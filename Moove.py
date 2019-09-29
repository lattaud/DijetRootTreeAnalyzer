#!/usr/bin/python
import argparse, os, tempfile, shutil, sys,math,pickle,itertools
parent = os.path.dirname(os.getcwd())
sys.path.append(parent)
from subprocess import call, PIPE, STDOUT, Popen
import argparse
import datetime

Ilist = ["0","1","2","3","4","5","6","7","8","9"]

for i in Ilist:
	cmd = "mv x0"+i+" x"+i
	os.system(cmd) 
