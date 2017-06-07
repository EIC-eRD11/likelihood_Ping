void LPion() {
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


	TCanvas *c1 = new TCanvas("c1","c1",700,500);
	c1->SetTopMargin(0.12);
	c1->SetBottomMargin(0.12);
	c1->SetLeftMargin(0.12);
	c1->SetRightMargin(0.12);

	TFile *f = new TFile("./LogLikelihood.root");
	TH1D *hLPion = (TH1D *) f->Get("hLPion");
	hLPion->GetXaxis()->SetTitle("log(prob(#pi^{-} #rightarrow #pi^{-}))");
	hLPion->GetYaxis()->SetTitle("Counts");
	hLPion->GetYaxis()->SetTitleSize(0.04);
	hLPion->GetXaxis()->SetTitleSize(0.04);
	hLPion->GetXaxis()->SetTitleOffset(1.2);
	hLPion->GetYaxis()->SetTitleOffset(1.2);
	hLPion->SetTitle("");
	hLPion->Draw("");

	c1->cd();
	c1->SaveAs("figs/Prob.pdf");
}
