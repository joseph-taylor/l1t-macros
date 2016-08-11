import os

# TO RUN (on lxplus)
# $ python <pathToThisFile>/dateStampInfo.py

# annoyingly python and eos don't always talk...

eosLocationBase = "/eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/"

# $ eos ls eosLocationBase
# to get the following list

directories = [
"crab_Collision2016-wRECO-l1t-integration-v71p1__277166_SingleMuon/",
"crab_Collision2016-wRECO-l1t-integration-v71p1__277168_SingleMuon/",
"crab_Collision2016-wRECO-l1t-integration-v71p1__277180_SingleMuon/",
"crab_Collision2016-wRECO-l1t-integration-v71p1__277194_SingleMuon/",
"crab_Collision2016-wRECO-l1t-integration-v71p1__277202_SingleMuon/",
"crab_Collision2016-wRECO-l1t-integration-v71p1__277217_SingleMuon/",
"crab_Collision2016-wRECO-l1t-integration-v71p1__277218_SingleMuon/",
"crab_Collision2016-wRECO-l1t-integration-v71p1__277219_SingleMuon/",
"crab_Collision2016-wRECO-l1t-integration-v71p1__277220_SingleMuon/",
"crab_Collision2016-wRECO-l1t-integration-v71p1__277305_SingleMuon/",
"crab_Collision2016-wRECO-l1t-integration-v71p1__277420_SingleMuon/",
"crab_Collision2016-wRECO-l1t-integration-v71p1__277933_SingleMuon/",
]

# run w/o datestamps line to get the required
# datestamps list...can then put in to check 0000's

dateStamps = [
"160802_161700",
"160802_161720",
"160804_040303",
"160802_161300",
"160804_040626",
"160804_040534",
"160804_040441",
"160802_234244",
"160804_040344",
"160802_161500",
"160802_161638",
"160803_133018",
]

# script running
# (assumes if there are two timeStamps that the most recent one, ie later stamp, is correct)
os.system("source /afs/cern.ch/project/eos/installation/cms/etc/setup.sh")
i=0
for directory in directories:
	# to get date stamp
	# os.system("/afs/cern.ch/project/eos/installation/cms/bin/eos.select ls %s%s | tail -1" % (eosLocationBase,directory))

    # to check date stamp
    os.system("/afs/cern.ch/project/eos/installation/cms/bin/eos.select ls %s%s%s" % (eosLocationBase,directory,dateStamps[i]))
    i = i + 1
