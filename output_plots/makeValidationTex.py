import os

tex = "\\documentclass{beamer}\n"
tex += "\\begin{document}\n\n"

runList = [
"run277166",
"run277168",
"run277180",
"run277194",
"run277202",
"run277217",
"run277218",
"run277219",
"run277220",
"run277305",
"run277420",
"run277933",
]

for run in runList:

    metPath = os.path.join("Turnons",run,"effs_SingleMu_caloMetBE_l1MetSeeds.pdf")
    httPath = os.path.join("Turnons",run,"effs_SingleMu_recoHtt_l1HttSeeds.pdf")
    jetBEPath = os.path.join("TurnonsJets",run,"effs_SingleMu_recoJetEt_l1JetEtSeeds_barrel-endcap.pdf")
    jetHFPath = os.path.join("TurnonsJets",run,"effs_SingleMu_recoJetEt_l1JetEtSeeds_hf.pdf")

    tex += "\\begin{frame}{"+ run +" - Jets}\n"
    tex += "\\normalsize\n Barrel+Endcap (left) and HF (right)\n"
    tex += "\\begin{figure}[!htbp]\n"
    tex += "\\centering\n"
    tex += "\\footnotesize\n \\textbf{CMS Preliminary} (13 TeV) \\hspace{0.15\\textwidth} \\textbf{CMS Preliminary} (13 TeV)\\hspace{0.35\\textwidth}\\\\"
    tex += "\\includegraphics[trim={0 0 0 1.3cm},clip,width=0.49\\textwidth]{"+jetBEPath+"}\n"
    tex += "\\includegraphics[trim={0 0 0 1.3cm},clip,width=0.49\\textwidth]{"+jetHFPath+"}\n"
    tex += "\\end{figure}\n"
    tex += "\\end{frame}\n\n"
    
    tex += "\\begin{frame}{Run "+str(run)+" - Sums}\n"
    tex += "\\normalsize\n MET (left) and HTT (right)\n"
    tex += "\\begin{figure}[!htbp]\n"
    tex += "\\centering\n"
    tex += "\\footnotesize\n \\textbf{CMS Preliminary} (13 TeV) \\hspace{0.15\\textwidth} \\textbf{CMS Preliminary} (13 TeV)\\hspace{0.35\\textwidth}\\\\"
    tex += "\\includegraphics[trim={0 0 0 1.3cm},clip,width=0.49\\textwidth]{"+metPath+"}\n"
    tex += "\\includegraphics[trim={0 0 0 1.3cm},clip,width=0.49\\textwidth]{"+httPath+"}\n"
    tex += "\\end{figure}\n"
    tex += "\\end{frame}\n\n"

tex += "\\end{document}"

print tex
