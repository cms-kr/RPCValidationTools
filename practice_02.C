#include <iostream>
#include <TH1F.h>
#include <TFile.h>
#include <TCanvas.h>

void practice_02()
{
	TCanvas TC1("TC1","TC1 title");
	TFile f1("../data/DQM_V0001_R000000001__RelValSingleMuPt100__CMSSW_10_6_0-106X_upgrade2018_realistic_v4-v1__DQMIO.root");
	TFile f2("../data/DQM_V0001_R000000001__RelValSingleMuPt100__CMSSW_11_0_0_pre2-106X_upgrade2018_realistic_v6-v1__DQMIO.root");
	TH1F*h1=(TH1F*)f1.Get("DQMData/Run 1/RPCDigisV/Run summary/RPCDigis/Bunch_Crossing");
	TH1F*h2=(TH1F*)f2.Get("DQMData/Run 1/RPCDigisV/Run summary/RPCDigis/Bunch_Crossing");
	h1->SetLineColor(kRed);
	h2->SetLineColor(kBlue);
	h1->Draw();
	h2->Draw("sames");
	gPad->Update();
	TPaveStats*st1=(TPaveStats*)h1->FindObject("stats");
	st1->SetY1NDC(0.8);
	st1->SetY2NDC(0.95);
	st1->SetTextColor(kRed);
	TPaveStats*st2=(TPaveStats*)h2->FindObject("stats");
	st2->SetY1NDC(0.65);
	st2->SetY2NDC(0.8);
	st2->SetTextColor(kBlue);
	TFile practice_02_file("practice_02_file.root","recreate");
	TC1.Write();
}
