void prob() {
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


	TH2D *hL5[3][2], *hL25[3][2], *hL45[3][2];
	TFile *f = new TFile("./LogLikelihood.root");
	/////// theta = 5 degree
	hL5[0][0] = (TH2D *) f->Get("hLPiKaonvsPTheta5");
	hL5[0][1] = (TH2D *) f->Get("hLPiProtonvsPTheta5");
	hL5[1][0] = (TH2D *) f->Get("hLKaonPivsPTheta5");
	hL5[1][1] = (TH2D *) f->Get("hLKaonProtonvsPTheta5");
	hL5[2][0] = (TH2D *) f->Get("hLProtonPivsPTheta5");
	hL5[2][1] = (TH2D *) f->Get("hLProtonKaonvsPTheta5");

	/////// theta = 25 degree
	hL25[0][0] = (TH2D *) f->Get("hLPiKaonvsPTheta25");
	hL25[0][1] = (TH2D *) f->Get("hLPiProtonvsPTheta25");
	hL25[1][0] = (TH2D *) f->Get("hLKaonPivsPTheta25");
	hL25[1][1] = (TH2D *) f->Get("hLKaonProtonvsPTheta25");
	hL25[2][0] = (TH2D *) f->Get("hLProtonPivsPTheta25");
	hL25[2][1] = (TH2D *) f->Get("hLProtonKaonvsPTheta25");

	/////// theta = 45 degree
	hL45[0][0] = (TH2D *) f->Get("hLPiKaonvsPTheta45");
	hL45[0][1] = (TH2D *) f->Get("hLPiProtonvsPTheta45");
	hL45[1][0] = (TH2D *) f->Get("hLKaonPivsPTheta45");
	hL45[1][1] = (TH2D *) f->Get("hLKaonProtonvsPTheta45");
	hL45[2][0] = (TH2D *) f->Get("hLProtonPivsPTheta45");
	hL45[2][1] = (TH2D *) f->Get("hLProtonKaonvsPTheta45");

	char title5[3][256]={ "#pi^{-}, shoot angle: #theta=5^{o}, #phi=45^{o}",
				"K^{-}, shoot angle: #theta=5^{o}, #phi=45^{o}", 
				"proton, shoot angle: #theta=5^{o}, #phi=45^{o}"};

	char title25[3][256]={	"#pi^{-}, shoot angle: #theta=25^{o}, #phi=45^{o}", 
				"K^{-}, shoot angle: #theta=25^{o}, #phi=45^{o}", 
				"proton, shoot angle: #theta=25^{o}, #phi=45^{o}"};

	char title45[3][256]={ "#pi^{-}, shoot angle: #theta=45^{o}, #phi=45^{o}", 
				"K^{-}, shoot angle: #theta=45^{o}, #phi=45^{o}", 
				"proton, shoot angle: #theta=45^{o}, #phi=45^{o}" };

	char ytitle[3][2][256]={ "log(#pi^{-}) - log(K^{-})", "log(#pi^{-}) - log(proton)",
				 "log(K^{-}) - log(#pi^{-})", "log(K^{-}) - log(proton)",
				 "log(proton) - log(#pi^{-})", "log(proton}) - log(K^{-})" };

	TLine *line = new TLine(2.5,0.,15.5,0);

	TCanvas *c1 = new TCanvas("c1","c1",2100,1000);
	c1->Divide(3,2);

	///////// theta = 5
	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			int index = 0;
			if(i==0 && j==0) index=1;
			if(i==0 && j==1) index=4;
			if(i==1 && j==0) index=2;
			if(i==1 && j==1) index=5;
			if(i==2 && j==0) index=3;
			if(i==2 && j==1) index=6;
			c1->cd(index);
			gPad->SetTopMargin(0.12);
			gPad->SetBottomMargin(0.12);
			gPad->SetLeftMargin(0.12);
			gPad->SetRightMargin(0.12);

			hL5[i][j]->GetYaxis()->SetRangeUser(-20.,80.);
			hL5[i][j]->GetXaxis()->SetTitle("Momentum (GeV/c)");
			hL5[i][j]->GetYaxis()->SetTitle(ytitle[i][j]);
			hL5[i][j]->GetYaxis()->SetTitleColor(kBlack);
			hL5[i][j]->GetYaxis()->SetTitleSize(0.055);
			hL5[i][j]->GetXaxis()->SetTitleSize(0.055);
			hL5[i][j]->GetYaxis()->SetTitleOffset(1.1);
			hL5[i][j]->GetXaxis()->SetTitleOffset(1.1);
			hL5[i][j]->SetTitle("");
			hL5[i][j]->Draw("colz");
			line->Draw();

			TLegend *leg = new TLegend(0.2,0.9,0.8,0.95);
			leg->SetTextSize(0.055);
			leg->SetLineColor(4);
			leg->SetLineStyle(1);
			leg->SetLineWidth(1);
			leg->SetFillColor(0);
			leg->SetMargin(0.1);
			leg->SetFillStyle(0);
			leg->SetTextAlign(12);
			leg->SetBorderSize(0);
			leg->AddEntry(hL5[i][j],title5[i],"");
			leg->Draw();
		}
	}
	c1->cd();
	c1->SaveAs("figs/ProbTheta5.pdf");


	///////// theta = 25
	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			int index = 0;
			if(i==0 && j==0) index=1;
			if(i==0 && j==1) index=4;
			if(i==1 && j==0) index=2;
			if(i==1 && j==1) index=5;
			if(i==2 && j==0) index=3;
			if(i==2 && j==1) index=6;
			c1->cd(index);
			gPad->SetTopMargin(0.12);
			gPad->SetBottomMargin(0.12);
			gPad->SetLeftMargin(0.12);
			gPad->SetRightMargin(0.12);

			hL25[i][j]->GetYaxis()->SetRangeUser(-20.,80.);
			hL25[i][j]->GetXaxis()->SetTitle("Momentum (GeV/c)");
			hL25[i][j]->GetYaxis()->SetTitle(ytitle[i][j]);
			hL25[i][j]->GetYaxis()->SetTitleColor(kBlack);
			hL25[i][j]->GetYaxis()->SetTitleSize(0.055);
			hL25[i][j]->GetXaxis()->SetTitleSize(0.055);
			hL25[i][j]->GetYaxis()->SetTitleOffset(1.1);
			hL25[i][j]->GetXaxis()->SetTitleOffset(1.1);
			hL25[i][j]->SetTitle("");
			hL25[i][j]->Draw("colz");
			line->Draw();

			TLegend *leg = new TLegend(0.2,0.9,0.8,0.95);
			leg->SetTextSize(0.055);
			leg->SetLineColor(4);
			leg->SetLineStyle(1);
			leg->SetLineWidth(1);
			leg->SetFillColor(0);
			leg->SetMargin(0.1);
			leg->SetFillStyle(0);
			leg->SetTextAlign(12);
			leg->SetBorderSize(0);
			leg->AddEntry(hL25[i][j],title25[i],"");
			leg->Draw();
		}
	}
	c1->cd();
	c1->SaveAs("figs/ProbTheta25.pdf");


	///////// theta = 45
	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			int index = 0;
			if(i==0 && j==0) index=1;
			if(i==0 && j==1) index=4;
			if(i==1 && j==0) index=2;
			if(i==1 && j==1) index=5;
			if(i==2 && j==0) index=3;
			if(i==2 && j==1) index=6;
			c1->cd(index);
			gPad->SetTopMargin(0.12);
			gPad->SetBottomMargin(0.12);
			gPad->SetLeftMargin(0.12);
			gPad->SetRightMargin(0.12);

			hL45[i][j]->GetYaxis()->SetRangeUser(-20.,80.);
			hL45[i][j]->GetXaxis()->SetTitle("Momentum (GeV/c)");
			hL45[i][j]->GetYaxis()->SetTitle(ytitle[i][j]);
			hL45[i][j]->GetYaxis()->SetTitleColor(kBlack);
			hL45[i][j]->GetYaxis()->SetTitleSize(0.055);
			hL45[i][j]->GetXaxis()->SetTitleSize(0.055);
			hL45[i][j]->GetYaxis()->SetTitleOffset(1.1);
			hL45[i][j]->GetXaxis()->SetTitleOffset(1.1);
			hL45[i][j]->SetTitle("");
			hL45[i][j]->Draw("colz");
			line->Draw();

			TLegend *leg = new TLegend(0.2,0.9,0.8,0.95);
			leg->SetTextSize(0.055);
			leg->SetLineColor(4);
			leg->SetLineStyle(1);
			leg->SetLineWidth(1);
			leg->SetFillColor(0);
			leg->SetMargin(0.1);
			leg->SetFillStyle(0);
			leg->SetTextAlign(12);
			leg->SetBorderSize(0);
			leg->AddEntry(hL45[i][j],title45[i],"");
			leg->Draw();
		}
	}
	c1->cd();
	c1->SaveAs("figs/ProbTheta45.pdf");
}
