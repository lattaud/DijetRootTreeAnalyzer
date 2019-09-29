#!/usr/bin/env python

"""Adds per-bunch crossing luminosity to data tuples.

The luminosity is written per lumi section per bunch crossing.  It is
read from a dedicated ROOT file.  Output is put in an independent ROOT
file, which can be added as a friend to the original tuple.

In order to limit the memory footprint, luminosity information is read
for one run at a time.  This approach relies on the input data being
grouped by run numbers and will lead to a huge degradation of
performance otherwise.
"""

import argparse
from array import array
from functools import total_ordering
import math
import os
import sys

import numpy as np

import ROOT



@total_ordering
class LumiID:
    """Lumi block and a BX number in a run."""
    
    def __init__(self, run, ls, bx):
        self.run = run
        self.ls = ls
        self.bx = bx
    
    
    def __eq__(self, other):
        return self.run == other.run and self.ls == other.ls and self.bx == other.bx
    
    
    def __hash__(self):
        return hash((self.run, self.ls, self.bx))
    
    
    def __lt__(self, other):
        if self.run != other.run:
            return self.run < other.run
        elif self.ls != other.ls:
            return self.ls < other.ls
        else:
            return self.bx < other.bx
    
    
    def __str__(self):
        return '{}:{}/{}'.format(self.run, self.ls, self.bx)



class LumiDB:
    """Provides access to luminosity.
    
    At every moment only keeps in memory information for a single run,
    which is needed to limit the momery footprint.  Because of this,
    requesting luminosities for events that are not grouped by run
    numbers is extremely inefficient.
    """
    
    # Number of buckets, which gives the maximal bunch crossing number
    nBuckets = 3564
    
    
    def __init__(self, inputFileName):
        
        # File with luminosities
        self.inputFile = ROOT.TFile(inputFileName)
        
        # Information for the current run.  The array of lumi section
        # numbers is supposed to be sorted.  If no information for the
        # current run has been loaded, this array will be empty.
        # Delivered luminosities are stored in a 2D array whose indices
        # are the index of the lumi section in the corresponding 1D
        # array and the bunch crossing number minus one.
        self.curRun = None
        self.lumiSections = np.array([], dtype=np.uint16)
        self.luminosity = np.array([], dtype=np.float32)
    
    
    def _load_info(self, run):
        """Load lumi info for the given run."""
        
        # Find tree for the given run
        tree = self.inputFile.Get(str(run))
        
        if not tree:
            print('\rNo luminosity tree for run {} found.'.format(run))
            self.luminosity.resize(0)
        else:
            
            # There is one entry per lumi section in the tree
            nLumiSections = tree.GetEntries()
            self.lumiSections.resize(nLumiSections)
            self.luminosity.resize(nLumiSections, LumiDB.nBuckets)
            
            bfLumiSection = np.empty(1, dtype=np.uint32)
            bfLuminosity = np.empty(LumiDB.nBuckets, dtype=np.float32)
            
            tree.SetBranchAddress('LumiSection', bfLumiSection)
            tree.SetBranchAddress('Luminosity', bfLuminosity)
            
            for iLumiSection in range(nLumiSections):
                tree.GetEntry(iLumiSection)
                self.lumiSections[iLumiSection] = bfLumiSection[0]
                self.luminosity[iLumiSection, :] = bfLuminosity
            
            
            # Make sure that the array of lumi section is ordered.  A
            # workaround would not be difficult to implement, but it is
            # expected to be ordered anyway.
            if not all(
                self.lumiSections[i] < self.lumiSections[i + 1]
                for i in range(self.lumiSections.size - 1)
            ):
                raise RuntimeError('Tree for run {} is not ordered in lumi sections.'.format(run))
        
        
        # print('\033[37mLumi info for run {} has been loaded.\033[0m'.format(run))
        self.curRun = run
    
    
    def get_lumi(self, lumiID):
        """Return luminosity for the given lumi ID.
        
        The returned value is the delivered luminosity (in 1/ub) for the
        given run, lumi section, and bunch crossing.  It is summed up
        over all orbits in a lumi section.  In order to get the average
        luminosity per event in the given bunch crossing, the values
        needs to be divided by the number of orbits (2^18).
        """
        
        if lumiID.run != self.curRun:
            self._load_info(lumiID.run)
        
        
        if self.lumiSections.size == 0:
            print('\rFailed to find lumi information for {}. Set lumi to zero.'.format(lumiID))
            lumi = 0.
        else:
            
            # Find index of the given lumi section
            lsIndex = np.searchsorted(self.lumiSections, lumiID.ls)
            
            if lsIndex == self.lumiSections.size or self.lumiSections[lsIndex] != lumiID.ls:
                print('\rFailed to find lumi information for {}. Set lumi to zero.'.format(lumiID))
                lumi = 0.
            else:
                lumi = self.luminosity[lsIndex, lumiID.bx - 1]
        
        return lumi



