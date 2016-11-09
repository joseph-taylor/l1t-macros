// list of all the directories used for the full batch jobs

std::vector<std::string> vecOfDirs = {
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283820_SingleMuon/161028_163848/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283830_SingleMuon/161028_163921/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283834_SingleMuon/161028_163743/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283835_SingleMuon/161102_011002/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283865_SingleMuon/161028_163814/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283876_SingleMuon/161102_010850/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283877_SingleMuon/161028_163709/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283884_SingleMuon/161102_010816/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283885_SingleMuon/161102_011114/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283933_SingleMuon/161102_010401/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283934_SingleMuon/161102_010323/0000/",
"root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283946_SingleMuon/161102_011037/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__283964_SingleMuon/161102_010549/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284014_SingleMuon/161102_010438/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284025_SingleMuon/161102_010137/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284029_SingleMuon/161102_010625/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284035_SingleMuon/161102_010928/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284036_SingleMuon/161102_014510/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284037_SingleMuon/161102_014653/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284038_SingleMuon/161102_014758/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284039_SingleMuon/161103_174200/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284040_SingleMuon/161102_014833/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284041_SingleMuon/161103_174234/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284042_SingleMuon/161102_014622/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284043_SingleMuon/161102_014359/0000/",
// "root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v88p0/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v88p0__284044_SingleMuon/161102_014434/0000/",
};

// std::vector<std::string> vecOfDirs = {
// "/afs/cern.ch/work/t/taylor/public/L1TriggerNtuples/"
// };

// // list of all the run numbers used for the full batch jobs
// // this will be used for the subdir and on the plot title
std::vector<std::string> vecOfRuns = {
// "run283820",
// "run283830",
// "run283834",
// "run283835",
// "run283865",
// "run283876",
// "run283877",
// "run283884",
// "run283885",
// "run283933",
// "run283934",
"run283946",
// "run283964",
// "run284014",
// "run284025",
// "run284029",
// "run284035",
// "run284036",
// "run284037",
// "run284038",
// "run284039",
// "run284040",
// "run284041",
// "run284042",
// "run284043",
// "run284044",
};

// std::vector<std::string> vecOfRuns = {
// "ZMM"
// };


// eg
// std::vector<std::string> vecOfRuns = {
// "run277166",
// "run277168",
// "run277180",
// "run277194",
// "run277202",
// "run277217",
// "run277218",
// "run277219",
// "run277220",
// "run277305",
// "run277420",
// "run277933",
// };



















