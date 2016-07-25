#include <string>
#include <vector>

#include "../Plotting/tdrstyle.C"
#include "../Event/TL1EventClass.h"
#include "../Utilities/TL1Progress.C"
#include "../Utilities/TL1DateTime.C"
#include "../Plotting/TL1Turnon.h"

vector<double> bins();
vector<double> binsHF();
void SetMyStyle(int palette, double rmarg, TStyle * myStyle);

void plotJetTurnons()
{
    TStyle * myStyle(new TStyle(TDRStyle()));
    SetMyStyle(55, 0.07, myStyle);

    std::string run = "6.3fb^{-1}";
    std::string jobSaveLabel = "parallelRunning_ICHEPv2/";
    std::string outDirBase = "/afs/cern.ch/user/t/taylor/l1t-macros/output_plots/";
    std::string outDir = outDirBase + jobSaveLabel + "combinedRuns/TurnonsJets/";
    std::vector<std::string> puType = {"0PU13","14PU21","22PU"};
    std::vector<int> puBins = {0,14,22,999};
    std::string sample = "Data";
    std::string triggerName = "SingleMu";
    std::string triggerTitle = "Single Muon";
    bool doFit = false;
    std::vector<TL1Turnon*> turnons;

    // Jet Et - barrel
    // turnons.emplace_back(new TL1Turnon());
    // turnons[0]->SetSeeds({0., 36., 68., 128., 200.});
    // turnons[0]->SetXBins(bins());
    // turnons[0]->SetX("recoJetEt","Offline Jet E_{T} (GeV)");
    // turnons[0]->SetSeed("l1JetEt","L1 Jet E_{T}");
    // turnons[0]->SetOutName(triggerName+"_recoJetEt_l1JetEtSeeds_barrel");
    // turnons[0]->SetFit(doFit);
    // turnons[0]->SetAddMark("|#eta| < 1.479");

    // // Jet Et - end cap
    // turnons.emplace_back(new TL1Turnon());
    // turnons[1]->SetSeeds({0., 36., 68., 128., 200.});
    // turnons[1]->SetXBins(bins());
    // turnons[1]->SetX("recoJetEt","Offline Jet E_{T} (GeV)");
    // turnons[1]->SetSeed("l1JetEt","L1 Jet E_{T}");
    // turnons[1]->SetOutName(triggerName+"_recoJetEt_l1JetEtSeeds_endcap");
    // turnons[1]->SetFit(doFit);
    // turnons[1]->SetAddMark("1.479 < |#eta| < 3.0");

    // Jet Et - barrel + endcap
    turnons.emplace_back(new TL1Turnon());
    turnons[0]->SetSeeds({0., 36., 68., 128., 200.});
    turnons[0]->SetXBins(bins());
    turnons[0]->SetX("recoJetEt","Offline Jet E_{T} (GeV)");
    turnons[0]->SetSeed("l1JetEt","L1 Jet E_{T}");
    turnons[0]->SetOutName(triggerName+"_recoJetEt_l1JetEtSeeds_barrel-endcap");
    turnons[0]->SetFit(doFit);
    turnons[0]->SetAddMark("|#eta| < 3.0");
    std::string t0rootFilePath = outDir + "dists_SingleMu_recoJetEt_l1JetEtSeeds_barrel-endcap.root";
    turnons[0]->SetOverwriteNames(t0rootFilePath.c_str(),"dist_recoJetEt_l1JetEt");

    // Jet Et - HF
    turnons.emplace_back(new TL1Turnon());
    turnons[1]->SetSeeds({0., 36., 68., 128., 176.});
    turnons[1]->SetXBins(binsHF());
    turnons[1]->SetX("recoJetEt","Offline Jet E_{T} (GeV)");
    turnons[1]->SetSeed("l1JetEt","L1 Jet E_{T}");
    turnons[1]->SetOutName(triggerName+"_recoJetEt_l1JetEtSeeds_hf");
    turnons[1]->SetFit(doFit);
    turnons[1]->SetAddMark("|#eta| > 3.0");
    std::string t1rootFilePath = outDir + "dists_SingleMu_recoJetEt_l1JetEtSeeds_hf.root";
    turnons[1]->SetOverwriteNames(t1rootFilePath.c_str(),"dist_recoJetEt_l1JetEt");

    for(auto it=turnons.begin(); it!=turnons.end(); ++it)
    {
        (*it)->SetSample(sample,"");
        (*it)->SetTrigger(triggerName,triggerTitle);
        (*it)->SetRun(run);
        (*it)->SetOutDir(outDir);
        (*it)->SetPuType(puType);
        (*it)->SetPuBins(puBins);
        (*it)->OverwritePlots();
    }

    for(auto it=turnons.begin(); it!=turnons.end(); ++it)
    {
        (*it)->DrawPlots();
        (*it)->DrawTurnons();
    }
}

vector<double> bins()
{
    vector<double> temp;
    for(double binLowerEdge= 0.0; binLowerEdge< 120.0; binLowerEdge+=2.0) temp.push_back(binLowerEdge);
    for(double binLowerEdge=120.0; binLowerEdge< 180.0; binLowerEdge+=2.0) temp.push_back(binLowerEdge);
    for(double binLowerEdge=180.0; binLowerEdge< 300.0; binLowerEdge+=2.0) temp.push_back(binLowerEdge);
    for(double binLowerEdge=300.0; binLowerEdge< 400.1; binLowerEdge+=5.0) temp.push_back(binLowerEdge);
//    for(double binLowerEdge= 40.0; binLowerEdge< 70.0; binLowerEdge+= 2.5) temp.push_back(binLowerEdge);
//    for(double binLowerEdge= 70.0; binLowerEdge<200.0; binLowerEdge+= 5.0) temp.push_back(binLowerEdge);
//    for(double binLowerEdge=200.0; binLowerEdge<300.0; binLowerEdge+=10.0) temp.push_back(binLowerEdge);
//    for(double binLowerEdge=300.0; binLowerEdge<400.1; binLowerEdge+=20.0) temp.push_back(binLowerEdge);
    return temp;
}

vector<double> binsHF()
{
    vector<double> temp;
    for(double binLowerEdge=  0.0; binLowerEdge< 150.0; binLowerEdge+= 2.0) temp.push_back(binLowerEdge);      
    for(double binLowerEdge=150.0; binLowerEdge< 180.0; binLowerEdge+= 5.0) temp.push_back(binLowerEdge);
    for(double binLowerEdge=180.0; binLowerEdge< 200.0; binLowerEdge+=10.0) temp.push_back(binLowerEdge);
    for(double binLowerEdge=200.0; binLowerEdge< 220.0; binLowerEdge+=20.0) temp.push_back(binLowerEdge);  
    for(double binLowerEdge=220.0; binLowerEdge< 300.0; binLowerEdge+=40.0) temp.push_back(binLowerEdge);            
    for(double binLowerEdge=300.0; binLowerEdge< 400.1; binLowerEdge+=100.0) temp.push_back(binLowerEdge);
//    for(double binLowerEdge= 40.0; binLowerEdge< 70.0; binLowerEdge+= 2.5) temp.push_back(binLowerEdge);
//    for(double binLowerEdge= 70.0; binLowerEdge<200.0; binLowerEdge+= 5.0) temp.push_back(binLowerEdge);
//    for(double binLowerEdge=200.0; binLowerEdge<300.0; binLowerEdge+=10.0) temp.push_back(binLowerEdge);
//    for(double binLowerEdge=300.0; binLowerEdge<400.1; binLowerEdge+=20.0) temp.push_back(binLowerEdge);
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
