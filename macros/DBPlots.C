void DBPlots() {
	gROOT->Reset();
	gStyle->SetOptStat(0);
	gStyle->SetOptFit(111);
	gStyle->SetPalette(1);
	gStyle->SetOptDate(0);

	gStyle->SetCanvasColor(kWhite);
	gStyle->SetFrameFillStyle(1001);
	gStyle->SetFrameFillColor(kWhite);
	gStyle->SetPadBorderMode(0);
	gStyle->SetPadColor(kWhite);
	gStyle->SetStatColor(kWhite);
	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
	// gStyle->SetLabelSize(.05,"X");
	// gStyle->SetLabelSize(.05,"Y");
	gStyle->SetLabelColor(1,"X");
	gStyle->SetLabelColor(1,"Y");


	TH3D *h[3][3];
	TFile *f1 = new TFile("../input/DB_theta5_phi45.root");
	h[0][0] = (TH3D *) f1->Get("hPiXYvsP");
	h[0][1] = (TH3D *) f1->Get("hKaonXYvsP");
	h[0][2] = (TH3D *) f1->Get("hProtonXYvsP");

	TFile *f2 = new TFile("../input/DB_theta25_phi45.root");
	h[1][0] = (TH3D *) f2->Get("hPiXYvsP");
	h[1][1] = (TH3D *) f2->Get("hKaonXYvsP");
	h[1][2] = (TH3D *) f2->Get("hProtonXYvsP");

	TFile *f3 = new TFile("../input/DB_theta45_phi45.root");
	h[2][0] = (TH3D *) f3->Get("hPiXYvsP");
	h[2][1] = (TH3D *) f3->Get("hKaonXYvsP");
	h[2][2] = (TH3D *) f3->Get("hProtonXYvsP");

	char title[3][3][256]={ "#pi^{-}, shoot angle: #theta=5^{o}, #phi=45^{o}",
				"K^{-}, shoot angle: #theta=5^{o}, #phi=45^{o}", 
				"proton, shoot angle: #theta=5^{o}, #phi=45^{o}", 
				"#pi^{-}, shoot angle: #theta=25^{o}, #phi=45^{o}", 
				"K^{-}, shoot angle: #theta=25^{o}, #phi=45^{o}", 
				"proton, shoot angle: #theta=25^{o}, #phi=45^{o}", 
				"#pi^{-}, shoot angle: #theta=45^{o}, #phi=45^{o}", 
				"K^{-}, shoot angle: #theta=45^{o}, #phi=45^{o}", 
				"proton, shoot angle: #theta=45^{o}, #phi=45^{o}" };

	TCanvas *c1 = new TCanvas("c1","c1",2210,1500);
	c1->Divide(3,3);

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			int index = 3*i+j+1;
			c1->cd(index);
			gPad->SetTopMargin(0.12);
			gPad->SetBottomMargin(0.12);
			gPad->SetLeftMargin(0.12);
			gPad->SetRightMargin(0.12);

			h[i][j]->GetXaxis()->SetTitle("X (mm)");
			h[i][j]->GetYaxis()->SetTitle("Y (mm)");
			h[i][j]->GetZaxis()->SetTitle("Momentum (GeV/c)");
			h[i][j]->GetYaxis()->SetTitleColor(kBlack);
			h[i][j]->GetZaxis()->SetTitleSize(0.04);
			h[i][j]->GetYaxis()->SetTitleSize(0.04);
			h[i][j]->GetXaxis()->SetTitleSize(0.035);
			h[i][j]->GetZaxis()->SetTitleOffset(1.7);
			h[i][j]->GetYaxis()->SetTitleOffset(1.7);
			h[i][j]->GetXaxis()->SetTitleOffset(1.7);
			h[i][j]->SetTitle("");
			h[i][j]->Draw("");

			TLegend *leg = new TLegend(0.15,0.9,0.8,0.95);
			leg->SetTextSize(0.055);
			leg->SetLineColor(4);
			leg->SetLineStyle(1);
			leg->SetLineWidth(1);
			leg->SetFillColor(0);
			leg->SetMargin(0.1);
			leg->SetFillStyle(0);
			leg->SetTextAlign(12);
			leg->SetBorderSize(0);
			leg->AddEntry(h[i][j],title[i][j],"");
			leg->Draw();
		}
	}

	c1->cd();
	c1->SaveAs("figs/DBPlots.png");
}
