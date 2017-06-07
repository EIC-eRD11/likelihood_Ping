/*==========================================================*
 *                   Split.C by Liang                       *
 *==========================================================*
 *                   12-31-2015 Ping                        *
 *----------------------------------------------------------*
 * change                                                   *
 * 1. infile from MBRFF.list to G4_data.list or G4_db.list  *
 * 2. dir from ./ to G4_datalist/ or  G4_dblist/            * 
 *========================================================= */
#include "iostream.h"

void Split(const Char_t *infile = "G4_db.list", const Char_t *dir = "G4_dblist", const Int_t NUM = 1)
//void Split(const Char_t *infile = "G4_data.list", const Char_t *dir = "G4_datalist/", const Int_t NUM = 1)
//void Split(const Char_t *infile = "MBRFF.list", const Char_t *dir = "./", const Int_t NUM = 1)
{
  gROOT->Reset();

  ifstream* inputStream = new ifstream;
  inputStream->open(infile);
  if (!(inputStream)) {
    cout << "can not open list file" << endl;
    return;
  }
  char line[512];
  char outputfile[100];
  ofstream outData;
  for (int i=0;inputStream->good();i++) {
    inputStream->getline(line,512);
    if  ( inputStream->good() ) {
      if(i%NUM==0) {
	if(outData.is_open()) outData.close();
	sprintf(outputfile,"%s/%d.list",dir,i/NUM);
	outData.open(outputfile);
      }
      cout << " read in file " << line << endl;
      outData << line << endl;
    }
  }
  if(outData.is_open()) outData.close();
}
