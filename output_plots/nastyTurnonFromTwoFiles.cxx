#include "TGraphAsymmErrors.h"
#include "TFile.h"
#include "TLegend.h"
#include <TCanvas.h>

#include <TH1F.h>
#include <TH2F.h>
#include <TEfficiency.h>
// #include <TCanvas.h>
#include <TROOT.h>
// #include <TFile.h>
#include <TSystem.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TLine.h>
// #include <TLegend.h>


TStyle * TDRStyle();


void nastyTurnonFromTwoFiles(){

	tdrStyle = TDRStyle();
	gROOT->SetStyle("tdrStyle");

	TLatex * latex = new TLatex();
	latex->SetNDC();
	latex->SetTextFont(42);



	// TFile *f1 = TFile::Open("/users/jt15104/l1t-macros/output_plots/MC/sums/effs_SingleMu_caloMetBE_l1MetSeeds.root");
	// TFile *f2 = TFile::Open("/users/jt15104/l1t-macros/output_plots/data/sums/effs_SingleMu_caloMetBE_l1MetSeeds.root");

	// TGraphAsymmErrors * t1a = (TGraphAsymmErrors*)f1->Get("dist_caloMetBE_l1MetSeed_40_DIV_dist_caloMetBE_l1MetSeed_0");
	// TGraphAsymmErrors * t1b = (TGraphAsymmErrors*)f1->Get("dist_caloMetBE_l1MetSeed_60_DIV_dist_caloMetBE_l1MetSeed_0");
	// TGraphAsymmErrors * t1c = (TGraphAsymmErrors*)f1->Get("dist_caloMetBE_l1MetSeed_80_DIV_dist_caloMetBE_l1MetSeed_0");
	// TGraphAsymmErrors * t1d = (TGraphAsymmErrors*)f1->Get("dist_caloMetBE_l1MetSeed_100_DIV_dist_caloMetBE_l1MetSeed_0");
	// TGraphAsymmErrors * t1e = (TGraphAsymmErrors*)f1->Get("dist_caloMetBE_l1MetSeed_120_DIV_dist_caloMetBE_l1MetSeed_0");	

	// TGraphAsymmErrors * t2a = (TGraphAsymmErrors*)f2->Get("dist_caloMetBE_l1MetSeed_40_DIV_dist_caloMetBE_l1MetSeed_0");
	// TGraphAsymmErrors * t2b = (TGraphAsymmErrors*)f2->Get("dist_caloMetBE_l1MetSeed_60_DIV_dist_caloMetBE_l1MetSeed_0");
	// TGraphAsymmErrors * t2c = (TGraphAsymmErrors*)f2->Get("dist_caloMetBE_l1MetSeed_80_DIV_dist_caloMetBE_l1MetSeed_0");
	// TGraphAsymmErrors * t2d = (TGraphAsymmErrors*)f2->Get("dist_caloMetBE_l1MetSeed_100_DIV_dist_caloMetBE_l1MetSeed_0");
	// TGraphAsymmErrors * t2e = (TGraphAsymmErrors*)f2->Get("dist_caloMetBE_l1MetSeed_120_DIV_dist_caloMetBE_l1MetSeed_0");		






	// TFile *f1 = TFile::Open("/users/jt15104/l1t-macros/output_plots/MC/sums/effs_SingleMu_recoHtt_l1HttSeeds.root");
	// TFile *f2 = TFile::Open("/users/jt15104/l1t-macros/output_plots/data/sums/effs_SingleMu_recoHtt_l1HttSeeds.root");

	// TGraphAsymmErrors * t1a = (TGraphAsymmErrors*)f1->Get("dist_recoHtt_l1Htt_120_DIV_dist_recoHtt_l1Htt_0");
	// TGraphAsymmErrors * t1b = (TGraphAsymmErrors*)f1->Get("dist_recoHtt_l1Htt_160_DIV_dist_recoHtt_l1Htt_0");
	// TGraphAsymmErrors * t1c = (TGraphAsymmErrors*)f1->Get("dist_recoHtt_l1Htt_200_DIV_dist_recoHtt_l1Htt_0");
	// TGraphAsymmErrors * t1d = (TGraphAsymmErrors*)f1->Get("dist_recoHtt_l1Htt_240_DIV_dist_recoHtt_l1Htt_0");
	// TGraphAsymmErrors * t1e = (TGraphAsymmErrors*)f1->Get("dist_recoHtt_l1Htt_280_DIV_dist_recoHtt_l1Htt_0");	

	// TGraphAsymmErrors * t2a = (TGraphAsymmErrors*)f2->Get("dist_recoHtt_l1Htt_120_DIV_dist_recoHtt_l1Htt_0");
	// TGraphAsymmErrors * t2b = (TGraphAsymmErrors*)f2->Get("dist_recoHtt_l1Htt_160_DIV_dist_recoHtt_l1Htt_0");
	// TGraphAsymmErrors * t2c = (TGraphAsymmErrors*)f2->Get("dist_recoHtt_l1Htt_200_DIV_dist_recoHtt_l1Htt_0");
	// TGraphAsymmErrors * t2d = (TGraphAsymmErrors*)f2->Get("dist_recoHtt_l1Htt_240_DIV_dist_recoHtt_l1Htt_0");
	// TGraphAsymmErrors * t2e = (TGraphAsymmErrors*)f2->Get("dist_recoHtt_l1Htt_280_DIV_dist_recoHtt_l1Htt_0");	










	// TFile *f1 = TFile::Open("/users/jt15104/l1t-macros/output_plots/MC/jets/effs_SingleMu_recoJetEt_l1JetEtSeeds_barrel-endcap.root");
	// TFile *f2 = TFile::Open("/users/jt15104/l1t-macros/output_plots/data/jets/effs_SingleMu_recoJetEt_l1JetEtSeeds_barrel-endcap.root");

	// TGraphAsymmErrors * t1a = (TGraphAsymmErrors*)f1->Get("dist_recoJetEt_l1JetEt_36_DIV_dist_recoJetEt_l1JetEt_0");
	// TGraphAsymmErrors * t1b = (TGraphAsymmErrors*)f1->Get("dist_recoJetEt_l1JetEt_68_DIV_dist_recoJetEt_l1JetEt_0");
	// TGraphAsymmErrors * t1c = (TGraphAsymmErrors*)f1->Get("dist_recoJetEt_l1JetEt_128_DIV_dist_recoJetEt_l1JetEt_0");
	// TGraphAsymmErrors * t1d = (TGraphAsymmErrors*)f1->Get("dist_recoJetEt_l1JetEt_200_DIV_dist_recoJetEt_l1JetEt_0");
	// TGraphAsymmErrors * t1e = (TGraphAsymmErrors*)f1->Get("dist_recoJetEt_l1JetEt_200_DIV_dist_recoJetEt_l1JetEt_0");	

	// TGraphAsymmErrors * t2a = (TGraphAsymmErrors*)f2->Get("dist_recoJetEt_l1JetEt_36_DIV_dist_recoJetEt_l1JetEt_0");
	// TGraphAsymmErrors * t2b = (TGraphAsymmErrors*)f2->Get("dist_recoJetEt_l1JetEt_68_DIV_dist_recoJetEt_l1JetEt_0");
	// TGraphAsymmErrors * t2c = (TGraphAsymmErrors*)f2->Get("dist_recoJetEt_l1JetEt_128_DIV_dist_recoJetEt_l1JetEt_0");
	// TGraphAsymmErrors * t2d = (TGraphAsymmErrors*)f2->Get("dist_recoJetEt_l1JetEt_200_DIV_dist_recoJetEt_l1JetEt_0");
	// TGraphAsymmErrors * t2e = (TGraphAsymmErrors*)f2->Get("dist_recoJetEt_l1JetEt_200_DIV_dist_recoJetEt_l1JetEt_0");		
















	TFile *f1 = TFile::Open("/users/jt15104/l1t-macros/output_plots/MC/jets/effs_SingleMu_recoJetEt_l1JetEtSeeds_hf.root");
	TFile *f2 = TFile::Open("/users/jt15104/l1t-macros/output_plots/data/jets/effs_SingleMu_recoJetEt_l1JetEtSeeds_hf.root");

	TGraphAsymmErrors * t1a = (TGraphAsymmErrors*)f1->Get("dist_recoJetEt_l1JetEt_36_DIV_dist_recoJetEt_l1JetEt_0");
	TGraphAsymmErrors * t1b = (TGraphAsymmErrors*)f1->Get("dist_recoJetEt_l1JetEt_68_DIV_dist_recoJetEt_l1JetEt_0");
	TGraphAsymmErrors * t1c = (TGraphAsymmErrors*)f1->Get("dist_recoJetEt_l1JetEt_68_DIV_dist_recoJetEt_l1JetEt_0");
	TGraphAsymmErrors * t1d = (TGraphAsymmErrors*)f1->Get("dist_recoJetEt_l1JetEt_176_DIV_dist_recoJetEt_l1JetEt_0");
	TGraphAsymmErrors * t1e = (TGraphAsymmErrors*)f1->Get("dist_recoJetEt_l1JetEt_128_DIV_dist_recoJetEt_l1JetEt_0");	

	TGraphAsymmErrors * t2a = (TGraphAsymmErrors*)f2->Get("dist_recoJetEt_l1JetEt_36_DIV_dist_recoJetEt_l1JetEt_0");
	TGraphAsymmErrors * t2b = (TGraphAsymmErrors*)f2->Get("dist_recoJetEt_l1JetEt_68_DIV_dist_recoJetEt_l1JetEt_0");
	TGraphAsymmErrors * t2c = (TGraphAsymmErrors*)f2->Get("dist_recoJetEt_l1JetEt_68_DIV_dist_recoJetEt_l1JetEt_0");
	TGraphAsymmErrors * t2d = (TGraphAsymmErrors*)f2->Get("dist_recoJetEt_l1JetEt_176_DIV_dist_recoJetEt_l1JetEt_0");
	TGraphAsymmErrors * t2e = (TGraphAsymmErrors*)f2->Get("dist_recoJetEt_l1JetEt_128_DIV_dist_recoJetEt_l1JetEt_0");		
















	t1a->SetMarkerStyle(10);
	t1b->SetMarkerStyle(10);
	t1c->SetMarkerStyle(10);
	// t1d->SetMarkerStyle(10);
	t1e->SetMarkerStyle(10);
	t2a->SetMarkerStyle(3);
	t2b->SetMarkerStyle(3);
	t2c->SetMarkerStyle(3);
	// t2d->SetMarkerStyle(3);
	t2e->SetMarkerStyle(3);				

	t1a->SetMarkerSize(3);
	t1b->SetMarkerSize(3);
	t1c->SetMarkerSize(3);
	// t1d->SetMarkerSize(3);
	t1e->SetMarkerSize(3);
	t2a->SetMarkerSize(3);
	t2b->SetMarkerSize(3);
	t2c->SetMarkerSize(3);
	// t2d->SetMarkerSize(3);
	t2e->SetMarkerSize(3);	

	t1a->SetLineColor(kRed);
	t1b->SetLineColor(kBlack);
	t1c->SetLineColor(kGreen+1);
	t1d->SetLineColor(kBlack);
	t1e->SetLineColor(kBlue+1);
	t2a->SetLineColor(kRed);
	t2b->SetLineColor(kBlack);
	t2c->SetLineColor(kGreen+1);
	t2d->SetLineColor(kBlack);
	t2e->SetLineColor(kBlue+1);	

	t1a->SetLineWidth(2);
	t1b->SetLineWidth(2);
	t1c->SetLineWidth(2);
	t1d->SetLineWidth(2);
	t1e->SetLineWidth(2);
	t2a->SetLineWidth(2);
	t2b->SetLineWidth(2);
	t2c->SetLineWidth(2);
	t2d->SetLineWidth(2);
	t2e->SetLineWidth(2);


	t1a->SetLineStyle(1);
	t1b->SetLineStyle(7);
	t1c->SetLineStyle(1);
	t1d->SetLineStyle(7);
	t1e->SetLineStyle(1);
	t2a->SetLineStyle(7);
	t2b->SetLineStyle(1);
	t2c->SetLineStyle(7);
	t2d->SetLineStyle(1);
	t2e->SetLineStyle(7);





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



	TCanvas* c=new TCanvas("c","c"); //650,600
	c->SetLeftMargin(0.15);
	c->SetGrid();

	t1a->SetTitle("run276525-SingleMuon Central Jets");

	t1a->Draw();
	// t1b->Draw("same");
	t1c->Draw("same");
	// t1d->Draw("same");
	t1e->Draw("same");
	t2a->Draw("same");
	// t2b->Draw("same");
	t2c->Draw("same");
	// t2d->Draw("same");
	t2e->Draw("same");



	latex->SetTextAlign(11); // align from left
	latex->DrawLatex(0.15,0.92,"#bf{CMS} #it{Preliminary} Data & MC");
	latex->SetTextAlign(31); // align from right
	latex->DrawLatex(0.92,0.92,"#sqrt{s} = 13 TeV");




	// TLegend * leg = new TLegend(0.56, 0.15, 0.88, 0.41); //(xmin, ymin, xmax, ymax)
	// leg->SetLineColor(0);
	// leg->AddEntry(t1a, "L1 MET>40 MC", "L");
	// leg->AddEntry(t2a, "L1 MET>40 Data", "L");
	// // leg->AddEntry(t1b, "L1 MET>60 MC", "L");
	// // leg->AddEntry(t2b, "L1 MET>60 Data", "L");
	// leg->AddEntry(t1c, "L1 MET>80 MC", "L");
	// leg->AddEntry(t2c, "L1 MET>80 Data", "L");
	// // leg->AddEntry(t1d, "L1 MET>100 MC", "L");
	// // leg->AddEntry(t2d, "L1 MET>100 Data", "L");
	// leg->AddEntry(t1e, "L1 MET>120 MC", "L");
	// leg->AddEntry(t2e, "L1 MET>120 Data", "L");
	// leg->Draw();
	// c->SaveAs("met.pdf");






	// TLegend * leg = new TLegend(0.56, 0.15, 0.88, 0.41); //(xmin, ymin, xmax, ymax)
	// leg->SetLineColor(0);
	// leg->AddEntry(t1a, "L1 HT > 120 MC", "L");
	// leg->AddEntry(t2a, "L1 HT > 120 Data", "L");
	// // leg->AddEntry(t1b, "L1 MET>60 MC", "L");
	// // leg->AddEntry(t2b, "L1 MET>60 Data", "L");
	// leg->AddEntry(t1c, "L1 HT > 200 MC", "L");
	// leg->AddEntry(t2c, "L1 HT > 200 Data", "L");
	// // leg->AddEntry(t1d, "L1 MET>100 MC", "L");
	// // leg->AddEntry(t2d, "L1 MET>100 Data", "L");
	// leg->AddEntry(t1e, "L1 HT > 280 MC", "L");
	// leg->AddEntry(t2e, "L1 HT > 280 Data", "L");
	// leg->Draw();
	// c->SaveAs("htt.pdf");








	// TLegend * leg = new TLegend(0.56, 0.15, 0.88, 0.50); //(xmin, ymin, xmax, ymax)
	// leg->SetLineColor(0);
	// leg->AddEntry(t1a, "L1 Jet > 36 MC", "L");
	// leg->AddEntry(t2a, "L1 Jet > 36 Data", "L");
	// leg->AddEntry(t1b, "L1 Jet > 68 MC", "L");
	// leg->AddEntry(t2b, "L1 Jet > 68 Data", "L");
	// leg->AddEntry(t1c, "L1 Jet > 128 MC", "L");
	// leg->AddEntry(t2c, "L1 Jet > 128 Data", "L");
	// // leg->AddEntry(t1d, "L1 MET>100 MC", "L");
	// // leg->AddEntry(t2d, "L1 MET>100 Data", "L");
	// leg->AddEntry(t1e, "L1 Jet > 200 MC", "L");
	// leg->AddEntry(t2e, "L1 Jet > 200 Data", "L");
	// leg->Draw();
	// c->SaveAs("cenJet.pdf");



	TLegend * leg = new TLegend(0.56, 0.15, 0.88, 0.50); //(xmin, ymin, xmax, ymax)
	leg->SetLineColor(0);
	leg->AddEntry(t1a, "L1 Jet > 36 MC", "L");
	leg->AddEntry(t2a, "L1 Jet > 36 Data", "L");
	// leg->AddEntry(t1b, "L1 Jet > 68 MC", "L");
	// leg->AddEntry(t2b, "L1 Jet > 68 Data", "L");
	leg->AddEntry(t1c, "L1 Jet > 68 MC", "L");
	leg->AddEntry(t2c, "L1 Jet > 68 Data", "L");
	// leg->AddEntry(t1d, "L1 MET>100 MC", "L");
	// leg->AddEntry(t2d, "L1 MET>100 Data", "L");
	leg->AddEntry(t1e, "L1 Jet > 128 MC", "L");
	leg->AddEntry(t2e, "L1 Jet > 128 Data", "L");
	leg->Draw();
	c->SaveAs("hfJet.pdf");






}










