//////*********************************//////
//////***** Author: Dr. Liang Xue *****//////
//////******  Date: 04/28/2015  *******//////
//////*********************************//////

// This class is to define the agorithm for 
// likelihood analysis for EIC RICH

#ifndef LIKELIHOOD_H
#define LIKELIHOOD_H

#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include "LLTreeDst.h"

//#define doLikelihoodDB

const double DEG=180./3.1415926;
const unsigned int nPads=88;   ///// number of photonsenor segmentation pads

using namespace std;

class event;
class hit;
class material;
class ring;

class likelihood
{
	public:
		likelihood(char *fdb, char *fout);
		~likelihood();

		int init();
		int process_event(event *aevt, hit *ahit);
		int end();

		bool isPhoton(hit *ahit, int i);
		bool isReflection(hit *ahit, int i);
		bool isOnAerogel(hit *ahit, int i);
		bool isOnPhotonSensor(hit *ahit, int i);
		void Smearing2D(double inx, double iny, double& outx, double& outy);
		double probability(TH2D* db, TH2D *hXY);

	private:
		TRandom *rd;
		material *mat;
		char *dbf;
		char *outf;
		TFile *dbfile;
		TFile *outputfile;

		#ifdef doLikelihoodDB
		TH2D *hNEvtvsP;
                TH3D *hPiXYvsP;
                TH3D *hKaonXYvsP;
                TH3D *hProtonXYvsP;
		#else
		TH2D *hNEvtvsP;
		TH3D *hPiXYvsP;
		TH3D *hKaonXYvsP;
		TH3D *hProtonXYvsP;

		TTree *mTree;
		LLTreeDst mDst;
                TH2D *hnHitAeglPerEvtvsMom;
                TH1D *hPhotonWL;
                TH1D *hPhotonE;
                TH2D *hnPhotonElvsnHits_SbKCs;
                TH2D *hnPhotonElvsnHits_GaAsP;
                TH2D *hnPhotonElvsnHits_GaAs;
		#endif
};
#endif
