#!/bin/bash
# run with $ bsub -q 8nh "sh submit_batch.sh <options>"
cd /afs/cern.ch/user/t/taylor/CMSSW_8_0_9/src/
eval `scramv1 runtime -sh`
cd /afs/cern.ch/user/t/taylor/l1t-macros/

# root -q -b -l makeJetResolutions.cxx
# root -q -b -l makeJetTurnons.cxx
# root -q -b -l makeJetXvsY.cxx
# root -q -b -l makeResolutions.cxx
# root -q -b -l makeTurnons.cxx
root -q -b -l makeXvsY.cxx