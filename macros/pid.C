void pid() {
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


	TH2D *hPID5[3][3];
	TH2D *hPID25[3][3];
	TH2D *hPID45[3][3];
	TFile *f = new TFile("./LogLikelihood.root");
	/////// theta = 5 degree
	hPID5[0][0] = (TH2D *) f->Get("hPIDPiPivsPTheta5");
	hPID5[0][1] = (TH2D *) f->Get("hPIDPiKvsPTheta5");
	hPID5[0][2] = (TH2D *) f->Get("hPIDPiPvsPTheta5");
	hPID5[1][0] = (TH2D *) f->Get("hPIDKPivsPTheta5");
	hPID5[1][1] = (TH2D *) f->Get("hPIDKKvsPTheta5");
	hPID5[1][2] = (TH2D *) f->Get("hPIDKPvsPTheta5");
	hPID5[2][0] = (TH2D *) f->Get("hPIDPPivsPTheta5");
	hPID5[2][1] = (TH2D *) f->Get("hPIDPKvsPTheta5");
	hPID5[2][2] = (TH2D *) f->Get("hPIDPPvsPTheta5");

	/////// theta = 25 degree
	hPID25[0][0] = (TH2D *) f->Get("hPIDPiPivsPTheta25");
	hPID25[0][1] = (TH2D *) f->Get("hPIDPiKvsPTheta25");
	hPID25[0][2] = (TH2D *) f->Get("hPIDPiPvsPTheta25");
	hPID25[1][0] = (TH2D *) f->Get("hPIDKPivsPTheta25");
	hPID25[1][1] = (TH2D *) f->Get("hPIDKKvsPTheta25");
	hPID25[1][2] = (TH2D *) f->Get("hPIDKPvsPTheta25");
	hPID25[2][0] = (TH2D *) f->Get("hPIDPPivsPTheta25");
	hPID25[2][1] = (TH2D *) f->Get("hPIDPKvsPTheta25");
	hPID25[2][2] = (TH2D *) f->Get("hPIDPPvsPTheta25");

	/////// theta = 45 degree
	hPID45[0][0] = (TH2D *) f->Get("hPIDPiPivsPTheta45");
	hPID45[0][1] = (TH2D *) f->Get("hPIDPiKvsPTheta45");
	hPID45[0][2] = (TH2D *) f->Get("hPIDPiPvsPTheta45");
	hPID45[1][0] = (TH2D *) f->Get("hPIDKPivsPTheta45");
	hPID45[1][1] = (TH2D *) f->Get("hPIDKKvsPTheta45");
	hPID45[1][2] = (TH2D *) f->Get("hPIDKPvsPTheta45");
	hPID45[2][0] = (TH2D *) f->Get("hPIDPPivsPTheta45");
	hPID45[2][1] = (TH2D *) f->Get("hPIDPKvsPTheta45");
	hPID45[2][2] = (TH2D *) f->Get("hPIDPPvsPTheta45");

	char title5[3][256]={ "#pi^{-}, shoot angle: #theta=5^{o}, #phi=45^{o}",
				"K^{-}, shoot angle: #theta=5^{o}, #phi=45^{o}", 
				"proton, shoot angle: #theta=5^{o}, #phi=45^{o}"};

	char title25[3][256]={	"#pi^{-}, shoot angle: #theta=25^{o}, #phi=45^{o}", 
				"K^{-}, shoot angle: #theta=25^{o}, #phi=45^{o}", 
				"proton, shoot angle: #theta=25^{o}, #phi=45^{o}"};

	char title45[3][256]={ "#pi^{-}, shoot angle: #theta=45^{o}, #phi=45^{o}", 
				"K^{-}, shoot angle: #theta=45^{o}, #phi=45^{o}", 
				"proton, shoot angle: #theta=45^{o}, #phi=45^{o}" };

	char title[3][3][256]={ "    #pi^{-} #rightarrow #pi^{-}", "    #pi^{-} #rightarrow K^{-}", "    #pi^{-} #rightarrow proton",
			       "    K^{-} #rightarrow #pi^{-}", "    K^{-} #rightarrow K^{-}", "    K^{-} #rightarrow proton",
			       "    proton #rightarrow #pi^{-}", "    proton #rightarrow K^{-}", "    proton #rightarrow proton" };

	TLine *line = new TLine(2.5,0.,15.5,0);

	TCanvas *c1 = new TCanvas("c1","c1",2100,500);
	c1->Divide(3,1);

	///////// theta = 5
	for(int i=0; i<3; i++){
		c1->cd(i+1);
		gPad->SetTopMargin(0.12);
		gPad->SetBottomMargin(0.12);
		gPad->SetLeftMargin(0.12);
		gPad->SetRightMargin(0.12);

		hPID5[i][0]->GetYaxis()->SetRangeUser(0.,1.);
		hPID5[i][0]->GetXaxis()->SetTitle("Momentum (GeV/c)");
		hPID5[i][0]->GetYaxis()->SetTitle("particle identification efficiency");
		hPID5[i][0]->GetYaxis()->SetTitleColor(kBlack);
		hPID5[i][0]->GetYaxis()->SetTitleSize(0.055);
		hPID5[i][0]->GetXaxis()->SetTitleSize(0.055);
		hPID5[i][0]->GetYaxis()->SetTitleOffset(1.1);
		hPID5[i][0]->GetXaxis()->SetTitleOffset(1.1);
		hPID5[i][0]->SetTitle("");
		if(i==0) {
			hPID5[i][0]->SetMarkerColor(kBlack);
			hPID5[i][1]->SetMarkerColor(kBlue);
			hPID5[i][2]->SetMarkerColor(kRed);
		}
		else if(i==1) {
			hPID5[i][1]->SetMarkerColor(kBlack);
			hPID5[i][0]->SetMarkerColor(kBlue);
			hPID5[i][2]->SetMarkerColor(kRed);
		}
		else if(i==2) {
			hPID5[i][2]->SetMarkerColor(kBlack);
			hPID5[i][1]->SetMarkerColor(kBlue);
			hPID5[i][0]->SetMarkerColor(kRed);
		}
		hPID5[i][0]->SetMarkerStyle(20);
		hPID5[i][0]->SetMarkerSize(1.2);
		hPID5[i][0]->Draw("");
		hPID5[i][1]->SetMarkerStyle(22);
		hPID5[i][1]->SetMarkerSize(1.2);
		hPID5[i][1]->Draw("SAME");
		hPID5[i][2]->SetMarkerStyle(23);
		hPID5[i][2]->SetMarkerSize(1.2);
		hPID5[i][2]->Draw("SAME");
		line->Draw();

		TLegend *leg;
		if(i==0 || i==1) leg = new TLegend(0.55,0.65,0.75,0.85);
		else if(i==2) leg = new TLegend(0.2,0.4,0.5,0.6);
		leg->SetTextSize(0.055);
		leg->SetLineColor(4);
		leg->SetLineStyle(1);
		leg->SetLineWidth(1);
		leg->SetFillColor(0);
		leg->SetMargin(0.1);
		leg->SetFillStyle(0);
		leg->SetTextAlign(12);
		leg->SetBorderSize(0);
		leg->AddEntry(hPID5[i][0],title[i][0],"pl");
		leg->AddEntry(hPID5[i][1],title[i][1],"pl");
		leg->AddEntry(hPID5[i][2],title[i][2],"pl");
		leg->Draw();
	}
	c1->cd();
	c1->SaveAs("figs/PIDTheta5.pdf");

	///////// theta = 25
	for(int i=0; i<3; i++){
		c1->cd(i+1);
		gPad->SetTopMargin(0.12);
		gPad->SetBottomMargin(0.12);
		gPad->SetLeftMargin(0.12);
		gPad->SetRightMargin(0.12);

		hPID25[i][0]->GetYaxis()->SetRangeUser(0.,1.);
		hPID25[i][0]->GetXaxis()->SetTitle("Momentum (GeV/c)");
		hPID25[i][0]->GetYaxis()->SetTitle("particle identification efficiency");
		hPID25[i][0]->GetYaxis()->SetTitleColor(kBlack);
		hPID25[i][0]->GetYaxis()->SetTitleSize(0.055);
		hPID25[i][0]->GetXaxis()->SetTitleSize(0.055);
		hPID25[i][0]->GetYaxis()->SetTitleOffset(1.1);
		hPID25[i][0]->GetXaxis()->SetTitleOffset(1.1);
		hPID25[i][0]->SetTitle("");
		if(i==0) {
			hPID25[i][0]->SetMarkerColor(kBlack);
			hPID25[i][1]->SetMarkerColor(kBlue);
			hPID25[i][2]->SetMarkerColor(kRed);
		}
		else if(i==1) {
			hPID25[i][1]->SetMarkerColor(kBlack);
			hPID25[i][0]->SetMarkerColor(kBlue);
			hPID25[i][2]->SetMarkerColor(kRed);
		}
		else if(i==2) {
			hPID25[i][2]->SetMarkerColor(kBlack);
			hPID25[i][1]->SetMarkerColor(kBlue);
			hPID25[i][0]->SetMarkerColor(kRed);
		}
		hPID25[i][0]->SetMarkerStyle(20);
		hPID25[i][0]->SetMarkerSize(1.2);
		hPID25[i][0]->Draw("");
		hPID25[i][1]->SetMarkerStyle(22);
		hPID25[i][1]->SetMarkerSize(1.2);
		hPID25[i][1]->Draw("SAME");
		hPID25[i][2]->SetMarkerStyle(23);
		hPID25[i][2]->SetMarkerSize(1.2);
		hPID25[i][2]->Draw("SAME");
		line->Draw();

		TLegend *leg;
                if(i==0 || i==1) leg = new TLegend(0.55,0.65,0.75,0.85);
                else if(i==2) leg = new TLegend(0.2,0.4,0.5,0.6);
		leg->SetTextSize(0.055);
		leg->SetLineColor(4);
		leg->SetLineStyle(1);
		leg->SetLineWidth(1);
		leg->SetFillColor(0);
		leg->SetMargin(0.1);
		leg->SetFillStyle(0);
		leg->SetTextAlign(12);
		leg->SetBorderSize(0);
		leg->AddEntry(hPID25[i][0],title[i][0],"pl");
		leg->AddEntry(hPID25[i][1],title[i][1],"pl");
		leg->AddEntry(hPID25[i][2],title[i][2],"pl");
		leg->Draw();
	}
	c1->cd();
	c1->SaveAs("figs/PIDTheta25.pdf");

	///////// theta = 45
	for(int i=0; i<3; i++){
		c1->cd(i+1);
		gPad->SetTopMargin(0.12);
		gPad->SetBottomMargin(0.12);
		gPad->SetLeftMargin(0.12);
		gPad->SetRightMargin(0.12);

		hPID45[i][0]->GetYaxis()->SetRangeUser(0.,1.);
		hPID45[i][0]->GetXaxis()->SetTitle("Momentum (GeV/c)");
		hPID45[i][0]->GetYaxis()->SetTitle("particle identification efficiency");
		hPID45[i][0]->GetYaxis()->SetTitleColor(kBlack);
		hPID45[i][0]->GetYaxis()->SetTitleSize(0.055);
		hPID45[i][0]->GetXaxis()->SetTitleSize(0.055);
		hPID45[i][0]->GetYaxis()->SetTitleOffset(1.1);
		hPID45[i][0]->GetXaxis()->SetTitleOffset(1.1);
		hPID45[i][0]->SetTitle("");
		if(i==0) {
			hPID45[i][0]->SetMarkerColor(kBlack);
			hPID45[i][1]->SetMarkerColor(kBlue);
			hPID45[i][2]->SetMarkerColor(kRed);
		}
		else if(i==1) {
			hPID45[i][1]->SetMarkerColor(kBlack);
			hPID45[i][0]->SetMarkerColor(kBlue);
			hPID45[i][2]->SetMarkerColor(kRed);
		}
		else if(i==2) {
			hPID45[i][2]->SetMarkerColor(kBlack);
			hPID45[i][1]->SetMarkerColor(kBlue);
			hPID45[i][0]->SetMarkerColor(kRed);
		}
		hPID45[i][0]->SetMarkerStyle(20);
		hPID45[i][0]->SetMarkerSize(1.2);
		hPID45[i][0]->Draw("");
		hPID45[i][1]->SetMarkerStyle(22);
		hPID45[i][1]->SetMarkerSize(1.2);
		hPID45[i][1]->Draw("SAME");
		hPID45[i][2]->SetMarkerStyle(23);
		hPID45[i][2]->SetMarkerSize(1.2);
		hPID45[i][2]->Draw("SAME");
		line->Draw();

		TLegend *leg;
                if(i==0 || i==1) leg = new TLegend(0.55,0.65,0.75,0.85);
                else if(i==2) leg = new TLegend(0.2,0.4,0.5,0.6);
		leg->SetTextSize(0.055);
		leg->SetLineColor(4);
		leg->SetLineStyle(1);
		leg->SetLineWidth(1);
		leg->SetFillColor(0);
		leg->SetMargin(0.1);
		leg->SetFillStyle(0);
		leg->SetTextAlign(12);
		leg->SetBorderSize(0);
		leg->AddEntry(hPID45[i][0],title[i][0],"pl");
		leg->AddEntry(hPID45[i][1],title[i][1],"pl");
		leg->AddEntry(hPID45[i][2],title[i][2],"pl");
		leg->Draw();
	}
	c1->cd();
	c1->SaveAs("figs/PIDTheta45.pdf");

}
