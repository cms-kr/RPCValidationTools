void practice_03()
{
        TCanvas TC1("TC1","TC1 title");
        TC1.Divide(1,2);

        TFile f1("../data/DQM_V0001_R000000001__RelValSingleMuPt100__CMSSW_10_6_0-106X_upgrade2018_realistic_v4-v1__DQMIO.root");
        TFile f2("../data/DQM_V0001_R000000001__RelValSingleMuPt100__CMSSW_11_0_0_pre2-106X_upgrade2018_realistic_v6-v1__DQMIO.root");

        TH1F*h1=(TH1F*)f1.Get("DQMData/Run 1/RPCDigisV/Run summary/RPCDigis/Strip_Profile");
        TH1F*h2=(TH1F*)f2.Get("DQMData/Run 1/RPCDigisV/Run summary/RPCDigis/Strip_Profile");

        h1->SetLineColor(kRed);
        h2->SetLineColor(kBlue);

        TC1.cd(1);
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

        Int_t sum_abs=0;
        for(Int_t i=0;i<100;i++)
        {
                sum_abs+=abs((h1->GetBinContent(i))-(h2->GetBinContent(i)));
        }
        Float_t h2_entries=h2->GetEntries();
        Float_t diff=sum_abs/h2_entries;
        cout<<"sum_abs: "<<sum_abs<<endl;
        cout<<"diff: "<<diff<<endl;

        TH1F h3=(*h1)-(*h2);
        h3.SetLineColor(kBlack);

        TString TS_diff="";
        TS_diff+=diff;

        TC1.cd(2);
        h3.Draw();

        TPaveText*text = new TPaveText(0.8,0.8,1.0,1.0,"brNDC");
        text->AddText(Form("%.5e",diff));
        text->Draw();

        TFile practice_03_file("practice_03_file.root","recreate");
        TC1.Write();
}
