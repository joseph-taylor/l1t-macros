#!/bin/bash
# run with $ bsub -q 8nh "sh submit_makeResolutions.sh <options in space seperated list>"
# $ bsub -q 8nh "sh submit_makeResolutions.sh"
# cd /afs/cern.ch/user/t/taylor/CMSSW_8_0_9/src/
cd /afs/cern.ch/user/t/taylor/CMSSW_8_0_21/src/
eval `scramv1 runtime -sh`
cd /afs/cern.ch/user/t/taylor/l1t-macros/

totalCommand="root -l -q -b 'makeResolutions.cxx($1,"\""$2"\"")'"
eval $totalCommand