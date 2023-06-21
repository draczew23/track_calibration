/*
  Code to check the variables from the tracks in stentu
  Author: P. Beltrame
  2023/06/13 - Created
  2023/06/14 - Added h_0_pxt, h_0_pytr, h_0_pztr
  2023/06/15 - Checked that from STENTU two and only two tracks are stored
  2023/06/20 - Evaluation of TrackMass and Q2
 */

#include <iostream>
#include <math.h>  

#include "TROOT.h"

#include "StentuReader.h"
#include "BadRun.cpp"

double rad2deg = 57.29578;
double mpi = 139.56995;
double mmu = 105.65839;

int trackcheck(const char *fdir="/home/user/NCBJ_files/KLOE/Paulo_help/track_calibration", const char *ftype="ppg") {
 
  // Loading Files
  TChain *tr = new TChain("STENTU/h1","");
  TSystemDirectory dir(fdir,fdir); 
  TList *files = dir.GetListOfFiles();
  if (files) {
    TSystemFile *file;
    TString fname;
    TIter next(files);
    while ((file=(TSystemFile*)next())) {
      fname = file->GetName();
      if (!file->IsDirectory() && fname.BeginsWith(ftype)) {
	cout << " ------------- " << endl;
	cout << " Loading file : " << fname << endl;
	cout << " ------------- " << endl;
	fname.Prepend("/");
	tr->Add(fdir+fname);
      }
    }
  }
  using namespace stentu;
  StentuReader evreader(tr);
  long nentries = tr->GetEntries();
  cout << "Number of entries " << nentries << endl;
  TFile *fout = TFile::Open(Form("hist_%s.root",ftype),"recreate");
  cout << " ------------- " << endl;

  // Histograms declaration
  gROOT->SetStyle("Bold");
  double bxsize, bxmin, bxmax, bysize, bymin, bymax;

  bxmax = 550.; bxmin = -550.; bxsize = 1;
  TH1F *h_0_pxtr = new TH1F("h_0_pxtr","pxtr", (bxmax-bxmin)/bxsize,bxmin,bxmax);
  TH1F *h_0_pxtr1 = new TH1F("h_0_pxtr1","pxtr 1", (bxmax-bxmin)/bxsize,bxmin,bxmax);
  TH1F *h_0_pxtr2 = new TH1F("h_0_pxtr2","pxtr 2", (bxmax-bxmin)/bxsize,bxmin,bxmax);
  TH1F *h_0_pytr = new TH1F("h_0_pytr","pytr", (bxmax-bxmin)/bxsize,bxmin,bxmax);
  TH1F *h_0_pytr1 = new TH1F("h_0_pytr1","pytr 1", (bxmax-bxmin)/bxsize,bxmin,bxmax);
  TH1F *h_0_pytr2 = new TH1F("h_0_pytr2","pytr 2", (bxmax-bxmin)/bxsize,bxmin,bxmax);
  TH1F *h_0_pztr = new TH1F("h_0_pztr","pztr", (bxmax-bxmin)/bxsize,bxmin,bxmax);
  TH1F *h_0_pztr1 = new TH1F("h_0_pztr1","pztr 1", (bxmax-bxmin)/bxsize,bxmin,bxmax);
  TH1F *h_0_pztr2 = new TH1F("h_0_pztr2","pztr 2", (bxmax-bxmin)/bxsize,bxmin,bxmax);
  
  bxmax = 250.; bxmin = 50.; bxsize = 1;
  TH1F *h_trkms = new TH1F("h_trkms","M_{trk}", (bxmax-bxmin)/bxsize,bxmin,bxmax);
  bymax = 1.; bymin = 0.; bysize = 1e-2;
  TH1F *h_qq = new TH1F("h_qq","Q^{2}", (bymax-bymin)/bysize,bymin,bymax);

  TH2F *h_qqtrkms = new TH2F("h_qqtrkms","Q^{2} M_{trk}", (bymax-bymin)/bysize,bymin,bymax, (bxmax-bxmin)/bxsize,bxmin,bxmax);

  double pmodb = 0;
  double eneb = 0;
  double rhofh[2] = {0};
  double rhopca[2] = {0};
  double ptp[2] = {0};
  double pmodtr[2] = {0};
  double ephot = 0;
  double asquared = 0;
  double trkms = 0;
  double psx = 0;
  double psy = 0;
  double psz = 0;
  double ps4 = 0;
  double q2 = 0;
  
  // 

  // LOOPING ON THE EVENTS //
  int scaledown = 5;
  int nn = nentries/scaledown;
  for (int iev = 0; iev < nn; iev++)
    {
      evreader.GetEntry(iev);	    
      int ntrk = sizeof(pxtr)/sizeof(int);
      if (isbadrun(Runnumber)) continue;
      if (iev>0 && iev%100000 == 0) cout << " Events : " << iev << endl;
      for (int ii = 0; ii < ntrk; ii++) {
       	if ((pxtr[ii]*pytr[ii]*pztr[ii])!=0) 
	  {h_0_pxtr->Fill(pxtr[ii]); h_0_pytr->Fill(pytr[ii]); h_0_pztr->Fill(pztr[ii]);}
      }
      if ((pxtr[0]*pytr[0]*pztr[0])!=0)
	{h_0_pxtr1->Fill(pxtr[0]); h_0_pytr1->Fill(pytr[0]); h_0_pztr1->Fill(pztr[0]);} 
      if ((pxtr[1]*pytr[1]*pztr[1])!=0)
	{h_0_pxtr2->Fill(pxtr[1]); h_0_pytr2->Fill(pytr[1]); h_0_pztr2->Fill(pztr[1]);}
      
      pmodb = sqrt(pow(pphix,2)+pow(pphiy,2)+pow(pphiz,2)); 

      if (ppgtag == 0) continue;
      if (filfo == 0) continue;
      if (ivtx*ndtfs[0]*ndtfs[1] == 0) continue;
      if (sqrt(pow(xvtx,2)+pow(yvtx,2))>15. or abs(zvtx)>7.) continue; 
      if (nprompt>10) continue;
      
      // Tracks
      bool flagdrch = true;
      bool flagp = true;
      bool flagass = true;
      bool flaglog = true;
	
      for (int ii = 0; ii < ntrk; ii++) {
	
	rhofh[ii] = sqrt(pow(xfirst[ii],2)+pow(yfirst[ii],2));
	rhopca[ii] = sqrt(pow(xpca[ii],2)+pow(ypca[ii],2));
	ptp[ii] = sqrt(pow(pxtr[ii],2)+pow(pytr[ii],2));
	
	if (rhofh[ii]>50 or rhopca[ii]>8 or abs(zpca[ii])>12)
	  flagdrch = false;
	if (abs(pztr[ii]) < 90 or ptp[ii] < 160) 
	  flagp = false;
	if (pxtr[ii]==0) 
	  flagp = false;
	if (assclu[ii] == 0) 
	  flagass = false;
	if (logrl[ii] < 0 ) 
	  flaglog = false;
	
      } // End loop on tracks

      if (flagdrch==false or flagp== false or flagp==false or flagass==false or flaglog==false) continue;

      // Track Mass
      pmodtr[0] = sqrt(pow(pxtr[0],2)+pow(pytr[0],2)+pow(pztr[0],2));
      pmodtr[1] = sqrt(pow(pxtr[1],2)+pow(pytr[1],2)+pow(pztr[1],2));
      ephot = pow((pphix-(pxtr[0]+pxtr[1])),2)+pow((pphiy-(pytr[0]+pytr[1])),2)+pow((pphiz-(pztr[0]+pztr[1])),2);
      ephot = sqrt(ephot);
      eneb = sqrt(pow(sqrts,2)+pow(pmodb,2));
      asquared = pow((ephot-eneb),2)-(pow(pmodtr[0],2)+pow(pmodtr[1],2));
      asquared = 0.5*asquared;
      trkms = (pow(asquared,2)-pow(pmodtr[0],2)*pow(pmodtr[1],2))
	/(2*asquared+pow(pmodtr[0],2)+pow(pmodtr[1],2));
      trkms = sqrt(trkms);
      
      // Q squared
      psx = pxtr[0]+pxtr[1];
      psy = pytr[0]+pytr[1];
      psz = pztr[0]+pztr[1];
      ps4 = sqrt(pow(pmodtr[0],2)+pow(mpi,2))+sqrt(pow(pmodtr[1],2)+pow(mpi,2));
      q2 = (pow(ps4,2)-(pow(psx,2)+pow(psy,2)+pow(psz,2)))*1.E-6;
      
      h_trkms->Fill(trkms);
      h_qq->Fill(q2);
      h_qqtrkms->Fill(q2, trkms);
      
    } // End loop on the events
 
  fout->Write();
  
  return 0;
}
