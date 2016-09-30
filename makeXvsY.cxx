#include <string>
#include <vector>
#include <algorithm>

#include "Plotting/tdrstyle.C"
#include "Event/TL1EventClass.h"
#include "Utilities/TL1Progress.C"
#include "Utilities/TL1DateTime.C"
#include "Plotting/TL1XvsY.h"
#include "runDirectories.cxx"

std::vector<double> bins(double max, double width, double min);
std::vector<double> phiBins();
void SetMyStyle(int palette, double rmarg, TStyle * myStyle);
double FoldPhi(double phi);

void makeXvsY(unsigned runChoiceIndex, std::string batchJobSaveLabel)
{
    TStyle * myStyle(new TStyle(TDRStyle()));
    SetMyStyle(57, 0.14, myStyle);

    std::vector<std::string> inDir;
    inDir.push_back(vecOfDirs[runChoiceIndex]);
    std::string run = vecOfRuns[runChoiceIndex];
    std::string outDirBase = "/afs/cern.ch/user/t/taylor/l1t-macros/output_plots/";
    std::string outDir = outDirBase + batchJobSaveLabel + "/xy/" + run;
    std::vector<std::string> puType = {"20PU29","30PU39","40PU49"};
    std::vector<int> puBins = {20,30,40,50};
    std::string sample = "Data";
    std::string triggerName = "SingleMu";
    std::string triggerTitle = "Single Muon";

    TL1EventClass * event(new TL1EventClass(inDir));
    std::vector<TL1XvsY*> xvsy;

    // caloMetBE
    xvsy.emplace_back(new TL1XvsY());
    xvsy[0]->SetXBins(bins(200.0,1.0,0.0));
    xvsy[0]->SetX("caloMetBE","Offline E_{T}^{miss} (GeV)");
    xvsy[0]->SetYBins(bins(200.0,1.0,0.0));
    xvsy[0]->SetY("l1Met","L1 E_{T}^{miss} (GeV)");
    xvsy[0]->SetOutName(triggerName+"_caloMetBE_vs_l1Met");

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
        (*it)->InitPlots();
    }

    unsigned NEntries = event->GetPEvent()->GetNEntries();
    while( event->Next() )
    {
        unsigned position = event->GetPEvent()->GetPosition()+1;
        TL1Progress::PrintProgressBar(position, NEntries);

        int pu = event->GetPEvent()->fVertex->nVtx;
        auto sums = event->GetPEvent()->fSums;

        //----- HTT -----//
        //double recoHtt = sums->Ht;
        //double l1Htt = event->fL1Htt;
        //if( recoHtt > 0.0 && l1Htt > 0.0 )
        //    xvsy[3]->Fill(recoHtt, l1Htt, pu);
        
        //bool mhtPassFlag = event->fMhtPassFlag;

        //----- MHT -----//
        double recoMht = sums->mHt;
        double l1Mht = event->fL1Mht;
        double recoMhtPhi = sums->mHtPhi;
        double l1MhtPhi = event->fL1MhtPhi;

        if( recoMht > 0.0 && l1Mht > 0.0 )
        {
            // xvsy[1]->Fill(recoMht, l1Mht, pu);
            // xvsy[3]->Fill(FoldPhi(recoMhtPhi), FoldPhi(l1MhtPhi), pu);
        }

        //----- ETT -----//
        //double recoEtt = sums->caloSumEtBE;
        //double l1Ett = event->fL1Ett;
        //if( recoEtt > 0.0 && l1Ett > 0.0 )
        //    xvsy[2]->Fill(recoEtt, l1Ett, pu);

        if( !event->fMuonFilterPassFlag ) continue; // JOE COMMENTED IN/OUT

        //----- MET -----//
        double recoMet = sums->caloMetBE;
        double l1Met = event->fL1Met;
        double recoMetPhi = sums->caloMetPhiBE;
        double l1MetPhi = event->fL1MetPhi;
        if( event->fMetFilterPassFlag && recoMet > 40.0 && l1Met != 0.0 )
        {
            xvsy[1]->Fill(FoldPhi(recoMetPhi), FoldPhi(l1MetPhi), pu);
        }
        if( event->fMetFilterPassFlag && recoMet != 0.0 && l1Met != 0.0 )
        {
            xvsy[0]->Fill(recoMet, l1Met, pu);
        }
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