TStyle * TDRStyle()
{
	TStyle * tdrStyle = new TStyle("tdrStyle","");

	//tdrStyle->SetPalette(palette);

	// For the canvas:
	tdrStyle->SetCanvasBorderMode(0);
	tdrStyle->SetCanvasColor(kWhite);
	tdrStyle->SetCanvasDefH(600); //Height of canvas
	tdrStyle->SetCanvasDefW(800); //Width of canvas
	tdrStyle->SetCanvasDefX(0);   //POsition on screen
	tdrStyle->SetCanvasDefY(0);

	// For the Pad:
	tdrStyle->SetPadBorderMode(0);
	// tdrStyle->SetPadBorderSize(Width_t size = 1);
	tdrStyle->SetPadColor(kWhite);
	tdrStyle->SetPadGridX(false);
	tdrStyle->SetPadGridY(false);
	tdrStyle->SetGridColor(0);
	tdrStyle->SetGridStyle(3);
	tdrStyle->SetGridWidth(1);
	tdrStyle->SetPadGridX(false);
	tdrStyle->SetPadGridY(false);

	// For the frame:
	tdrStyle->SetFrameBorderMode(0);
	tdrStyle->SetFrameBorderSize(1);
	tdrStyle->SetFrameFillColor(0);
	tdrStyle->SetFrameFillStyle(0);
	tdrStyle->SetFrameLineColor(1);
	tdrStyle->SetFrameLineStyle(1);
	tdrStyle->SetFrameLineWidth(1);

	// For the histo:
	// tdrStyle->SetHistFillColor(1);
	// tdrStyle->SetHistFillStyle(0);
	tdrStyle->SetHistLineColor(1);
	tdrStyle->SetHistLineStyle(0);
	tdrStyle->SetHistLineWidth(1);
	// tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
	// tdrStyle->SetNumberContours(Int_t number = 20);

	tdrStyle->SetEndErrorSize(2);
	//  tdrStyle->SetErrorMarker(20);
	tdrStyle->SetErrorX(0.);

	tdrStyle->SetMarkerStyle(20);

	//For the legend
	tdrStyle->SetLegendBorderSize(0);
	tdrStyle->SetLegendFillColor(0);
	tdrStyle->SetLegendFont(42);
	tdrStyle->SetLegendTextSize(0.05);

	//For the fit/function:
	tdrStyle->SetOptFit(0);
	tdrStyle->SetFitFormat("5.4g");
	tdrStyle->SetFuncColor(2);
	tdrStyle->SetFuncStyle(1);
	tdrStyle->SetFuncWidth(1);

	//For the date:
	tdrStyle->SetOptDate(0);
	// tdrStyle->SetDateX(Float_t x = 0.01);
	// tdrStyle->SetDateY(Float_t y = 0.01);

	// For the statistics box:
	tdrStyle->SetOptFile(0);
	tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
	tdrStyle->SetStatColor(kWhite);
	tdrStyle->SetStatFont(42);
	tdrStyle->SetStatFontSize(0.025);
	tdrStyle->SetStatTextColor(1);
	tdrStyle->SetStatFormat("6.4g");
	tdrStyle->SetStatBorderSize(1);
	tdrStyle->SetStatH(0.1);
	tdrStyle->SetStatW(0.15);
	// tdrStyle->SetStatStyle(Style_t style = 1001);
	// tdrStyle->SetStatX(Float_t x = 0);
	// tdrStyle->SetStatY(Float_t y = 0);

	// Margins:
	//tdrStyle->SetPadTopMargin(0.05);
	tdrStyle->SetPadTopMargin(0.10);
	tdrStyle->SetPadBottomMargin(0.13);
	// tdrStyle->SetPadLeftMargin(0.16);
	tdrStyle->SetPadLeftMargin(0.14);
	// tdrStyle->SetPadRightMargin(0.02);
	tdrStyle->SetPadRightMargin(0.07);
	// tdrStyle->SetPadRightMargin(0.10); // only really want to be changing this for the scatters

	// For the Global title:
	tdrStyle->SetOptTitle(0);
	tdrStyle->SetTitleFont(42);
	tdrStyle->SetTitleColor(1);
	tdrStyle->SetTitleTextColor(1);
	tdrStyle->SetTitleFillColor(10);
	tdrStyle->SetTitleFontSize(0.05);
	// tdrStyle->SetTitleH(0); // Set the height of the title box
	// tdrStyle->SetTitleW(0); // Set the width of the title box
	// tdrStyle->SetTitleX(0); // Set the position of the title box
	// tdrStyle->SetTitleY(0.985); // Set the position of the title box
	// tdrStyle->SetTitleStyle(Style_t style = 1001);
	// tdrStyle->SetTitleBorderSize(2);

	// For the axis titles:
	tdrStyle->SetTitleColor(1, "XYZ");
	tdrStyle->SetTitleFont(42, "XYZ");
	tdrStyle->SetTitleSize(0.06, "XYZ");
	// tdrStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
	// tdrStyle->SetTitleYSize(Float_t size = 0.02);
	tdrStyle->SetTitleXOffset(0.95);//EDITFROM 0.9
	tdrStyle->SetTitleYOffset(1.25);
	// tdrStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

	// For the axis labels:
	tdrStyle->SetLabelColor(1, "XYZ");
	tdrStyle->SetLabelFont(42, "XYZ");
	tdrStyle->SetLabelOffset(0.007, "XYZ");
	// tdrStyle->SetLabelSize(0.05, "XYZ");
	tdrStyle->SetLabelSize(0.06, "XYZ");

	// For the axis:
	tdrStyle->SetAxisColor(1, "XYZ");
	tdrStyle->SetStripDecimals(kTRUE);
	tdrStyle->SetTickLength(0.03, "XYZ");
	tdrStyle->SetNdivisions(510, "XYZ");
	tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
	tdrStyle->SetPadTickY(1);

	// Change for log plots:
	tdrStyle->SetOptLogx(0);
	tdrStyle->SetOptLogy(0);
	tdrStyle->SetOptLogz(0);

	// Postscript options:
	tdrStyle->SetPaperSize(20.,20.);
	// tdrStyle->SetLineScalePS(Float_t scale = 3);
	// tdrStyle->SetLineStyleString(Int_t i, const char* text);
	// tdrStyle->SetHeaderPS(const char* header);
	// tdrStyle->SetTitlePS(const char* pstitle);

	// tdrStyle->SetBarOffset(Float_t baroff = 0.5);
	// tdrStyle->SetBarWidth(Float_t barwidth = 0.5);
	// tdrStyle->SetPaintTextFormat(const char* format = "g");
	// tdrStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
	// tdrStyle->SetTimeOffset(Double_t toffset);
	// tdrStyle->SetHistMinimumZero(kTRUE);

	//tdrStyle->cd();
	return tdrStyle;
}


