#include <string>
#include <vector>

#include "../Plotting/tdrstyle.C"
#include "../Event/TL1EventClass.h"
#include "../Utilities/TL1Progress.C"
#include "../Utilities/TL1DateTime.C"
#include "../Plotting/TL1Resolution.h"

// run locally with:
// $ root -q -b -l 'makeJetResolutions.cxx(*)'
// where * is an integer refering to set labelling (starts at zero)

std::vector<double> bins(std::string plotType);
void SetMyStyle(int palette, double rmarg, TStyle * myStyle);
double FoldPhi(double phi);

void plotJetResolutions()
{
    TStyle * myStyle(new TStyle(TDRStyle()));
    SetMyStyle(55, 0.07, myStyle);

    std::string run = "6.3fb^{-1}";
    std::string jobSaveLabel = "parallelRunning_ICHEPv2redoRESO/";
    std::string outDirBase = "/afs/cern.ch/user/t/taylor/l1t-macros/output_plots/";
    std::string outDir = outDirBase + jobSaveLabel + "combinedRuns/resJets/";
    std::vector<std::string> puType = {"0PU13","14PU21","22PU"};
    std::vector<int> puBins = {0,14,22,999};
    std::string sample = "Data";
    std::string triggerName = "SingleMu";
    std::string triggerTitle = "Single Muon";
    std::vector<TL1Resolution*> resolution;

    // Jet Et - barrel
    // resolution.emplace_back(new TL1Resolution());
    // resolution[0]->SetBins(bins());
    // resolution[0]->SetX("jetEt","Offline Jet E_{T}");
    // resolution[0]->SetY("l1JetEt","L1 Jet E_{T})");
    // resolution[0]->SetOutName(triggerName+"_jetEt_over_l1JetEt_barrel");
    // resolution[0]->SetAddMark("#splitline{Offline Jet E_{T} > 30 GeV}{|#eta| < 1.479}");

    // Jet Et - end-cap
    // resolution.emplace_back(new TL1Resolution());
    // resolution[1]->SetBins(bins());
    // resolution[1]->SetX("jetEt","Offline Jet E_{T}");
    // resolution[1]->SetY("l1JetEt","L1 Jet E_{T}");
    // resolution[1]->SetOutName(triggerName+"_jetEt_over_l1JetEt_endcap");
    // resolution[1]->SetAddMark("#splitline{Offline Jet E_{T} > 30 GeV}{1.479 < |#eta| < 3.0}");

    // Jet Et - barrel + end-cap
    resolution.emplace_back(new TL1Resolution());
    resolution[0]->SetPlotType("Energy");
    resolution[0]->SetBins(bins("Energy"));
    resolution[0]->SetX("jetEt","Offline Jet E_{T}");
    resolution[0]->SetY("l1JetEt","L1 Jet E_{T}");
    resolution[0]->SetOutName(triggerName+"_jetEt_over_l1JetEt_barrel-endcap");
    resolution[0]->SetAddMark("#splitline{E_{T}^{offline} > 30 GeV}{|#eta_{jet}^{offline}| < 3.0}");
    std::string t0rootFilePath = outDir + "res_SingleMu_jetEt_over_l1JetEt_barrel-endcap.root";
    resolution[0]->SetOverwriteNames(t0rootFilePath.c_str(),"res_Energy_jetEt_l1JetEt");

    // Jet Et - HF
    // resolution.emplace_back(new TL1Resolution());
    // resolution[1]->SetPlotType("Energy");
    // resolution[1]->SetBins(bins("Energy"));
    // resolution[1]->SetX("jetEt","Offline Jet E_{T}");
    // resolution[1]->SetY("l1JetEt","L1 Jet E_{T}");
    // resolution[1]->SetOutName(triggerName+"_jetEt_over_l1JetEt_hf");
    // resolution[1]->SetAddMark("#splitline{E_{T}^{offline} > 30 GeV}{|#eta_{jet}^{offline}| > 3.0}");

    // Jet phi - barrel
    // resolution.emplace_back(new TL1Resolution());
    // resolution[4]->SetBins(bins());
    // resolution[4]->SetX("jetPhi","#phi_{jet}^{offline}");
    // resolution[4]->SetY("l1JetPhi","#phi_{jet}^{L1}");
    // resolution[4]->SetOutName(triggerName+"_jetPhi_over_l1JetPhi_barrel");
    // resolution[4]->SetAddMark("#splitline{E_{T}^{offline} > 30 GeV}{|#eta| < 1.479}");

    // // Jet Phi - endcap
    // resolution.emplace_back(new TL1Resolution());
    // resolution[5]->SetBins(bins());
    // resolution[5]->SetX("jetPhi","Offline Jet Phi");
    // resolution[5]->SetY("l1JetPhi","L1 Jet Phi");
    // resolution[5]->SetOutName(triggerName+"_jetPhi_over_l1JetPhi_endcap");
    // resolution[5]->SetAddMark("#splitline{Offline Jet E_{T} > 30 GeV}{1.479 < |#eta| < 3.0}");

    // Jet Phi - barrel + endcap
    resolution.emplace_back(new TL1Resolution());
    resolution[1]->SetPlotType("Position");
    resolution[1]->SetBins(bins("Position"));
    resolution[1]->SetX("jetPhi","#phi_{jet}^{offline}");
    resolution[1]->SetY("l1JetPhi","#phi_{jet}^{L1}");
    resolution[1]->SetOutName(triggerName+"_jetPhi_over_l1JetPhi_barrel-endcap");
    resolution[1]->SetAddMark("#splitline{E_{T}^{offline} > 30 GeV}{|#eta_{jet}^{offline}| < 3.0}");
    std::string t1rootFilePath = outDir + "res_SingleMu_jetPhi_over_l1JetPhi_barrel-endcap.root";
    resolution[1]->SetOverwriteNames(t1rootFilePath.c_str(),"res_Position_jetPhi_l1JetPhi");

    // Jet Phi - HF
    // resolution.emplace_back(new TL1Resolution());
    // resolution[3]->SetPlotType("Position");
    // resolution[3]->SetBins(bins("Position"));
    // resolution[3]->SetX("jetPhi","#phi_{jet}^{offline}");
    // resolution[3]->SetY("l1JetPhi","#phi_{jet}^{L1}");
    // resolution[3]->SetOutName(triggerName+"_jetPhi_over_l1JetPhi_hf");
    // resolution[3]->SetAddMark("#splitline{E_{T}^{offline} > 30 GeV}{|#eta_{jet}^{offline}| > 3.0}");

    // Jet Eta
    resolution.emplace_back(new TL1Resolution());
    resolution[2]->SetPlotType("Position");
    resolution[2]->SetBins(bins("Position"));
    resolution[2]->SetX("jetEta","|#eta_{jet}^{offline}|");
    resolution[2]->SetY("l1JetEta","|#eta_{jet}^{L1}|");
    resolution[2]->SetOutName(triggerName+"_jetEta_over_l1JetEta");
    resolution[2]->SetAddMark("E_{T}^{offline} > 30 GeV");
    std::string t2rootFilePath = outDir + "res_SingleMu_jetEta_over_l1JetEta.root";
    resolution[2]->SetOverwriteNames(t2rootFilePath.c_str(),"res_Position_jetEta_l1JetEta");

    for(auto it=resolution.begin(); it!=resolution.end(); ++it)
    {
        (*it)->SetSample(sample,"");
        (*it)->SetTrigger(triggerName,triggerTitle);
        (*it)->SetRun(run);
        (*it)->SetOutDir(outDir);
        (*it)->SetPuType(puType);
        (*it)->SetPuBins(puBins);
        (*it)->OverwritePlots();
    }
    
    for(auto it=resolution.begin(); it!=resolution.end(); ++it)
        (*it)->DrawPlots();
}

std::vector<double> bins(std::string plotType)
{
    std::vector<double> temp;
    if( plotType == "Position" ) for(double binLowerEdge=-0.3; binLowerEdge<=0.3; binLowerEdge+= 0.005) temp.push_back(binLowerEdge);
    else if( plotType == "Energy" ) for(double binLowerEdge=-1.0; binLowerEdge<=1.5; binLowerEdge+= 0.05) temp.push_back(binLowerEdge);
    return temp;
}

void SetMyStyle(int palette, double rmarg, TStyle * myStyle)
{
    myStyle->SetCanvasDefW(800);
    myStyle->SetCanvasDefH(600);
    myStyle->SetNumberContours(255);
    myStyle->SetPalette(palette);
    myStyle->SetPadRightMargin(rmarg);
    myStyle->cd();
}

double FoldPhi(double phi)
{
    return TMath::Min( (float)abs(phi), (float)abs(2*TMath::Pi()-phi) );
}
