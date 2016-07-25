#include <string>
#include <vector>
#include <algorithm>

#include "../Plotting/tdrstyle.C"
#include "../Event/TL1EventClass.h"
#include "../Utilities/TL1Progress.C"
#include "../Utilities/TL1DateTime.C"
#include "../Plotting/TL1XvsY.h"

std::vector<double> bins(double max, double width, double min);
std::vector<double> phiBins();
void SetMyStyle(int palette, double rmarg, TStyle * myStyle);
double FoldPhi(double phi);

void plotXvsY()
{
    TStyle * myStyle(new TStyle(TDRStyle()));
    SetMyStyle(57, 0.14, myStyle);

    std::string run = "6.3fb^{-1}";
    std::string jobSaveLabel = "parallelRunning_ICHEPv2/";
    std::string outDirBase = "/afs/cern.ch/user/t/taylor/l1t-macros/output_plots/";
    std::string outDir = outDirBase + jobSaveLabel + "combinedRuns/xy/";
    std::vector<std::string> puType = {"0PU13","14PU21","22PU"};
    std::vector<int> puBins = {0,14,22,999};
    std::string sample = "Data";
    std::string triggerName = "SingleMu";
    std::string triggerTitle = "Single Muon";
    std::vector<TL1XvsY*> xvsy;

    // caloMetBE
    xvsy.emplace_back(new TL1XvsY());
    xvsy[0]->SetXBins(bins(200.0,1.0,0.0));
    xvsy[0]->SetX("caloMetBE","Offline E_{T}^{miss} (GeV)");
    xvsy[0]->SetYBins(bins(200.0,1.0,0.0));
    xvsy[0]->SetY("l1Met","L1 E_{T}^{miss} (GeV)");
    xvsy[0]->SetOutName(triggerName+"_caloMetBE_vs_l1Met");
    std::string t0rootFilePath = outDir + "xy_SingleMu_caloMetBE_vs_l1Met.root";
    xvsy[0]->SetOverwriteNames(t0rootFilePath.c_str(),"xy_caloMetBE_vs_l1Met");

    // mht
    // xvsy.emplace_back(new TL1XvsY());
    // xvsy[1]->SetXBins(bins(200.0,1.0,0.0));
    // xvsy[1]->SetX("recoMht","Offline H_{T}^{miss} (GeV)");
    // xvsy[1]->SetYBins(bins(200.0,1.0,0.0));
    // xvsy[1]->SetY("l1Mht","L1 H_{T}^{miss} (GeV)");
    // xvsy[1]->SetOutName(triggerName+"_recoMht_vs_l1Mht");

    // caloEttBE
    // xvsy.emplace_back(new TL1XvsY());
    // xvsy[2]->SetXBins(bins(600.0,10,0.0));
    // xvsy[2]->SetX("recoEtt","Offline Total E_{T} (GeV)");
    // xvsy[2]->SetYBins(bins(600.0,10,0.0));
    // xvsy[2]->SetY("l1Ett","L1 Total E_{T}");
    // xvsy[2]->SetOutName(triggerName+"_recoEtt_vs_l1Ett");

    // htt
    // xvsy.emplace_back(new TL1XvsY());
    // xvsy[3]->SetXBins(bins(600.0,1.0,0.0));
    // xvsy[3]->SetX("recohtt","Offline Total H_{T} (GeV)");
    // xvsy[3]->SetYBins(bins(600.0,1.0,0.0));
    // xvsy[3]->SetY("l1Htt","L1 Total H_{T}");
    // xvsy[3]->SetOutName(triggerName+"_htt_vs_l1Htt");
    
    // caloMetBE Phi
    xvsy.emplace_back(new TL1XvsY());
    xvsy[1]->SetXBins(phiBins());
    xvsy[1]->SetX("caloMetBEPhi","Offline E_{T}^{miss} Phi");
    xvsy[1]->SetYBins(phiBins());
    xvsy[1]->SetY("l1MetPhi","L1 E_{T}^{miss} Phi");
    xvsy[1]->SetOutName(triggerName+"_caloMetBEPhi_vs_l1MetPhi");
    // xvsy[1]->SetAddMark("Offline E_{T}^{miss} > 40 GeV");
    std::string t1rootFilePath = outDir + "xy_SingleMu_caloMetBEPhi_vs_l1MetPhi.root";
    xvsy[1]->SetOverwriteNames(t1rootFilePath.c_str(),"xy_caloMetBEPhi_vs_l1MetPhi");

    // mht Phi
    // xvsy.emplace_back(new TL1XvsY());
    // xvsy[3]->SetXBins(phiBins());
    // xvsy[3]->SetX("recoMhtPhi","Offline H_{T}^{miss} Phi");
    // xvsy[3]->SetYBins(phiBins());
    // xvsy[3]->SetY("l1MhtPhi","L1 H_{T}^{miss} Phi");
    // xvsy[3]->SetOutName(triggerName+"_recoMhtPhi_vs_l1MhtPhi");

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

std::vector<double> bins(double max, double width, double min)
{
    std::vector<double> temp;
    for(double binLowerEdge=min; binLowerEdge<=max; binLowerEdge+= width) temp.push_back(binLowerEdge);
    return temp;
}

std::vector<double> phiBins()
{
    std::vector<double> temp;
    for(double binLowerEdge=0.0; binLowerEdge<=TMath::Pi(); binLowerEdge+= (TMath::Pi())/36.) temp.push_back(binLowerEdge);
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
    return TMath::Min( (float)TMath::Abs(phi), (float)TMath::Abs(2*TMath::Pi()-phi) );
}
