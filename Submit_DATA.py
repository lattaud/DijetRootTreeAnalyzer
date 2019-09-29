#!/usr/bin/python
import argparse, os, tempfile, shutil, sys,math,pickle,itertools
from subprocess import call, PIPE, STDOUT, Popen
import argparse
import datetime

DirList = ["BCD","EF","FGH"]
numList = ["96","40","92"]
it = 0

for iDir in DirList:
	
	
	cmd = "condor_submit config_File=config/cutFile_Gjet_HF_JEC_"+iDir+".txt output_name=DATA_analysis_full_"+iDir+"_nominal name_list=x dir_list=DATA_analysis_All/"+iDir+"/ Njob="+str(numList[it])+" Submit_to_HTcondor.sub"
	print(cmd)
	os.system(cmd)
	cmd = "condor_submit config_File=config/cutFile_Gjet_HF_JEC_"+iDir+"_up.txt output_name=DATA_analysis_full_"+iDir+"_jecup name_list=x dir_list=DATA_analysis_All/"+iDir+"/ Njob="+str(numList[it])+" Submit_to_HTcondor.sub"
	print(cmd)
	os.system(cmd)
	cmd = "condor_submit config_File=config/cutFile_Gjet_HF_JEC_"+iDir+"_down.txt output_name=DATA_analysis_full_"+iDir+"_jecdown name_list=x dir_list=DATA_analysis_All/"+iDir+"/ Njob="+str(numList[it])+" Submit_to_HTcondor.sub"
	print(cmd)
	os.system(cmd)
	it += 1