if __name__ == '__main__':
    
    # Parse arguments
    argParser = argparse.ArgumentParser(
        epilog=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter
    )
    argParser.add_argument(
        'inputFile', metavar='inputFile',
        help='Input data file'
    )
    argParser.add_argument(
        '-l', '--lumi', metavar='lumi-per-bx.root', default='lumi-per-bx.root',
        help='ROOT file with per-BX luminosity information'
    )
    argParser.add_argument(
        '--input-tree', metavar='eventIDTree', dest='inputTree', default='EventID',
        help='Name of the source tree with event IDs'
    )
    argParser.add_argument(
        '-o', '--output', metavar='outputFile', default=None,
        help='Name for the output file'
    )
    argParser.add_argument(
        '--lumi-tree', metavar='lumiTree', dest='lumiTree', default='Lumi',
        help='Name for the tree with luminosity information'
    )
    argParser.add_argument(
        '--progress', action='store_true',
        help='Print progress'
    )
    args = argParser.parse_args()
    
    if args.output is None:
        args.output = '{}_{}.root'.format(
            os.path.splitext(args.inputFile)[0], args.lumiTree
        )
    
    
    # An object to access luminosity information
    lumiDB = LumiDB(args.lumi)
    
    
    # Open the input file
    inputFile = ROOT.TFile(args.inputFile)
    inputTree = inputFile.Get(args.inputTree)
    
    bfRun = array('l', [0])
    bfLumiSection = array('L', [0])
    bfBunchCrossing = array('L', [0])
    
    inputTree.SetBranchAddress('Run', bfRun)
    inputTree.SetBranchAddress('LumiBlock', bfLumiSection)
    inputTree.SetBranchAddress('BunchCrossing', bfBunchCrossing)
    
    inputTree.SetBranchStatus('Event', False)
    
    
    # Create output file
    outputFile = ROOT.TFile(args.output, 'recreate')
    outputTree = ROOT.TTree(args.lumiTree, 'Per-LS per-BX luminosity')
    
    bfLumi = array('f', [0])
    outputTree.Branch('Lumi', bfLumi, 'Lumi/F')
    
    
    # Fill the output tree.  Luminosities in the database are summed
    # over all orbits in a lumi section.  Divide them by the number of
    # orbits to get mean per-event delivered luminosity.
    lumiPerEventScale = 1. / 2**18
    
    nEvents = inputTree.GetEntries()
    nProcessed = 0
    nPerProgressUnit = math.ceil(nEvents / 100)
    
    for ev in range(nEvents):
        inputTree.GetEntry(ev)
        lumiID = LumiID(bfRun[0], bfLumiSection[0], bfBunchCrossing[0])
        
        bfLumi[0] = lumiDB.get_lumi(lumiID) * lumiPerEventScale
        outputTree.Fill()
        
        if args.progress:
            if nProcessed % nPerProgressUnit == 0:
                sys.stdout.write(
                    '\r\033[37mDone {:3d}%\033[0m'.format(round(nProcessed / nEvents * 100))
                )
                sys.stdout.flush()
            nProcessed += 1
    
    if args.progress:
        sys.stdout.write('\r\033[37mDone 100%\033[0m\n')
    
    
    # Write the output tree and close the files
    outputTree.Write('', ROOT.TObject.kOverwrite)
    outputFile.Close()
    inputFile.Close()
