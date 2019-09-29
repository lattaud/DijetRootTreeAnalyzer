#!/usr/bin/python
import argparse, os, tempfile, shutil, sys,math,pickle,itertools
from subprocess import call, PIPE, STDOUT, Popen
import argparse
import datetime

DirList = ["100_250"]#"50_100","50_100_ext","100_250","100_250_ext","250_400","250_400_ext","400_650","400_650_ext","650_inf","650_inf_ext"
numList = ["2"]#"10","86","16","76","2","1","1","2",
it = 0

for iDir in DirList:
	
	
	cmd = "condor_submit config_File=config/cutFile_Gjet_HF_JEC_BCD.txt output_name=amc_analysis_noDphi_"+iDir+"_nominal name_list=x dir_list=Analysis_all_bdt/AMC@NLO/"+iDir+"/ Njob="+str(numList[it])+" Submit_to_HTcondor.sub"
	print(cmd)
	os.system(cmd)
	
	cmd = "condor_submit config_File=config/cutFile_Gjet_HF_JEC_BCD_up.txt output_name=amc_analysis_noDphi_"+iDir+"_jecup name_list=x dir_list=Analysis_all_bdt/AMC@NLO/"+iDir+"/ Njob="+str(numList[it])+" Submit_to_HTcondor.sub"
	print(cmd)
	os.system(cmd)
	cmd = "condor_submit config_File=config/cutFile_Gjet_HF_JEC_BCD_down.txt output_name=amc_analysis_noDphi_"+iDir+"_jecdown name_list=x dir_list=Analysis_all_bdt/AMC@NLO/"+iDir+"/ Njob="+str(numList[it])+" Submit_to_HTcondor.sub"
	print(cmd)
	os.system(cmd)
	it += 1
