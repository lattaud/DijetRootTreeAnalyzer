#!/usr/bin/python
import argparse, os, tempfile, shutil, sys,math,pickle,itertools
from subprocess import call, PIPE, STDOUT, Popen
import argparse
import datetime

DirList = ["40_100","40_100_ext","100_200","100_200_ext","200_400","200_400_ext","400_600","400_600_ext","600_Inf","600_Inf_ext"]
numList = ["9","10","10","10","20","21","6","6","5","6"]
it = 0

for iDir in DirList:
	
	cmd = "condor_submit config_File=config/cutFile_Gjet_HF_JEC_up.txt output_name=madgraph_analysis_noDphi_"+iDir+"_jecup name_list=x dir_list=Analysis_all_bdt/Madgraph/"+iDir+"/ Njob="+str(numList[it])+" Submit_to_HTcondor.sub"
	print(cmd)
	os.system(cmd)
	cmd = "condor_submit config_File=config/cutFile_Gjet_HF_JEC_down.txt output_name=madgraph_analysis_noDphi_"+iDir+"_jecdown name_list=x dir_list=Analysis_all_bdt/Madgraph/"+iDir+"/ Njob="+str(numList[it])+" Submit_to_HTcondor.sub"
	print(cmd)
	os.system(cmd)
	it += 1
