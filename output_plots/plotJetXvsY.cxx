#include <string>
#include <vector>
#include <algorithm>

#include "../Plotting/tdrstyle.C"
#include "../Event/TL1EventClass.h"
#include "../Utilities/TL1Progress.C"
#include "../Utilities/TL1DateTime.C"
#include "../Plotting/TL1XvsY.h"

vector<double> bins(double max);
vector<double> phiBins();
vector<double> etaBins();
double FoldPhi(double phi);
void SetMyStyle(int palette, double rmarg, TStyle * myStyle);

void plotJetXvsY()
{
    TStyle * myStyle(new TStyle(TDRStyle()));
    SetMyStyle(57, 0.14, myStyle);

    std::string run = "6.3fb^{-1}";
    std::string jobSaveLabel = "parallelRunning_ICHEPv2/";
    std::string outDirBase = "/afs/cern.ch/user/t/taylor/l1t-macros/output_plots/";
    std::string outDir = outDirBase + jobSaveLabel + "combinedRuns/xyJets/";
    std::vector<std::string> puType = {"0PU13","14PU21","22PU"};
    std::vector<int> puBins = {0,14,22,999};
    std::string sample = "Data";
    std::string triggerName = "SingleMu";
    std::string triggerTitle = "Single Muon";
    std::vector<TL1XvsY*> xvsy;

    // Jet Et - barrel
    // xvsy.emplace_back(new TL1XvsY());
    // xvsy[0]->SetXBins(bins(300.0));
    // xvsy[0]->SetX("jetEt","Offline Jet E_{T} (GeV)");
    // xvsy[0]->SetYBins(bins(300.0));
    // xvsy[0]->SetY("l1JetEt","L1 Jet E_{T} (GeV)");
    // xvsy[0]->SetOutName(triggerName+"_jetEt_vs_l1JetEt_barrel");
    // xvsy[0]->SetAddMark("|#eta| < 1.479");

    // Jet Et - end-cap
    // xvsy.emplace_back(new TL1XvsY());
    // xvsy[1]->SetXBins(bins(300.0));
    // xvsy[1]->SetX("jetEt","Offline Jet E_{T} (GeV)");
    // xvsy[1]->SetYBins(bins(300.0));
    // xvsy[1]->SetY("l1JetEt","L1 Jet E_{T} (GeV)");
    // xvsy[1]->SetOutName(triggerName+"_jetEt_vs_l1JetEt_endcap");
    // xvsy[1]->SetAddMark("1.479 < |#eta| < 3.0");
    
    // Jet Et - barrel end-cap
    xvsy.emplace_back(new TL1XvsY());
    xvsy[0]->SetXBins(bins(300.0));
    xvsy[0]->SetX("jetEt","Offline Jet E_{T} (GeV)");
    xvsy[0]->SetYBins(bins(300.0));
    xvsy[0]->SetY("l1JetEt","L1 Jet E_{T} (GeV)");
    xvsy[0]->SetOutName(triggerName+"_jetEt_vs_l1JetEt_barrel-endcap");
    xvsy[0]->SetAddMark("|#eta| < 3.0");
    std::string t0rootFilePath = outDir + "xy_SingleMu_jetEt_vs_l1JetEt_barrel-endcap.root";
    xvsy[0]->SetOverwriteNames(t0rootFilePath.c_str(),"xy_jetEt_vs_l1JetEt");

    // Jet Et - HF
    xvsy.emplace_back(new TL1XvsY());
    xvsy[1]->SetXBins(bins(300.0));
    xvsy[1]->SetX("jetEt","Offline Jet E_{T} (GeV)");
    xvsy[1]->SetYBins(bins(300.0));
    xvsy[1]->SetY("l1JetEt","L1 Jet E_{T} (GeV)");
    xvsy[1]->SetOutName(triggerName+"_jetEt_vs_l1JetEt_hf");
    xvsy[1]->SetAddMark("|#eta| > 3.0");
    std::string t1rootFilePath = outDir + "xy_SingleMu_jetEt_vs_l1JetEt_hf.root";
    xvsy[1]->SetOverwriteNames(t1rootFilePath.c_str(),"xy_jetEt_vs_l1JetEt");

    // Jet phi - barrel
    // xvsy.emplace_back(new TL1XvsY());
    // xvsy[4]->SetXBins(phiBins());
    // xvsy[4]->SetX("jetPhi","Offline Jet Phi");
    // xvsy[4]->SetYBins(phiBins());
    // xvsy[4]->SetY("l1JetPhi","L1 Jet Phi");
    // xvsy[4]->SetOutName(triggerName+"_jetPhi_vs_l1JetPhi_barrel");
    // xvsy[4]->SetAddMark("|#eta| < 1.479");

    // Jet Phi - endcap
    // xvsy.emplace_back(new TL1XvsY());
    // xvsy[5]->SetXBins(phiBins());
    // xvsy[5]->SetX("jetPhi","Offline Jet Phi");
    // xvsy[5]->SetYBins(phiBins());
    // xvsy[5]->SetY("l1JetPhi","L1 Jet Phi");
    // xvsy[5]->SetOutName(triggerName+"_jetPhi_vs_l1JetPhi_endcap");
    // xvsy[5]->SetAddMark("1.479 < |#eta| < 3.0");

    // Jet Phi - barrel endcap
    xvsy.emplace_back(new TL1XvsY());
    xvsy[2]->SetXBins(phiBins());
    xvsy[2]->SetX("jetPhi","Offline Jet Phi");
    xvsy[2]->SetYBins(phiBins());
    xvsy[2]->SetY("l1JetPhi","L1 Jet Phi");
    xvsy[2]->SetOutName(triggerName+"_jetPhi_vs_l1JetPhi_barrel-endcap");
    xvsy[2]->SetAddMark("|#eta| < 3.0");
    std::string t2rootFilePath = outDir + "xy_SingleMu_jetPhi_vs_l1JetPhi_barrel-endcap.root";
    xvsy[2]->SetOverwriteNames(t2rootFilePath.c_str(),"xy_jetPhi_vs_l1JetPhi");

    // Jet Phi - HF
    xvsy.emplace_back(new TL1XvsY());
    xvsy[3]->SetXBins(phiBins());
    xvsy[3]->SetX("jetPhi","Offline Jet Phi");
    xvsy[3]->SetYBins(phiBins());
    xvsy[3]->SetY("l1JetPhi","L1 Jet Phi");
    xvsy[3]->SetOutName(triggerName+"_jetPhi_vs_l1JetPhi_hf");
    xvsy[3]->SetAddMark("|#eta| > 3.0");
    std::string t3rootFilePath = outDir + "xy_SingleMu_jetPhi_vs_l1JetPhi_hf.root";
    xvsy[3]->SetOverwriteNames(t3rootFilePath.c_str(),"xy_jetPhi_vs_l1JetPhi");

    // Jet Eta
    xvsy.emplace_back(new TL1XvsY());
    xvsy[4]->SetXBins(etaBins());
    xvsy[4]->SetX("jetEta","Offline Jet Eta");
    xvsy[4]->SetYBins(etaBins());
    xvsy[4]->SetY("l1JetEta","L1 Jet Eta");
    xvsy[4]->SetOutName(triggerName+"_jetEta_vs_l1JetEta_hf");
    std::string t4rootFilePath = outDir + "xy_SingleMu_jetEta_vs_l1JetEta.root";
    xvsy[4]->SetOverwriteNames(t4rootFilePath.c_str(),"xy_jetEta_vs_l1JetEta");

    for(auto it=xvsy.begin(); it!=xvsy.end(); ++it)
    {
        (*it)->SetSample(sample,"");
        (*it)->SetTrigger(triggerName,triggerTitle);
        (*it)->SetRun(run);
        (*it)->SetOutDir(outDir);
        (*it)->SetPuType(puType);
        (*it)->SetPuBins(puBins);
        (*it)->OverwritePlots();
    }

    for(auto it=xvsy.begin(); it!=xvsy.end(); ++it)
        (*it)->DrawPlots();
}

vector<double> bins(double max)
{
    vector<double> temp;
    for(double binLowerEdge=0.0; binLowerEdge<=max; binLowerEdge+= 1.0) temp.push_back(binLowerEdge);
    return temp;
}

vector<double> phiBins()
{
    vector<double> temp;
    for(double binLowerEdge=0.0; binLowerEdge<=TMath::Pi(); binLowerEdge+= (TMath::Pi())/36.) temp.push_back(binLowerEdge);
    return temp;
}

vector<double> etaBins()
{
    vector<double> temp;
    for(double binLowerEdge=-5.0; binLowerEdge<=5.0; binLowerEdge+= 0.1) temp.push_back(binLowerEdge);
    return temp;
}

double FoldPhi(double phi)
{
    return min( (float)abs(phi), (float)abs(2*TMath::Pi()-phi) );
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
