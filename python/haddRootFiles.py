import os
from runList import listOfRunsForPython

######################################################################
######################################################################
motherDirectory = "parallelRunning_ICHEPv2/"

resJets = ["res_SingleMu_jetEt_over_l1JetEt_barrel-endcap.root",
           "res_SingleMu_jetEta_over_l1JetEta.root",
           "res_SingleMu_jetPhi_over_l1JetPhi_barrel-endcap.root"]

Resolutions = ["res_SingleMu_caloMetBE_over_l1Met.root"]

Turnons = ["dists_SingleMu_caloMetBE_l1MetSeeds.root",
           "dists_SingleMu_recoHtt_l1HttSeeds.root",
           "effs_SingleMu_caloMetBE_l1MetSeeds.root",
           "effs_SingleMu_recoHtt_l1HttSeeds.root"]

TurnonsJets = ["dists_SingleMu_recoJetEt_l1JetEtSeeds_barrel-endcap.root",
               "dists_SingleMu_recoJetEt_l1JetEtSeeds_hf.root",
               "effs_SingleMu_recoJetEt_l1JetEtSeeds_barrel-endcap.root",
               "effs_SingleMu_recoJetEt_l1JetEtSeeds_hf.root"]

xy = ["xy_SingleMu_caloMetBE_vs_l1Met.root",
      "xy_SingleMu_caloMetBEPhi_vs_l1MetPhi.root"]

xyJets = ["xy_SingleMu_jetEt_vs_l1JetEt_barrel-endcap.root",
          "xy_SingleMu_jetEt_vs_l1JetEt_hf.root",
          "xy_SingleMu_jetEta_vs_l1JetEta_hf.root",
          "xy_SingleMu_jetPhi_vs_l1JetPhi_barrel-endcap.root",
          "xy_SingleMu_jetPhi_vs_l1JetPhi_hf.root"]
######################################################################
######################################################################

os.system("cd /afs/cern.ch/user/t/taylor/l1t-macros/output_plots/%s" % motherDirectory)
os.system("mkdir combinedRuns/")
os.system("mkdir combinedRuns/resJets/")
os.system("mkdir combinedRuns/Resolutions/")
os.system("mkdir combinedRuns/Turnons/")
os.system("mkdir combinedRuns/TurnonJets/")
os.system("mkdir combinedRuns/xy/")
os.system("mkdir combinedRuns/xyJets/")

i = 0
for rootFile in resJets:

	commandString = "hadd combinedRuns/resJets/" + rootFile + " "
	for runNumber in listOfRunsForPython:
		commandString = commandString + "resJets/run" + runNumber +  "/" + rootFile + " "

	# print commandString
	os.system("%s" % commandString)
	i = i + 1
	print ("combined %d of %d file-sets in resJets" % (i, len(resJets)))
print("done resJets:)")



i = 0
for rootFile in Resolutions:

	commandString = "hadd combinedRuns/Resolutions/" + rootFile + " "
	for runNumber in listOfRunsForPython:
		commandString = commandString + "Resolutions/run" + runNumber +  "/" + rootFile + " "

	# print commandString
	os.system("%s" % commandString)
	i = i + 1
	print ("combined %d of %d file-sets in Resolutions" % (i, len(Resolutions)))
print("done Resolutions:)")



i = 0
for rootFile in Turnons:

	commandString = "hadd combinedRuns/Turnons/" + rootFile + " "
	for runNumber in listOfRunsForPython:
		commandString = commandString + "Turnons/run" + runNumber +  "/" + rootFile + " "

	# print commandString
	os.system("%s" % commandString)
	i = i + 1
	print ("combined %d of %d file-sets in Turnons" % (i, len(Turnons)))
print("done Turnons:)")



i = 0
for rootFile in TurnonsJets:

	commandString = "hadd combinedRuns/TurnonsJets/" + rootFile + " "
	for runNumber in listOfRunsForPython:
		commandString = commandString + "TurnonsJets/run" + runNumber +  "/" + rootFile + " "

	# print commandString
	os.system("%s" % commandString)
	i = i + 1
	print ("combined %d of %d file-sets in TurnonsJets" % (i, len(TurnonsJets)))
print("done TurnonsJets:)")



i = 0
for rootFile in xy:

	commandString = "hadd combinedRuns/xy/" + rootFile + " "
	for runNumber in listOfRunsForPython:
		commandString = commandString + "xy/run" + runNumber +  "/" + rootFile + " "

	# print commandString
	os.system("%s" % commandString)
	i = i + 1
	print ("combined %d of %d file-sets in xy" % (i, len(xy)))
print("done xy:)")



i = 0
for rootFile in xyJets:

	commandString = "hadd combinedRuns/xyJets/" + rootFile + " "
	for runNumber in listOfRunsForPython:
		commandString = commandString + "xyJets/run" + runNumber +  "/" + rootFile + " "

	# print commandString
	os.system("%s" % commandString)
	i = i + 1
	print ("combined %d of %d file-sets in xyJets" % (i, len(xyJets)))
print("done xyJets:)")

