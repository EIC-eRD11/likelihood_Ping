/*======================================================================*
 *                        analysis.C by Ping                            *
 *                            01-10-2016                                *
 *----------------------------------------------------------------------*
 * Modified from Liang's Analysis.C for performing Likelihood analysis  *
 * on simulation of Modular RICH detector design of eic eRD11/14        *
 *                                                                      *
 * In this macros: Input ../output/G4_data_all.root, then Chain the     * 
 * TTreee:LLTreeDST, and fill histograms.                               *
 * =====================================================================*/ 

#include <TH1.h>
#include <TH2.h>
#include <TChain.h>
#include <TStyle.h>
#include <TROOT.h>
#include <TFile.h>

using namespace std;

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
Double_t        LPion;
Double_t        LKaon;
Double_t        LProton;

const Int_t PION=-211;
const Int_t KAON=-321;
const Int_t PROTON=2212;
const string particleString[3]={"Pi","Kaon","Proton"};
const int THETA[3]={5,25,45};
//incident momentum
const double ptot[61]={ 3.0, 3.2, 3.4, 3.6, 3.8, 4.0, 4.2, 4.4, 4.6, 4.8,
		  5.0, 5.2, 5.4, 5.6, 5.8, 6.0, 6.2, 6.4, 6.6, 6.8,
		  7.0, 7.2, 7.4, 7.6, 7.8, 8.0, 8.2, 8.4, 8.6, 8.8,
		  9.0, 9.2, 9.4, 9.6, 9.8, 10.0, 10.2, 10.4, 10.6, 10.8,
		  11.0, 11.2, 11.4, 11.6, 11.8, 12.0, 12.2, 12.4, 12.6, 12.8,
		  13.0, 13.2, 13.4, 13.6, 13.8, 14.0, 14.2, 14.4, 14.6, 14.8, 15.0 };

TH1D *hLogPion= new TH1D("hLPion","hLPion",200,-200.,0.);
TH2D *hLogvsMom[3][3][3]; //[incident particle][detected species][theta]
TH2D *hPIDvsMom[3][3][3]; //[incident particle][detected species][theta]

void SetgStyle();
void Set_Branch_Address(TChain* fchain);
void SetHisto();
double GetMomentum();
void Fill_hLogvsMom(int* index,double mom);
void getIndex(int* index, double mom);
int plusOne(int species);
void WriteFile(const char* filename);

//==================================================================//
void analysis(const char *inputFile="../output/G4_data_all.root")
{
  int count[3][3][3][61]={0}; //[incident particle][detected species][theta][momentum]
  
  SetgStyle();
  SetHisto();
  //---------------------- Set Branch Address ----------------------// 
  TChain *fchain  = new TChain("LLTreeDst");
  fchain->Add(inputFile);
  Set_Branch_Address(fchain);
  
  //------------------------ Fill Histograms -----------------------//
  Int_t nEvents = fchain->GetEntries();
  cout<<"nEvents="<<nEvents<<endl;

  for(int i=0;i<nEvents; i++){
    if(i%1000==0) cout<<"====== Processing "<< i <<" events; ====="<< endl;
    
    fchain->GetEntry(i);
    double mom=sqrt(pow(px,2)+pow(py,2)+pow(pz,2));
    
    int index[3]; //={incident Particle, theta, momentum}
    getIndex(index,mom);
    
    Fill_hLogvsMom(index, mom);
    
    //count PID efficiency & mis-PID
    for (int j=0;j<3;j++) {
      if (plusOne(j)) count[index[0]][j][index[1]][index[2]]++;
    }
  }//end of f(i;i<nEvent;i++)

  
  for (int i=0;i<3;i++) {
    for (int k=0;k<3;k++) {
      for (int m=0;m<61;m++) {
	int sumCount=count[i][0][k][m]+count[i][1][k][m]+count[i][2][k][m];
	for (int j=0;j<3;j++) {
	  hPIDvsMom[i][j][k]->Fill(ptot[m],count[i][j][k][m]/sumCount);
	}
      }
    }
  }

  WriteFile("LogLikelihood.root");
  
}//end of analysis()
//==================================================================//

void SetgStyle()
{
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
}

//==================================================================//
void Set_Branch_Address(TChain* fchain)
{
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
  fchain->SetBranchAddress("Lpion", &LPion);
  fchain->SetBranchAddress("LKaon", &LKaon);
  fchain->SetBranchAddress("Lproton", &LProton);
}

//==================================================================//
void SetHisto()
{
  float xMin[2]={2.5, 2.5};
  float xMax[2]={15.5, 15.5};
  float xBin[2]={65, 65};
  float yMin[2]={-20, 0};
  float yMax[2]={130, 1.2};
  float yBin[2]={150, 120};
  
  string Prefix[2]={"hL","hPID"};
  string theta[3]={"5","25","45"};
  string Name, Title;
  
  for(int i=0;i<3;i++) { //incidet particle
    for (int j=0;j<3;j++) { //detected species
      for (int k=0;k<3;k++) { //theta
	
	if (i!=j) {
	  Name=Prefix[0]+particleString[i]+particleString[j]+"vsPTheta"+theta[k];
	  Title=Name;
	  hLogvsMom[i][j][k]=new TH2D(Name.c_str(),Title.c_str(),xBin[0],xMin[0],xMax[0],yBin[0],yMin[0],yMax[0]);
	}
	
	Name=Prefix[1]+particleString[i]+particleString[j]+"vsPTheta"+theta[k];
	Title=Name;
	hPIDvsMom[i][j][k]=new TH2D(Name.c_str(),Title.c_str(),xBin[1],xMin[1],xMax[1],yBin[1],yMin[1],yMax[1]);
      }
    }
  }  
}

//==================================================================//
void Fill_hLogvsMom(int* index, double mom)
{
  Double_t Log[3]={LPion, LKaon, LProton};
  if (index[0]<3 && index[1]<3) {
    if (index[0]==0 && index[1]==0) hLogPion->Fill(Log[0]);
    
    for (int i=0;i<3;i++) {
      if(i==index[0]) continue;
      hLogvsMom[index[0]][i][index[1]]->Fill(mom,Log[index[0]]-Log[i]);
    }
  } 
}

//==================================================================//
void getIndex(int* index, double mom)
{
  if (pid==PION) index[0]=0;
  else if (pid==KAON) index[0]=1;
  else if (pid==PROTON) index[0]=2;
  else index[0]=3;

  if (fabs(theta-THETA[0])<0.1) index[1]=0;
  else if (fabs(theta-THETA[1])<0.1) index[1]=1;
  else if (fabs(theta-THETA[2])<0.1) index[1]=2;
  else index[1]=3;

  for (int i=0;i<61;i++) {
    if (fabs(mom-ptot[i])<0.05) {
      index[2]=i;
      break;
    }
  }
}

//==================================================================//
int plusOne(int species)
{
  Double_t Log[3]={LPion, LKaon, LProton};
  int plus=1;

  for (int i=0;i<3;i++) {
    if (i==species) continue;

    if (Log[i]>Log[species]) {
      plus=-1;
      break;
    }
  }
    
  return plus;
}

//==================================================================//
void WriteFile(const char* filename)
{
  TFile* outputFile=new TFile(filename,"RECREATE");

  for (int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      for (int k=0;k<3;k++) {
	if (i!=j) hLogvsMom[i][j][k]->Write();
      }
    }
  }

  for (int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      for (int k=0;k<3;k++) {
	hPIDvsMom[i][j][k]->Write();
      }
    }
  }

  outputFile->Close();
}
