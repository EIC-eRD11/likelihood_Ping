void Analysis(const char *inputF="../output/G4_data_all.root") {
  gROOT->Reset();
  gStyle->SetOptStat(111);
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
  
  Int_t           pid;
  Float_t         px;
  Float_t         py;
  Float_t         pz;
  Float_t         vx;
  Float_t         vy;
  Float_t         vz;
  Float_t         theta;
  Float_t         phi;
  Int_t           nhit;
  Int_t           nhitAegl;
  Int_t           nhitPhoDet;
  Int_t           nelSbKCs;
  Int_t           nelGaAsP;
  Int_t           nelGaAs;
  Double_t        Lpion;
  Double_t        LKaon;
  Double_t        Lproton;
  
  TChain *fchain  = new TChain("LLTreeDst");
  fchain->Add(inputF);
  fchain->SetMakeClass(1);
  fchain->SetBranchAddress("pid", &pid);
  fchain->SetBranchAddress("px", &px);
  fchain->SetBranchAddress("py", &py);
  fchain->SetBranchAddress("pz", &pz);
  fchain->SetBranchAddress("vx", &vx);
  fchain->SetBranchAddress("vy", &vy);
  fchain->SetBranchAddress("vz", &vz);
  fchain->SetBranchAddress("theta", &theta);
  fchain->SetBranchAddress("phi", &phi);
  fchain->SetBranchAddress("nhit", &nhit);
  fchain->SetBranchAddress("nhitAegl", &nhitAegl);
  fchain->SetBranchAddress("nhitPhoDet", &nhitPhoDet);
  fchain->SetBranchAddress("nelSbKCs", &nelSbKCs);
  fchain->SetBranchAddress("nelGaAsP", &nelGaAsP);
  fchain->SetBranchAddress("nelGaAs", &nelGaAs);
  fchain->SetBranchAddress("Lpion", &Lpion);
  fchain->SetBranchAddress("LKaon", &LKaon);
  fchain->SetBranchAddress("Lproton", &Lproton);
  
  TH1D *hLPion = new TH1D("hLPion","hLPion",200,-200.,0.);
  
  ///////// for pi- with theta=5:  log (pi-) - log(K-), and log (pi-) - log(proton)
  ///////// for K- with theta=5:  log (K-) - log(pi-), and log (K-) - log(proton)
  ///////// for proton with theta=5:  log (proton) - log(pi-), and log (proton) - log(K)
  TH2D *hLPiKaonvsPTheta5 = new TH2D("hLPiKaonvsPTheta5","hLPiKaonvsPTheta5",65,2.5,15.5,150,-20.,130.);
  TH2D *hLPiProtonvsPTheta5 = new TH2D("hLPiProtonvsPTheta5","hLPiProtonvsPTheta5",65,2.5,15.5,150,-20.,130.);
  TH2D *hLKaonPivsPTheta5 = new TH2D("hLKaonPivsPTheta5","hLKaonPivsPTheta5",65,2.5,15.5,150,-20.,130.);
  TH2D *hLKaonProtonvsPTheta5 = new TH2D("hLKaonProtonvsPTheta5","hLKaonProtonvsPTheta5",65,2.5,15.5,150,-20.,130.);
  TH2D *hLProtonPivsPTheta5 = new TH2D("hLProtonPivsPTheta5","hLProtonPivsPTheta5",65,2.5,15.5,150,-20.,130.);
  TH2D *hLProtonKaonvsPTheta5 = new TH2D("hLProtonKaonvsPTheta5","hLProtonKaonvsPTheta5",65,2.5,15.5,150,-20.,130.);
  
  ///////// for pi- with theta=25:  log (pi-) - log(K-), and log (pi-) - log(proton)
  ///////// for K- with theta=25:  log (K-) - log(pi-), and log (K-) - log(proton)
  ///////// for proton with theta=25:  log (proton) - log(pi-), and log (proton) - log(K)
  TH2D *hLPiKaonvsPTheta25 = new TH2D("hLPiKaonvsPTheta25","hLPiKaonvsPTheta25",65,2.5,15.5,150,-20.,130.);
  TH2D *hLPiProtonvsPTheta25 = new TH2D("hLPiProtonvsPTheta25","hLPiProtonvsPTheta25",65,2.5,15.5,150,-20.,130.);
  TH2D *hLKaonPivsPTheta25 = new TH2D("hLKaonPivsPTheta25","hLKaonPivsPTheta25",65,2.5,15.5,150,-20.,130.);
  TH2D *hLKaonProtonvsPTheta25 = new TH2D("hLKaonProtonvsPTheta25","hLKaonProtonvsPTheta25",65,2.5,15.5,150,-20.,130.);
  TH2D *hLProtonPivsPTheta25 = new TH2D("hLProtonPivsPTheta25","hLProtonPivsPTheta25",65,2.5,15.5,150,-20.,130.);
  TH2D *hLProtonKaonvsPTheta25 = new TH2D("hLProtonKaonvsPTheta25","hLProtonKaonvsPTheta25",65,2.5,15.5,150,-20.,130.);
  
  ///////// for pi- with theta=45:  log (pi-) - log(K-), and log (pi-) - log(proton)
  ///////// for K- with theta=45:  log (K-) - log(pi-), and log (K-) - log(proton)
  ///////// for proton with theta=45:  log (proton) - log(pi-), and log (proton) - log(K)
  TH2D *hLPiKaonvsPTheta45 = new TH2D("hLPiKaonvsPTheta45","hLPiKaonvsPTheta45",65,2.5,15.5,150,-20.,130.);
  TH2D *hLPiProtonvsPTheta45 = new TH2D("hLPiProtonvsPTheta45","hLPiProtonvsPTheta45",65,2.5,15.5,150,-20.,130.);
  TH2D *hLKaonPivsPTheta45 = new TH2D("hLKaonPivsPTheta45","hLKaonPivsPTheta45",65,2.5,15.5,150,-20.,130.);
  TH2D *hLKaonProtonvsPTheta45 = new TH2D("hLKaonProtonvsPTheta45","hLKaonProtonvsPTheta45",65,2.5,15.5,150,-20.,130.);
  TH2D *hLProtonPivsPTheta45 = new TH2D("hLProtonPivsPTheta45","hLProtonPivsPTheta45",65,2.5,15.5,150,-20.,130.);
  TH2D *hLProtonKaonvsPTheta45 = new TH2D("hLProtonKaonvsPTheta45","hLProtonKaonvsPTheta45",65,2.5,15.5,150,-20.,130.);
  
  
  ///////// for pi-, K, proton with theta=5; calculate PID efficiency, misPID
  TH2D *hPIDPiPivsPTheta5 = new TH2D("hPIDPiPivsPTheta5","hPIDPiPivsPTheta5",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPiKvsPTheta5 = new TH2D("hPIDPiKvsPTheta5","hPIDPiKvsPTheta5",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPiPvsPTheta5 = new TH2D("hPIDPiPvsPTheta5","hPIDPiPvsPTheta5",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDKPivsPTheta5 = new TH2D("hPIDKPivsPTheta5","hPIDKPivsPTheta5",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDKKvsPTheta5 = new TH2D("hPIDKKvsPTheta5","hPIDKKvsPTheta5",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDKPvsPTheta5 = new TH2D("hPIDKPvsPTheta5","hPIDKPvsPTheta5",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPPivsPTheta5 = new TH2D("hPIDPPivsPTheta5","hPIDPPivsPTheta5",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPKvsPTheta5 = new TH2D("hPIDPKvsPTheta5","hPIDPKvsPTheta5",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPPvsPTheta5 = new TH2D("hPIDPPvsPTheta5","hPIDPPvsPTheta5",65,2.5,15.5,120,0.,1.2);
  
  ///////// for pi-, K, proton with theta=25; calculate PID efficiency, misPID
  TH2D *hPIDPiPivsPTheta25 = new TH2D("hPIDPiPivsPTheta25","hPIDPiPivsPTheta25",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPiKvsPTheta25 = new TH2D("hPIDPiKvsPTheta25","hPIDPiKvsPTheta25",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPiPvsPTheta25 = new TH2D("hPIDPiPvsPTheta25","hPIDPiPvsPTheta25",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDKPivsPTheta25 = new TH2D("hPIDKPivsPTheta25","hPIDKPivsPTheta25",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDKKvsPTheta25 = new TH2D("hPIDKKvsPTheta25","hPIDKKvsPTheta25",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDKPvsPTheta25 = new TH2D("hPIDKPvsPTheta25","hPIDKPvsPTheta25",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPPivsPTheta25 = new TH2D("hPIDPPivsPTheta25","hPIDPPivsPTheta25",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPKvsPTheta25 = new TH2D("hPIDPKvsPTheta25","hPIDPKvsPTheta25",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPPvsPTheta25 = new TH2D("hPIDPPvsPTheta25","hPIDPPvsPTheta25",65,2.5,15.5,120,0.,1.2);
  
  ///////// for pi-, K, proton with theta=45; calculate PID efficiency, misPID
  TH2D *hPIDPiPivsPTheta45 = new TH2D("hPIDPiPivsPTheta45","hPIDPiPivsPTheta45",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPiKvsPTheta45 = new TH2D("hPIDPiKvsPTheta45","hPIDPiKvsPTheta45",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPiPvsPTheta45 = new TH2D("hPIDPiPvsPTheta45","hPIDPiPvsPTheta45",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDKPivsPTheta45 = new TH2D("hPIDKPivsPTheta45","hPIDKPivsPTheta45",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDKKvsPTheta45 = new TH2D("hPIDKKvsPTheta45","hPIDKKvsPTheta45",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDKPvsPTheta45 = new TH2D("hPIDKPvsPTheta45","hPIDKPvsPTheta45",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPPivsPTheta45 = new TH2D("hPIDPPivsPTheta45","hPIDPPivsPTheta45",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPKvsPTheta45 = new TH2D("hPIDPKvsPTheta45","hPIDPKvsPTheta45",65,2.5,15.5,120,0.,1.2);
  TH2D *hPIDPPvsPTheta45 = new TH2D("hPIDPPvsPTheta45","hPIDPPvsPTheta45",65,2.5,15.5,120,0.,1.2);
  
  double ptot[61]={ 3.0, 3.2, 3.4, 3.6, 3.8, 4.0, 4.2, 4.4, 4.6, 4.8,
		    5.0, 5.2, 5.4, 5.6, 5.8, 6.0, 6.2, 6.4, 6.6, 6.8,
		    7.0, 7.2, 7.4, 7.6, 7.8, 8.0, 8.2, 8.4, 8.6, 8.8,
		    9.0, 9.2, 9.4, 9.6, 9.8, 10.0, 10.2, 10.4, 10.6, 10.8,
		    11.0, 11.2, 11.4, 11.6, 11.8, 12.0, 12.2, 12.4, 12.6 12.8,
		    13.0, 13.2, 13.4, 13.6, 13.8, 14.0, 14.2, 14.4, 14.6, 14.8, 15.0 };
  
  /////// calculate PID fractions for theta=5 vs. ptot
  double theta5pipi[61];
  double theta5piK[61];
  double theta5pip[61];
  double theta5Kpi[61];
  double theta5KK[61];
  double theta5Kp[61];
  double theta5ppi[61];
  double theta5pK[61];
  double theta5pp[61];
  
  /////// calculate PID fractions for theta=25 vs. ptot
  double theta25pipi[61];
  double theta25piK[61];
  double theta25pip[61];
  double theta25Kpi[61];
  double theta25KK[61];
  double theta25Kp[61];
  double theta25ppi[61];
  double theta25pK[61];
  double theta25pp[61];
  
  /////// calculate PID fractions for theta=25 vs. ptot
  double theta45pipi[61];
  double theta45piK[61];
  double theta45pip[61];
  double theta45Kpi[61];
  double theta45KK[61];
  double theta45Kp[61];
  double theta45ppi[61];
  double theta45pK[61];
  double theta45pp[61];
  
  Int_t nEvents = fchain->GetEntries();
  for(int i=0;i<nEvents; i++){
    if(i%1000==0) cout<<"====== Processing "<< i <<" evnets; ====="<< endl;
    
    fchain->GetEntry(i);
    double mom = sqrt(px*px+py*py+pz*pz);
    
    if(fabs(theta-5)<0.1){
      if(pid==-211){
	hLPion->Fill(Lpion);
	hLPiKaonvsPTheta5->Fill(mom, Lpion-LKaon);
	hLPiProtonvsPTheta5->Fill(mom, Lpion-Lproton);
      }
      else if(pid==-321){
	hLKaonPivsPTheta5->Fill(mom, LKaon-Lpion);
	hLKaonProtonvsPTheta5->Fill(mom, LKaon-Lproton);
      }
      else if(pid==2212){
	hLProtonPivsPTheta5->Fill(mom, Lproton-Lpion);
	hLProtonKaonvsPTheta5->Fill(mom, Lproton-LKaon);
      }
    }
    else if(fabs(theta-25)<0.1){
      if(pid==-211){
	hLPiKaonvsPTheta25->Fill(mom, Lpion-LKaon);
	hLPiProtonvsPTheta25->Fill(mom, Lpion-Lproton);
      }
      else if(pid==-321){
	hLKaonPivsPTheta25->Fill(mom, LKaon-Lpion);
	hLKaonProtonvsPTheta25->Fill(mom, LKaon-Lproton);
      }
      else if(pid==2212){
	hLProtonPivsPTheta25->Fill(mom, Lproton-Lpion);
	hLProtonKaonvsPTheta25->Fill(mom, Lproton-LKaon);
      }
    }
    else if(fabs(theta-45)<0.1){
      if(pid==-211){
	hLPiKaonvsPTheta45->Fill(mom, Lpion-LKaon);
	hLPiProtonvsPTheta45->Fill(mom, Lpion-Lproton);
      }
      else if(pid==-321){
	hLKaonPivsPTheta45->Fill(mom, LKaon-Lpion);
	hLKaonProtonvsPTheta45->Fill(mom, LKaon-Lproton);
      }
      else if(pid==2212){
	hLProtonPivsPTheta45->Fill(mom, Lproton-Lpion);
	hLProtonKaonvsPTheta45->Fill(mom, Lproton-LKaon);
      }
    }
    
    //	cout<< "pid: " << pid << ";  momentum: "<< sqrt(px*px+py*py+pz*pz)<<"; Theta: "<< theta <<"; Phi: "<<phi<<endl;
    if(fabs(theta-5)<0.1){
      if(pid==-211){
	for(int j=0; j<62;j++){
	  if(fabs(mom-ptot[j])<0.05){
	    if((Lpion-LKaon)>0. && (Lpion-Lproton)>0.) theta5pipi[j]++;
	    if((LKaon-Lpion)>0. && (LKaon-Lproton)>0.) theta5piK[j]++;
	    if((Lproton-Lpion)>0. && (Lproton-LKaon)>0.) theta5pip[j]++;
	  }
	}
      }
      else if(pid==-321){
	for(int j=0; j<62;j++){
	  if(fabs(mom-ptot[j])<0.05){
	    if((Lpion-LKaon)>0. && (Lpion-Lproton)>0.) theta5Kpi[j]++;
	    if((LKaon-Lpion)>0. && (LKaon-Lproton)>0.) theta5KK[j]++;
	    if((Lproton-Lpion)>0. && (Lproton-LKaon)>0.) theta5Kp[j]++;
	  }
	}
      }
      else if(pid==2212){
	for(int j=0; j<62;j++){
	  if(fabs(mom-ptot[j])<0.05){
	    if((Lpion-LKaon)>0. && (Lpion-Lproton)>0.) theta5ppi[j]++;
	    if((LKaon-Lpion)>0. && (LKaon-Lproton)>0.) theta5pK[j]++;
	    if((Lproton-Lpion)>0. && (Lproton-LKaon)>0.) theta5pp[j]++;
	  }
	}
      }
    }
    else if(fabs(theta-25)<0.1){
      if(pid==-211){
	for(int j=0; j<62;j++){
	  if(fabs(mom-ptot[j])<0.05){
	    if((Lpion-LKaon)>0. && (Lpion-Lproton)>0.) theta25pipi[j]++;
	    if((LKaon-Lpion)>0. && (LKaon-Lproton)>0.) theta25piK[j]++;
	    if((Lproton-Lpion)>0. && (Lproton-LKaon)>0.) theta25pip[j]++;
	  }
	}
      }
      else if(pid==-321){
	for(int j=0; j<62;j++){
	  if(fabs(mom-ptot[j])<0.05){
	    if((Lpion-LKaon)>0. && (Lpion-Lproton)>0.) theta25Kpi[j]++;
	    if((LKaon-Lpion)>0. && (LKaon-Lproton)>0.) theta25KK[j]++;
	    if((Lproton-Lpion)>0. && (Lproton-LKaon)>0.) theta25Kp[j]++;
	  }
	}
      }
      else if(pid==2212){
	for(int j=0; j<62;j++){
	  if(fabs(mom-ptot[j])<0.05){
	    if((Lpion-LKaon)>0. && (Lpion-Lproton)>0.) theta25ppi[j]++;
	    if((LKaon-Lpion)>0. && (LKaon-Lproton)>0.) theta25pK[j]++;
	    if((Lproton-Lpion)>0. && (Lproton-LKaon)>0.) theta25pp[j]++;
	  }
	}
      }
    }
    else if(fabs(theta-45)<0.1){
      if(pid==-211){
	for(int j=0; j<62;j++){
	  if(fabs(mom-ptot[j])<0.05){
	    if((Lpion-LKaon)>0. && (Lpion-Lproton)>0.) theta45pipi[j]++;
	    if((LKaon-Lpion)>0. && (LKaon-Lproton)>0.) theta45piK[j]++;
	    if((Lproton-Lpion)>0. && (Lproton-LKaon)>0.) theta45pip[j]++;
	  }
	}
      }
      else if(pid==-321){
	for(int j=0; j<62;j++){
	  if(fabs(mom-ptot[j])<0.05){
	    if((Lpion-LKaon)>0. && (Lpion-Lproton)>0.) theta45Kpi[j]++;
	    if((LKaon-Lpion)>0. && (LKaon-Lproton)>0.) theta45KK[j]++;
	    if((Lproton-Lpion)>0. && (Lproton-LKaon)>0.) theta45Kp[j]++;
	  }
	}
      }
      else if(pid==2212){
	for(int j=0; j<62;j++){
	  if(fabs(mom-ptot[j])<0.05){
	    if((Lpion-LKaon)>0. && (Lpion-Lproton)>0.) theta45ppi[j]++;
	    if((LKaon-Lpion)>0. && (LKaon-Lproton)>0.) theta45pK[j]++;
	    if((Lproton-Lpion)>0. && (Lproton-LKaon)>0.) theta45pp[j]++;
	  }
	}
      }
    }
  }
  
  
  for(int i=0; i<62; i++){
    
    double theta5totPi = theta5pipi[i]+theta5piK[i]+theta5pip[i];
    hPIDPiPivsPTheta5->Fill(ptot[i], theta5pipi[i]/theta5totPi); 
    hPIDPiKvsPTheta5->Fill(ptot[i], theta5piK[i]/theta5totPi); 
    hPIDPiPvsPTheta5->Fill(ptot[i], theta5pip[i]/theta5totPi);
    
    double theta5totK = theta5Kpi[i]+theta5KK[i]+theta5Kp[i];
    hPIDKPivsPTheta5->Fill(ptot[i], theta5Kpi[i]/theta5totK);
    hPIDKKvsPTheta5->Fill(ptot[i], theta5KK[i]/theta5totK);
    hPIDKPvsPTheta5->Fill(ptot[i], theta5Kp[i]/theta5totK);
    
    double theta5totP = theta5ppi[i]+theta5pK[i]+theta5pp[i];
    hPIDPPivsPTheta5->Fill(ptot[i], theta5ppi[i]/theta5totP);
    hPIDPKvsPTheta5->Fill(ptot[i], theta5pK[i]/theta5totP);
    hPIDPPvsPTheta5->Fill(ptot[i], theta5pp[i]/theta5totP);
    
    double theta25totPi = theta25pipi[i]+theta25piK[i]+theta25pip[i];
    hPIDPiPivsPTheta25->Fill(ptot[i], theta25pipi[i]/theta25totPi);
    hPIDPiKvsPTheta25->Fill(ptot[i], theta25piK[i]/theta25totPi);
    hPIDPiPvsPTheta25->Fill(ptot[i], theta25pip[i]/theta25totPi);
    
    double theta25totK = theta25Kpi[i]+theta25KK[i]+theta25Kp[i];
    hPIDKPivsPTheta25->Fill(ptot[i], theta25Kpi[i]/theta25totK);
    hPIDKKvsPTheta25->Fill(ptot[i], theta25KK[i]/theta25totK);
    hPIDKPvsPTheta25->Fill(ptot[i], theta25Kp[i]/theta25totK);
    
    double theta25totP = theta25ppi[i]+theta25pK[i]+theta25pp[i];
    hPIDPPivsPTheta25->Fill(ptot[i], theta25ppi[i]/theta25totP);
    hPIDPKvsPTheta25->Fill(ptot[i], theta25pK[i]/theta25totP);
    hPIDPPvsPTheta25->Fill(ptot[i], theta25pp[i]/theta25totP);
    
    double theta45totPi = theta45pipi[i]+theta45piK[i]+theta45pip[i];
    hPIDPiPivsPTheta45->Fill(ptot[i], theta45pipi[i]/theta45totPi);
    hPIDPiKvsPTheta45->Fill(ptot[i], theta45piK[i]/theta45totPi);
    hPIDPiPvsPTheta45->Fill(ptot[i], theta45pip[i]/theta45totPi);
    
    double theta45totK = theta45Kpi[i]+theta45KK[i]+theta45Kp[i];
    hPIDKPivsPTheta45->Fill(ptot[i], theta45Kpi[i]/theta45totK);
    hPIDKKvsPTheta45->Fill(ptot[i], theta45KK[i]/theta45totK);
    hPIDKPvsPTheta45->Fill(ptot[i], theta45Kp[i]/theta45totK);
    
    double theta45totP = theta45ppi[i]+theta45pK[i]+theta45pp[i];
    hPIDPPivsPTheta45->Fill(ptot[i], theta45ppi[i]/theta45totP);
    hPIDPKvsPTheta45->Fill(ptot[i], theta45pK[i]/theta45totP);
    hPIDPPvsPTheta45->Fill(ptot[i], theta45pp[i]/theta45totP);
  }
  
  TFile *fFile = new TFile("LogLikelihood.root","RECREATE");
  hLPion->Write();
  hLPiKaonvsPTheta5->Write();
  hLPiProtonvsPTheta5->Write();
  hLKaonPivsPTheta5->Write();
  hLKaonProtonvsPTheta5->Write();
  hLProtonPivsPTheta5->Write();
  hLProtonKaonvsPTheta5->Write();
  
  hLPiKaonvsPTheta25->Write();
  hLPiProtonvsPTheta25->Write();
  hLKaonPivsPTheta25->Write();
  hLKaonProtonvsPTheta25->Write();
  hLProtonPivsPTheta25->Write();
  hLProtonKaonvsPTheta25->Write();
  
  hLPiKaonvsPTheta45->Write();
  hLPiProtonvsPTheta45->Write();
  hLKaonPivsPTheta45->Write();
  hLKaonProtonvsPTheta45->Write();
  hLProtonPivsPTheta45->Write();
  hLProtonKaonvsPTheta45->Write();
  
  hPIDPiPivsPTheta5->Write(); 
  hPIDPiKvsPTheta5->Write();
  hPIDPiPvsPTheta5->Write();
  hPIDKPivsPTheta5->Write();
  hPIDKKvsPTheta5->Write();
  hPIDKPvsPTheta5->Write();
  hPIDPPivsPTheta5->Write();
  hPIDPKvsPTheta5->Write();
  hPIDPPvsPTheta5->Write();
  
  hPIDPiPivsPTheta25->Write();
  hPIDPiKvsPTheta25->Write();
  hPIDPiPvsPTheta25->Write();
  hPIDKPivsPTheta25->Write();
  hPIDKKvsPTheta25->Write();
  hPIDKPvsPTheta25->Write();
  hPIDPPivsPTheta25->Write();
  hPIDPKvsPTheta25->Write();
  hPIDPPvsPTheta25->Write();
  
  hPIDPiPivsPTheta45->Write();
  hPIDPiKvsPTheta45->Write();
  hPIDPiPvsPTheta45->Write();
  hPIDKPivsPTheta45->Write();
  hPIDKKvsPTheta45->Write();
  hPIDKPvsPTheta45->Write();
  hPIDPPivsPTheta45->Write();
  hPIDPKvsPTheta45->Write();
  hPIDPPvsPTheta45->Write();
  
  fFile->Close();
  
}
