import os
from runList import listOfRunsForPython

# TORUN, do so from jobLogs directory
# $ python /afs/cern.ch/user/t/taylor/l1t-macros/python/submitParallelProcesses.py

# all outputs form these batch jobs will be beaneath this dir
# require many many quotes...

batchJobSaveLabel = '"parallelRunning_ICHEPv2"'
# numberOfFiles = 49
numberOfFiles = len(listOfRunsForPython)

# want to set this length as the actual length of the vector of run entries.
for i in range (0,numberOfFiles):
	# for testing
	# print('bsub -q 8nh "sh /afs/cern.ch/user/t/taylor/l1t-macros/shellSubmission/submit_makeJetResolutions.sh %d %s"' % (i, batchJobSaveLabel))
	# print('bsub -q 8nh "sh /afs/cern.ch/user/t/taylor/l1t-macros/shellSubmission/submit_makeJetTurnons.sh %d %s"' % (i, batchJobSaveLabel))
	# print('bsub -q 8nh "sh /afs/cern.ch/user/t/taylor/l1t-macros/shellSubmission/submit_makeJetXvsY.sh %d %s"' % (i, batchJobSaveLabel))
	# print('bsub -q 8nh "sh /afs/cern.ch/user/t/taylor/l1t-macros/shellSubmission/submit_makeResolutions.sh %d %s"' % (i, batchJobSaveLabel))
	# print('bsub -q 8nh "sh /afs/cern.ch/user/t/taylor/l1t-macros/shellSubmission/submit_makeTurnons.sh %d %s"' % (i, batchJobSaveLabel))
	# print('bsub -q 8nh "sh /afs/cern.ch/user/t/taylor/l1t-macros/shellSubmission/submit_makeXvsY.sh %d %s"' % (i, batchJobSaveLabel))		
	
	# for the real thing
	os.system('bsub -q 8nh "sh /afs/cern.ch/user/t/taylor/l1t-macros/shellSubmission/submit_makeJetResolutions.sh %d %s"' % (i, batchJobSaveLabel))
	os.system('bsub -q 8nh "sh /afs/cern.ch/user/t/taylor/l1t-macros/shellSubmission/submit_makeJetTurnons.sh %d %s"' % (i, batchJobSaveLabel))
	os.system('bsub -q 8nh "sh /afs/cern.ch/user/t/taylor/l1t-macros/shellSubmission/submit_makeJetXvsY.sh %d %s"' % (i, batchJobSaveLabel))
	os.system('bsub -q 8nh "sh /afs/cern.ch/user/t/taylor/l1t-macros/shellSubmission/submit_makeResolutions.sh %d %s"' % (i, batchJobSaveLabel))
	os.system('bsub -q 8nh "sh /afs/cern.ch/user/t/taylor/l1t-macros/shellSubmission/submit_makeTurnons.sh %d %s"' % (i, batchJobSaveLabel))
	os.system('bsub -q 8nh "sh /afs/cern.ch/user/t/taylor/l1t-macros/shellSubmission/submit_makeXvsY.sh %d %s"' % (i, batchJobSaveLabel))