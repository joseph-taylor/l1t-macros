#include "TGraphAsymmErrors.h"
#include "TFile.h"
#include "TLegend.h"
#include <TCanvas.h>

void nastyTurnonFromTwoFiles(){

	TFile *f1 = TFile::Open("/afs/cern.ch/user/t/taylor/l1t-macros/output_plots/MCvalidation_9Nov_doubleMu_dataSingleMu_v2/Turnons/run283865/effs_SingleMu_caloMetBE_l1MetSeeds.root");
	TFile *f2 = TFile::Open("/afs/cern.ch/user/t/taylor/l1t-macros/output_plots/MCvalidation_9Nov_doubleMu_mcZMM_v3/Turnons/ZMM/effs_SingleMu_caloMetBE_l1MetSeeds.root");

	TGraphAsymmErrors * t1a = (TGraphAsymmErrors*)f1->Get("divide_dist_recoJetEt_l1JetEt_36_by_dist_recoJetEt_l1JetEt_0");
	TGraphAsymmErrors * t1b = (TGraphAsymmErrors*)f1->Get("divide_dist_recoJetEt_l1JetEt_68_by_dist_recoJetEt_l1JetEt_0");
	TGraphAsymmErrors * t1c = (TGraphAsymmErrors*)f1->Get("divide_dist_recoJetEt_l1JetEt_128_by_dist_recoJetEt_l1JetEt_0");
	// TGraphAsymmErrors * t1d = (TGraphAsymmErrors*)f1->Get("divide_dist_recoJetEt_l1JetEt_200_by_dist_recoJetEt_l1JetEt_0");
	// TGraphAsymmErrors * t1e = (TGraphAsymmErrors*)f1->Get("divide_dist_recoJetEt_l1JetEt_36_by_dist_recoJetEt_l1JetEt_0");	

	TGraphAsymmErrors * t2a = (TGraphAsymmErrors*)f2->Get("divide_dist_recoJetEt_l1JetEt_36_by_dist_recoJetEt_l1JetEt_0");
	TGraphAsymmErrors * t2b = (TGraphAsymmErrors*)f2->Get("divide_dist_recoJetEt_l1JetEt_68_by_dist_recoJetEt_l1JetEt_0");
	TGraphAsymmErrors * t2c = (TGraphAsymmErrors*)f2->Get("divide_dist_recoJetEt_l1JetEt_128_by_dist_recoJetEt_l1JetEt_0");
	// TGraphAsymmErrors * t2d = (TGraphAsymmErrors*)f2->Get("divide_dist_recoJetEt_l1JetEt_200_by_dist_recoJetEt_l1JetEt_0");
	// TGraphAsymmErrors * t2e = (TGraphAsymmErrors*)f2->Get("divide_dist_recoJetEt_l1JetEt_36_by_dist_recoJetEt_l1JetEt_0");	

	t1a->SetMarkerStyle(10);
	t1b->SetMarkerStyle(10);
	t1c->SetMarkerStyle(10);
	// t1d->SetMarkerStyle(20);
	// t1e->SetMarkerStyle(20);
	t2a->SetMarkerStyle(3);
	t2b->SetMarkerStyle(3);
	t2c->SetMarkerStyle(3);
	// t2d->SetMarkerStyle(21);
	// t2e->SetMarkerStyle(21);				

	t1a->SetMarkerSize(3);
	t1b->SetMarkerSize(3);
	t1c->SetMarkerSize(3);
	// t1d->SetMarkerSize(3);
	// t1e->SetMarkerSize(3);
	t2a->SetMarkerSize(3);
	t2b->SetMarkerSize(3);
	t2c->SetMarkerSize(3);
	// t2d->SetMarkerSize(3);
	// t2e->SetMarkerSize(3);	

	t1a->SetLineColor(kRed);
	t1b->SetLineColor(kBlue+1);
	t1c->SetLineColor(kGreen+1);
	// t1d->SetLineColor(kBlack);
	// t1e->SetLineColor(kMagenta+1);
	t2a->SetLineColor(kRed);
	t2b->SetLineColor(kBlue+1);
	t2c->SetLineColor(kGreen+1);
	// t2d->SetLineColor(kBlack);
	// t2e->SetLineColor(kMagenta+1);	

	t1a->SetLineWidth(2);
	t1b->SetLineWidth(2);
	t1c->SetLineWidth(2);
	// t1d->SetLineWidth(2);
	// t1e->SetLineWidth(2);
	t2a->SetLineWidth(2);
	t2b->SetLineWidth(2);
	t2c->SetLineWidth(2);
	// t2d->SetLineWidth(2);
	// t2e->SetLineWidth(2);


	t1a->SetLineStyle(1);
	t1b->SetLineStyle(7);
	t1c->SetLineStyle(1);
	// t1d->SetLineStyle(7);
	// t1e->SetLineStyle(1);
	t2a->SetLineStyle(7);
	t2b->SetLineStyle(1);
	t2c->SetLineStyle(7);
	// t2d->SetLineStyle(1);
	// t2e->SetLineStyle(7);





	// t1a->
	// t1b->
	// t1c->
	// t1d->
	// t1e->
	// t2a->
	// t2b->
	// t2c->
	// t2d->
	// t2e->



	TCanvas* c=new TCanvas("c","c",700,700); //650,600
	c->SetLeftMargin(0.15);
	c->SetGrid();

	t1a->SetTitle("run276525-SingleMuon Central Jets");

	t1a->Draw();
	t1b->Draw("same");
	t1c->Draw("same");
	// // t1d->Draw("same");
	// t1e->Draw("same");
	t2a->Draw("same");
	t2b->Draw("same");
	t2c->Draw("same");
	// t2d->Draw("same");
	// t2e->Draw("same");

	TLegend * leg = new TLegend(0.55, 0.11, 0.89, 0.41); //(xmin, ymin, xmax, ymax)
	leg->SetLineColor(0);
	leg->AddEntry(t1a, "L1>36GeV newCorr", "L");
	leg->AddEntry(t2a, "L1>36GeV oldCorr", "L");
	leg->AddEntry(t1b, "L1>68GeV newCorr", "L");
	leg->AddEntry(t2b, "L1>68GeV oldCorr", "L");
	leg->AddEntry(t1c, "L1>128GeV newCorr", "L");
	leg->AddEntry(t2c, "L1>128GeV oldCorr", "L");
	// leg->AddEntry(t1d, "L1>176GeV newCorr", "L");
	// leg->AddEntry(t2d, "L1>176GeV oldCorr", "L");
	// leg->AddEntry(t1e, "L1>176GeV newCorr", "L");
	// leg->AddEntry(t2e, "L1>176GeV oldCorr", "L");
	leg->Draw();
}