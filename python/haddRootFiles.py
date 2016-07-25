import os
from runList import listOfRunsForPython

# $ python /afs/cern.ch/user/t/taylor/l1t-macros/python/haddRootFiles.py

# what about .root files which are ~null???
######################################################################
######################################################################
motherDirectory = "parallelRunning_ICHEPv2redoRESO/"
dirPath = "/afs/cern.ch/user/t/taylor/l1t-macros/output_plots/" + motherDirectory

resJets = ["res_SingleMu_jetEt_over_l1JetEt_barrel-endcap.root",
           "res_SingleMu_jetEta_over_l1JetEta.root",
           "res_SingleMu_jetPhi_over_l1JetPhi_barrel-endcap.root"]

Resolutions = ["res_SingleMu_caloMetBE_over_l1Met.root"]

Turnons = ["dists_SingleMu_caloMetBE_l1MetSeeds.root",
           "dists_SingleMu_recoHtt_l1HttSeeds.root"]

TurnonsJets = ["dists_SingleMu_recoJetEt_l1JetEtSeeds_barrel-endcap.root",
               "dists_SingleMu_recoJetEt_l1JetEtSeeds_hf.root"]

xy = ["xy_SingleMu_caloMetBE_vs_l1Met.root",
      "xy_SingleMu_caloMetBEPhi_vs_l1MetPhi.root"]

xyJets = ["xy_SingleMu_jetEt_vs_l1JetEt_barrel-endcap.root",
          "xy_SingleMu_jetEt_vs_l1JetEt_hf.root",
          "xy_SingleMu_jetEta_vs_l1JetEta_hf.root",
          "xy_SingleMu_jetPhi_vs_l1JetPhi_barrel-endcap.root",
          "xy_SingleMu_jetPhi_vs_l1JetPhi_hf.root"]
######################################################################
######################################################################

os.system("mkdir %scombinedRuns/" % dirPath)
os.system("mkdir %scombinedRuns/resJets/" % dirPath)
os.system("mkdir %scombinedRuns/Resolutions/" % dirPath)
os.system("mkdir %scombinedRuns/Turnons/" % dirPath)
os.system("mkdir %scombinedRuns/TurnonsJets/" % dirPath)
os.system("mkdir %scombinedRuns/xy/" % dirPath)
os.system("mkdir %scombinedRuns/xyJets/" % dirPath)

i = 0
for rootFile in resJets:

	commandString = "hadd -k " + dirPath + "combinedRuns/resJets/" + rootFile + " "
	for runNumber in listOfRunsForPython:
		commandString = commandString + dirPath + "resJets/run" + runNumber +  "/" + rootFile + " "

	# print commandString
	os.system("%s" % commandString)
	i = i + 1
	print ("Combined %d of %d file-sets in resJets" % (i, len(resJets)))
print("Done resJets:)\n\n")



i = 0
for rootFile in Resolutions:

	commandString = "hadd -k " + dirPath + "combinedRuns/Resolutions/" + rootFile + " "
	for runNumber in listOfRunsForPython:
		commandString = commandString + dirPath + "Resolutions/run" + runNumber +  "/" + rootFile + " "

	# print commandString
	os.system("%s" % commandString)
	i = i + 1
	print ("Combined %d of %d file-sets in Resolutions" % (i, len(Resolutions)))
print("Done Resolutions:)\n\n")



i = 0
for rootFile in Turnons:

	commandString = "hadd -k " + dirPath +"combinedRuns/Turnons/" + rootFile + " "
	for runNumber in listOfRunsForPython:
		commandString = commandString + dirPath + "Turnons/run" + runNumber +  "/" + rootFile + " "

	# print commandString
	os.system("%s" % commandString)
	i = i + 1
	print ("Combined %d of %d file-sets in Turnons" % (i, len(Turnons)))
print("Done Turnons:)\n\n")



i = 0
for rootFile in TurnonsJets:

	commandString = "hadd -k " + dirPath + "combinedRuns/TurnonsJets/" + rootFile + " "
	for runNumber in listOfRunsForPython:
		commandString = commandString + dirPath + "TurnonsJets/run" + runNumber +  "/" + rootFile + " "

	# print commandString
	os.system("%s" % commandString)
	i = i + 1
	print ("Combined %d of %d file-sets in TurnonsJets" % (i, len(TurnonsJets)))
print("Done TurnonsJets:)\n\n")



i = 0
for rootFile in xy:

	commandString = "hadd -k " + dirPath + "combinedRuns/xy/" + rootFile + " "
	for runNumber in listOfRunsForPython:
		commandString = commandString + dirPath + "xy/run" + runNumber +  "/" + rootFile + " "

	# print commandString
	os.system("%s" % commandString)
	i = i + 1
	print ("Combined %d of %d file-sets in xy" % (i, len(xy)))
print("Done xy:)\n\n")



i = 0
for rootFile in xyJets:

	commandString = "hadd -k " + dirPath + "combinedRuns/xyJets/" + rootFile + " "
	for runNumber in listOfRunsForPython:
		commandString = commandString + dirPath + "xyJets/run" + runNumber +  "/" + rootFile + " "

	# print commandString
	os.system("%s" % commandString)
	i = i + 1
	print ("Combined %d of %d file-sets in xyJets" % (i, len(xyJets)))
print("Done xyJets:)\n\n")

