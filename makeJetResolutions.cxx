#include <string>
#include <vector>

#include "Plotting/tdrstyle.C"
#include "Event/TL1EventClass.h"
#include "Utilities/TL1Progress.C"
#include "Utilities/TL1DateTime.C"
#include "Plotting/TL1Resolution.h"

// note that this can be run on 'resolution' or 'energy' mode

// resolution[0]->SetPlotType("Energy");
// resolution[0]->SetBins(bins("Energy"));


std::vector<double> bins(std::string plotType);
void SetMyStyle(int palette, double rmarg, TStyle * myStyle);
double FoldPhi(double phi);

void makeJetResolutions()
{
    TStyle * myStyle(new TStyle(TDRStyle()));
    SetMyStyle(55, 0.07, myStyle);

    // Basic
    std::string sample = "Data";
    std::string triggerName = "SingleMu";
    std::string triggerTitle = "Single Muon";

    std::string run = "6.3fb^{-1}"; // an additional label for the plots 
    std::string outDirBase = "/afs/cern.ch/user/t/taylor/l1t-macros/output_plots/";
    std::vector<std::string> puType = {"0PU12","13PU19","20PU"};
    std::vector<int> puBins = {0,14,22,999};

    std::vector<std::string> inDir;
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276242_SingleMuon/160713_011258/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276243_SingleMuon/160713_010926/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276244_SingleMuon/160713_010210/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276282_SingleMuon/160713_011747/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276283_SingleMuon/160713_011101/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276315_SingleMuon/160713_011624/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276317_SingleMuon/160713_011002/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276318_SingleMuon/160713_011559/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276326_SingleMuon/160713_153648/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276327_SingleMuon/160713_010451/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276352_SingleMuon/160713_011033/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276355_SingleMuon/160713_010714/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276357_SingleMuon/160713_012210/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276361_SingleMuon/160713_011534/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276363_SingleMuon/160713_011945/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276384_SingleMuon/160713_010558/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276437_SingleMuon/160713_012016/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276453_SingleMuon/160713_154023/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276454_SingleMuon/160713_154139/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276455_SingleMuon/160713_154436/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276456_SingleMuon/160713_154306/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276457_SingleMuon/160713_154350/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276458_SingleMuon/160713_154415/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276495_SingleMuon/160713_154052/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276501_SingleMuon/160713_153938/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276502_SingleMuon/160713_154244/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276525_SingleMuon/160713_153738/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276527_SingleMuon/160713_153913/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276528_SingleMuon/160713_154201/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276542_SingleMuon/160713_153619/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276543_SingleMuon/160713_153848/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276544_SingleMuon/160713_154118/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276545_SingleMuon/160713_154221/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276581_SingleMuon/160713_154327/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276582_SingleMuon/160713_153823/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276583_SingleMuon/160713_153713/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276584_SingleMuon/160713_154000/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276585_SingleMuon/160713_153801/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276586_SingleMuon/160713_154458/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276653_SingleMuon/160715_224916/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276655_SingleMuon/160715_224942/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276659_SingleMuon/160715_224707/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276775_SingleMuon/160715_224730/0000/*.root");
    inDir.push_back("root://eoscms.cern.ch//eos/cms/store/group/dpg_trigger/comm_trigger/L1Trigger/L1Menu2016/Stage2/Collision2016-wRECO-l1t-integration-v71p1/SingleMuon/crab_Collision2016-wRECO-l1t-integration-v71p1__276776_SingleMuon/160715_224856/0000/*.root");           
    
    std::string outDir = outDirBase+"/ICHEPv1_"+TL1DateTime::GetDate()+"_"+sample+"_"+"run-"+run+"_"+triggerName+"/resJets/";

    TL1EventClass * event(new TL1EventClass(inDir));
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

    for(auto it=resolution.begin(); it!=resolution.end(); ++it)
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

        for(unsigned iRecoJet=0; iRecoJet<event->GetPEvent()->fJets->nJets; ++iRecoJet)
        {
            if( !event->fIsLeadingRecoJet ) continue;
            if( !event->fIsMatchedL1Jet ) continue;

            int pu = event->GetPEvent()->fVertex->nVtx;
            auto recoJet = event->GetPEvent()->fJets;

            double recoEt = recoJet->etCorr[event->fLeadingRecoJetIndex];
            double recoEta = recoJet->eta[event->fLeadingRecoJetIndex];
            double recoPhi = FoldPhi(recoJet->phi[event->fLeadingRecoJetIndex]);

            double l1Et = event->fL1JetEt[event->fMatchedL1JetIndex];
            double l1Eta = event->fL1JetEta[event->fMatchedL1JetIndex];
            double l1Phi = FoldPhi(event->fL1JetPhi[event->fMatchedL1JetIndex]);

            if( abs(recoEta) <= 1.479 )
            {
                //if(recoEt!=0.0 && l1Et!=0.0 && recoEt>=30.0) resolution[0]->Fill(recoEt, l1Et, pu);
                //if(recoPhi!=0.0 && l1Phi!=0.0 && recoEt>=30.0) resolution[4]->Fill(recoPhi, l1Phi, pu);

                if(recoEta!=0.0 && l1Eta!=0.0 && recoEt>=30.0) resolution[4]->Fill(abs(recoEta), abs(l1Eta), pu);
                if(recoEt>=30.0 && l1Et!=0.0 ) resolution[0]->Fill(recoEt, l1Et, pu);
                if(recoPhi!=0.0 && l1Phi!=0.0 && recoEt>=30.0) resolution[2]->Fill(recoPhi, l1Phi, pu);
            }
            else if( abs(recoEta) <= 3.0 )
            {
                //if(recoEt!=0.0 && l1Et!=0.0 && recoEt>=30.0) resolution[1]->Fill(recoEt, l1Et, pu);
                //if(recoPhi!=0.0 && l1Phi!=0.0 && recoEt>=30.0) resolution[5]->Fill(recoPhi, l1Phi, pu);

                if(recoEta!=0.0 && l1Eta!=0.0 && recoEt>=30.0) resolution[4]->Fill(abs(recoEta), abs(l1Eta), pu);
                if(recoEt>=30.0 && l1Et!=0.0 ) resolution[0]->Fill(recoEt, l1Et, pu);
                if(recoPhi!=0.0 && l1Phi!=0.0 && recoEt>=30.0) resolution[2]->Fill(recoPhi, l1Phi, pu);
            }
            else
            {
                if(recoEt>=30.0 && l1Et!=0.0) resolution[1]->Fill(recoEt, l1Et, pu);
                if(recoPhi!=0.0 && l1Phi!=0.0 && recoEt>=30.0) resolution[3]->Fill(recoPhi, l1Phi, pu);
                if(recoEta!=0.0 && l1Eta!=0.0 && recoEt>=30.0) resolution[4]->Fill(abs(recoEta), abs(l1Eta), pu);
            }
        }

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
