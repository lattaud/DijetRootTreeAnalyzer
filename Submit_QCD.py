#!/usr/bin/python
import argparse, os, tempfile, shutil, sys,math,pickle,itertools
from subprocess import call, PIPE, STDOUT, Popen
import argparse
import datetime

DirList = ["15_30","30_50","50_80","80_120","80_120_ext","120_170","120_170_ext","170_300","170_300_ext","300_470","300_470_ext","470_600","600_800","600_800_ext","800_100","800_1000_ext","1000_1400","1000_1400_ext","1400_1800","1400_1800_ext","1800_2400","1800_2400_ext","2400_3200","2400_3200_ext","3200_Inf"]
numList = ["40","10","10","8","8","7","6","7","8","5","19","4","4","10","4","16","4","7","1","3","1","2","1","1","1"]
it = 0

for iDir in DirList:
	
	cmd = "condor_submit config_File=config/cutFile_Gjet_HF_JEC_BCD.txt output_name=QCD_analysis_noDphi_"+iDir+"_nominal name_list=x dir_list=Analysis_all_bdt/QCD/"+iDir+"/ Njob="+str(numList[it])+" Submit_to_HTcondor.sub"
	print(cmd)
	os.system(cmd)
	#cmd = "condor_submit config_File=config/cutFile_Gjet_HF_JEC_BCD_up.txt output_name=QCD_analysis_noDphi_"+iDir+"_jecup name_list=x dir_list=Analysis_all_bdt/QCD/"+iDir+"/ Njob="+str(numList[it])+" Submit_to_HTcondor.sub"
	#print(cmd)
	#os.system(cmd)
	#cmd = "condor_submit config_File=config/cutFile_Gjet_HF_JEC_BCD_down.txt output_name=QCD_analysis_noDphi_"+iDir+"_jecdown name_list=x dir_list=Analysis_all_bdt/QCD/"+iDir+"/ Njob="+str(numList[it])+" Submit_to_HTcondor.sub"
	#print(cmd)
	#os.system(cmd)
	it += 1
