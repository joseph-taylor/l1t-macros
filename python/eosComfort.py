import os

#######################################
#######################################
# run with $ python /afs/cern.ch/user/t/taylor/l1t-macros/python/eosComfort.py

# creates a list of the the dir-paths underneath a mother directory on eos
# for each element in this list it creates another list with the ntuples in the corresponding dir

# assumes latest time stamp is the correct one (hence the use of 'tail -1')
# currently only for 0000 subDirectoy

# the directory which holds the divergent paths
motherDir = "/eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/"

#######################################
#######################################

# the divergent dirs within the mother
daughterDirs = os.popen("/afs/cern.ch/project/eos/installation/cms/bin/eos.select ls %s" % motherDir, "r").readlines()
dateStamps = []
fullPaths = []
ntupleNames = []  # list in a list


for i in range (0,len(daughterDirs)):
	daughterDirs[i] = daughterDirs[i].rstrip() + "/"
	
	dateStamps.append(os.popen("/afs/cern.ch/project/eos/installation/cms/bin/eos.select ls %s%s | tail -1" % (motherDir,daughterDirs[i]), "r").readline())
	dateStamps[i] = dateStamps[i].rstrip() + "/"

	fullPaths.append(motherDir + daughterDirs[i] + dateStamps[i] + "0000/")

	ntupleNames.append(os.popen("/afs/cern.ch/project/eos/installation/cms/bin/eos.select ls %s" % (fullPaths[i]), "r").readlines())
	# ntuplesNames[x][y]
	# x: the directory
	# y: files within directory
	for j in range (0,len(ntupleNames[i])):
		ntupleNames[i][j] = ntupleNames[i][j].rstrip()

	if "failed" in ntupleNames[i]:
		ntupleNames[i].remove("failed")
	if "log" in ntupleNames[i]:
		ntupleNames[i].remove("log")


# the list of dir-path
print fullPaths

# the list of ntuple files
# print ntupleNames
