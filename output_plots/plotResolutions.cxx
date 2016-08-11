#include <string>
#include <vector>

#include "../Plotting/tdrstyle.C"
#include "../Event/TL1EventClass.h"
#include "../Utilities/TL1Progress.C"
#include "../Utilities/TL1DateTime.C"
#include "../Plotting/TL1Resolution.h"

std::vector<double> bins(std::string plotType);
void SetMyStyle(int palette, double rmarg, TStyle * myStyle);
double FoldPhi(double phi);

void plotResolutions()
{
    TStyle * myStyle(new TStyle(TDRStyle()));
    SetMyStyle(55, 0.07, myStyle);

    std::string run = "3.1fb^{-1}";
    std::string jobSaveLabel = "parallelRunning_ICHEPv2redoRESO/";
    std::string outDirBase = "/afs/cern.ch/user/t/taylor/l1t-macros/output_plots/";
    std::string outDir = outDirBase + jobSaveLabel + "combinedRuns/Resolutions/";
    std::vector<std::string> puType = {"0PU13","14PU21","22PU"};
    std::vector<int> puBins = {0,14,22,999};
    std::string sample = "Data";
    std::string triggerName = "SingleMu";
    std::string triggerTitle = "Single Muon";
    std::vector<TL1Resolution*> resolution;
    
    // caloMetBE
    resolution.emplace_back(new TL1Resolution());
    resolution[0]->SetPlotType("Energy");
    resolution[0]->SetBins(bins("Energy"));
    resolution[0]->SetX("caloMetBE","Offline E_{T}^{miss}");
    resolution[0]->SetY("l1met","L1 E_{T}^{miss}");
    resolution[0]->SetOutName(triggerName+"_caloMetBE_over_l1Met");
    resolution[0]->SetAddMark("Offline E_{T}^{miss} > 40 GeV");
    std::string t0rootFilePath = outDir + "res_SingleMu_caloMetBE_over_l1Met.root";
    resolution[0]->SetOverwriteNames(t0rootFilePath.c_str(),"res_Energy_caloMetBE_l1met");

    // mht
    // resolution.emplace_back(new TL1Resolution());
    // resolution[1]->SetBins(bins());
    // resolution[1]->SetX("mht","Offline H_{T}^{miss}");
    // resolution[1]->SetY("l1mht","L1 H_{T}^{miss}");
    // resolution[1]->SetOutName(triggerName+"_recalcMht_over_l1Mht");
    // resolution[1]->SetAddMark("L1 ETM > 40 GeV");

    // caloEttBE
    // resolution.emplace_back(new TL1Resolution());
    // resolution[2]->SetBins(bins());
    // resolution[2]->SetX("caloEttBE","Offline Total E_{T}");
    // resolution[2]->SetY("l1ett","L1 Total E_{T}");
    // resolution[2]->SetOutName(triggerName+"_caloEttBE_over_l1Ett");
    // resolution[2]->SetAddMark("L1 ETM > 40 GeV");

    // htt
    // resolution.emplace_back(new TL1Resolution());
    // resolution[1]->SetPlotType("Energy");
    // resolution[1]->SetBins(bins("Energy"));
    // resolution[1]->SetX("htt","Offline Total H_{T}");
    // resolution[1]->SetY("l1htt","L1 Total H_{T}");
    // resolution[1]->SetOutName(triggerName+"_htt_over_l1Htt");
    // resolution[1]->SetAddMark("Offline HTT > 100 GeV");

    // caloMetBE Phi
    // resolution.emplace_back(new TL1Resolution());
    // resolution[2]->SetPlotType("Position");
    // resolution[2]->SetBins(bins("Position"));
    // resolution[2]->SetX("caloMetBEPhi","Offline E_{T}^{miss} Phi");
    // resolution[2]->SetY("l1metphi","L1 E_{T}^{miss} Phi");
    // resolution[2]->SetOutName(triggerName+"_caloMetBEPhi_over_l1MetPhi");
    //resolution[0]->SetAddMark("L1 ETM > 40 GeV");

    // mht Phi
    // resolution.emplace_back(new TL1Resolution());
    // resolution[3]->SetPlotType("Position");
    // resolution[3]->SetBins(bins("Position"));
    // resolution[3]->SetX("mhtPhi","Offline H_{T}^{miss} Phi");
    // resolution[3]->SetY("l1httphi","L1 Total H_{T} Phi");
    // resolution[3]->SetOutName(triggerName+"_recalcMhtPhi_over_l1MhtPhi");
    //resolution[0]->SetAddMark("L1 ETM > 40 GeV");

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
    if( plotType == "Energy" ) for(double binLowerEdge=-1.0; binLowerEdge<=1.5; binLowerEdge+= 0.05) temp.push_back(binLowerEdge);
    else if( plotType == "Position" ) for(double binLowerEdge=-0.3; binLowerEdge<=0.3; binLowerEdge+= 0.005) temp.push_back(binLowerEdge);
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
