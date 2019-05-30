import os

tex = "\\documentclass{beamer}\n"
tex += "\\begin{document}\n\n"

runs = [281613,281616,281638,281639,281641,281663,281674,281680,281686,281689,281691,281693,281707,281726,281727,281797,281975,281976,282033,282034,282035,282037,]

for run in runs:
    # path = "20160708_Data_run-{0}_SingleMu".format(run)
    # if not os.path.join(path): continue
    path = "/Users/jt15104/Trigger/plots/validation_13Oct2016_v2"

    metPath = os.path.join(path,"Turnons","effs_SingleMu_caloMetBE_l1MetSeeds.pdf")
    httPath = os.path.join(path,"Turnons","effs_SingleMu_recoHtt_l1HttSeeds.pdf")
    jetBEPath = os.path.join(path,"TurnonsJets","effs_SingleMu_recoJetEt_l1JetEtSeeds_barrel-endcap.pdf")
    jetHFPath = os.path.join(path,"TurnonsJets","effs_SingleMu_recoJetEt_l1JetEtSeeds_hf.pdf")

    tex += "\\begin{frame}{Run "+str(run)+" - Jets}\n"
    tex += "Barrel+Endcap (left) and HF (right)\n"
    tex += "\\begin{figure}[!htbp]\n"
    tex += "\\centering\n"
    tex += "\\includegraphics[width=0.49\\textwidth]{"+jetBEPath+"}\n"
    tex += "\\includegraphics[width=0.49\\textwidth]{"+jetHFPath+"}\n"
    tex += "\\end{figure}\n"
    tex += "\\end{frame}\n\n"
    
    tex += "\\begin{frame}{Run "+str(run)+" - Sums}\n"
    tex += "MET (left) and HTT (right)\n"
    tex += "\\begin{figure}[!htbp]\n"
    tex += "\\centering\n"
    tex += "\\includegraphics[width=0.49\\textwidth]{"+metPath+"}\n"
    tex += "\\includegraphics[width=0.49\\textwidth]{"+httPath+"}\n"
    tex += "\\end{figure}\n"
    tex += "\\end{frame}\n\n"

tex += "\\end{document}"

print tex