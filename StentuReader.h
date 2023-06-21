//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Jan  7 12:44:46 2023 by ROOT version 6.26/00
// from TTree h1/STENTU
// found on file: files/drc_stentu_pcadtm_30300_30302.root
//////////////////////////////////////////////////////////

#ifndef StentuReader_h
#define StentuReader_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
namespace stentu{
  // Declaration of leaf types
   Int_t           Runnumber;
   Int_t           Eventnumber;
   Float_t         pphix;
   Float_t         pphiy;
   Float_t         pphiz;
   Float_t         sqrts;
   Float_t         phix;
   Float_t         phiy;
   Float_t         phiz;
   Int_t           trgtype;
   Int_t           cosmveto;
   Int_t           l2dch;
   Int_t           l3flag;
   Int_t           filfo;
   Int_t           flfdwnscl;
   Int_t           ppgtag;
   Int_t           tagevtyp;
   Int_t           rpitag;
   Int_t           ivtx;
   Int_t           ndtfs[2];
   Int_t           assclu[2];
   Float_t         eplan[5][2];
   Float_t         etot[2];
   Float_t         deltatp[2];
   Float_t         deltate[2];
   Float_t         alpi[2];
   Float_t         alel[2];
   Float_t         logrl[2];
   Float_t         mlp[2];
   Float_t         xvtx;
   Float_t         yvtx;
   Float_t         zvtx;
   Float_t         pxtr[2];
   Float_t         pytr[2];
   Float_t         pztr[2];
   Float_t         thetr[2];
   Float_t         phitr[2];
   Float_t         trkmass;
   Float_t         qq;
   Float_t         the_pions_cm;
   Float_t         qq_mm;
   Float_t         the_muons_cm;
   Float_t         dista;
   Float_t         smtrk;
   Int_t           ndeid;
   Float_t         nsampling[2];
   Float_t         nsampletrunc[2];
   Float_t         dedxmean[2];
   Float_t         trmean[2];
   Float_t         pulle[2];
   Float_t         pullm[2];
   Float_t         pullp[2];
   Int_t           nprompt;
   Float_t         enepro[10];
   Float_t         tpro[10];
   Float_t         xpro[10];
   Float_t         ypro[10];
   Float_t         zpro[10];
   Float_t         Eneclu[2];
   Float_t         Tclu[2];
   Float_t         Xclu[2];
   Float_t         Yclu[2];
   Float_t         Zclu[2];
   Int_t           secstr[2];
   Int_t           secsph[10];
   Int_t           secsrest;
   Float_t         xfirst[2];
   Float_t         yfirst[2];
   Float_t         zfirst[2];
   Float_t         xpca[2];
   Float_t         ypca[2];
   Float_t         zpca[2];
   Float_t         xlast[2];
   Float_t         ylast[2];
   Float_t         zlast[2];
   Float_t         pxtrmc[4];
   Float_t         pytrmc[4];
   Float_t         pztrmc[4];
   Float_t         trkmassmc;
   Float_t         qqmc;
   Float_t         the_pions_cmmc;
   Float_t         qqmc_mm;
   Float_t         the_muons_cmmc;
   Int_t           pidmc[10];
   Int_t           pkinmc[10];
   Float_t         Chi2f[2];
   Float_t         probc[2];
   Float_t         curf[2];
   Float_t         ctf[2];
   Float_t         phif[2];
   Float_t         scur2[2];
   Float_t         scurct[2];
   Float_t         scurph[2];
   Float_t         sct2[2];
   Float_t         sctph[2];
   Float_t         sphi2[2];
   Float_t         curp[2];
   Float_t         ctp[2];
   Float_t         phip[2];
   Float_t         scur2p[2];
   Float_t         scurctp[2];
   Float_t         scurphp[2];
   Float_t         sct2p[2];
   Float_t         sctphp[2];
   Float_t         sphi2p[2];
   Int_t           nhit[2];
}

class StentuReader {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // List of branches
   TBranch        *b_Runnumber;   //!
   TBranch        *b_Eventnumber;   //!
   TBranch        *b_pphix;   //!
   TBranch        *b_pphiy;   //!
   TBranch        *b_pphiz;   //!
   TBranch        *b_sqrts;   //!
   TBranch        *b_phix;   //!
   TBranch        *b_phiy;   //!
   TBranch        *b_phiz;   //!
   TBranch        *b_trgtype;   //!
   TBranch        *b_cosmveto;   //!
   TBranch        *b_l2dch;   //!
   TBranch        *b_l3flag;   //!
   TBranch        *b_filfo;   //!
   TBranch        *b_flfdwnscl;   //!
   TBranch        *b_ppgtag;   //!
   TBranch        *b_tagevtyp;   //!
   TBranch        *b_rpitag;   //!
   TBranch        *b_ivtx;   //!
   TBranch        *b_ndtfs;   //!
   TBranch        *b_assclu;   //!
   TBranch        *b_eplan;   //!
   TBranch        *b_etot;   //!
   TBranch        *b_deltatp;   //!
   TBranch        *b_deltate;   //!
   TBranch        *b_alpi;   //!
   TBranch        *b_alel;   //!
   TBranch        *b_logrl;   //!
   TBranch        *b_mlp;   //!
   TBranch        *b_xvtx;   //!
   TBranch        *b_yvtx;   //!
   TBranch        *b_zvtx;   //!
   TBranch        *b_pxtr;   //!
   TBranch        *b_pytr;   //!
   TBranch        *b_pztr;   //!
   TBranch        *b_thetr;   //!
   TBranch        *b_phitr;   //!
   TBranch        *b_trkmass;   //!
   TBranch        *b_qq;   //!
   TBranch        *b_the_pions_cm;   //!
   TBranch        *b_qq_mm;   //!
   TBranch        *b_the_muons_cm;   //!
   TBranch        *b_dista;   //!
   TBranch        *b_smtrk;   //!
   TBranch        *b_ndeid;   //!
   TBranch        *b_nsampling;   //!
   TBranch        *b_nsampletrunc;   //!
   TBranch        *b_dedxmean;   //!
   TBranch        *b_trmean;   //!
   TBranch        *b_pulle;   //!
   TBranch        *b_pullm;   //!
   TBranch        *b_pullp;   //!
   TBranch        *b_nprompt;   //!
   TBranch        *b_enepro;   //!
   TBranch        *b_tpro;   //!
   TBranch        *b_xpro;   //!
   TBranch        *b_ypro;   //!
   TBranch        *b_zpro;   //!
   TBranch        *b_Eneclu;   //!
   TBranch        *b_Tclu;   //!
   TBranch        *b_Xclu;   //!
   TBranch        *b_Yclu;   //!
   TBranch        *b_Zclu;   //!
   TBranch        *b_secstr;   //!
   TBranch        *b_secsph;   //!
   TBranch        *b_secsrest;   //!
   TBranch        *b_xfirst;   //!
   TBranch        *b_yfirst;   //!
   TBranch        *b_zfirst;   //!
   TBranch        *b_xpca;   //!
   TBranch        *b_ypca;   //!
   TBranch        *b_zpca;   //!
   TBranch        *b_xlast;   //!
   TBranch        *b_ylast;   //!
   TBranch        *b_zlast;   //!
   TBranch        *b_pxtrmc;   //!
   TBranch        *b_pytrmc;   //!
   TBranch        *b_pztrmc;   //!
   TBranch        *b_trkmassmc;   //!
   TBranch        *b_qqmc;   //!
   TBranch        *b_the_pions_cmmc;   //!
   TBranch        *b_qqmc_mm;   //!
   TBranch        *b_the_muons_cmmc;   //!
   TBranch        *b_pidmc;   //!
   TBranch        *b_pkinmc;   //!
   TBranch        *b_Chi2f;   //!
   TBranch        *b_probc;   //!
   TBranch        *b_curf;   //!
   TBranch        *b_ctf;   //!
   TBranch        *b_phif;   //!
   TBranch        *b_scur2;   //!
   TBranch        *b_scurct;   //!
   TBranch        *b_scurph;   //!
   TBranch        *b_sct2;   //!
   TBranch        *b_sctph;   //!
   TBranch        *b_sphi2;   //!
   TBranch        *b_curp;   //!
   TBranch        *b_ctp;   //!
   TBranch        *b_phip;   //!
   TBranch        *b_scur2p;   //!
   TBranch        *b_scurctp;   //!
   TBranch        *b_scurphp;   //!
   TBranch        *b_sct2p;   //!
   TBranch        *b_sctphp;   //!
   TBranch        *b_sphi2p;   //!
   TBranch        *b_nhit;   //!

   StentuReader(TTree *tree=0);
   virtual ~StentuReader();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(){};
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

//#endif

//#ifdef StentuReader_cxx
StentuReader::StentuReader(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("drc_stentu_pcadtm_30300_30302.root");// There was "files/drc....." even though the folder given by Fedor had no such directory "files". Removing it there seems to be no change in the functioning of the looper script
      if (!f || !f->IsOpen()) {
         f = new TFile("drc_stentu_pcadtm_30300_30302.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("drc_stentu_pcadtm_30300_30302.root:/STENTU");
      dir->GetObject("h1",tree);

   }
   Init(tree);
}

StentuReader::~StentuReader()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t StentuReader::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t StentuReader::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void StentuReader::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   using namespace stentu;
   
   fChain->SetBranchAddress("Runnumber", &Runnumber, &b_Runnumber);
   fChain->SetBranchAddress("Eventnumber", &Eventnumber, &b_Eventnumber);
   fChain->SetBranchAddress("pphix", &pphix, &b_pphix);
   fChain->SetBranchAddress("pphiy", &pphiy, &b_pphiy);
   fChain->SetBranchAddress("pphiz", &pphiz, &b_pphiz);
   fChain->SetBranchAddress("sqrts", &sqrts, &b_sqrts);
   fChain->SetBranchAddress("phix", &phix, &b_phix);
   fChain->SetBranchAddress("phiy", &phiy, &b_phiy);
   fChain->SetBranchAddress("phiz", &phiz, &b_phiz);
   fChain->SetBranchAddress("trgtype", &trgtype, &b_trgtype);
   fChain->SetBranchAddress("cosmveto", &cosmveto, &b_cosmveto);
   fChain->SetBranchAddress("l2dch", &l2dch, &b_l2dch);
   fChain->SetBranchAddress("l3flag", &l3flag, &b_l3flag);
   fChain->SetBranchAddress("filfo", &filfo, &b_filfo);
   fChain->SetBranchAddress("flfdwnscl", &flfdwnscl, &b_flfdwnscl);
   fChain->SetBranchAddress("ppgtag", &ppgtag, &b_ppgtag);
   fChain->SetBranchAddress("tagevtyp", &tagevtyp, &b_tagevtyp);
   fChain->SetBranchAddress("rpitag", &rpitag, &b_rpitag);
   fChain->SetBranchAddress("ivtx", &ivtx, &b_ivtx);
   fChain->SetBranchAddress("ndtfs", ndtfs, &b_ndtfs);
   fChain->SetBranchAddress("assclu", assclu, &b_assclu);
   fChain->SetBranchAddress("eplan", eplan, &b_eplan);
   fChain->SetBranchAddress("etot", etot, &b_etot);
   fChain->SetBranchAddress("deltatp", deltatp, &b_deltatp);
   fChain->SetBranchAddress("deltate", deltate, &b_deltate);
   fChain->SetBranchAddress("alpi", alpi, &b_alpi);
   fChain->SetBranchAddress("alel", alel, &b_alel);
   fChain->SetBranchAddress("logrl", logrl, &b_logrl);
   fChain->SetBranchAddress("mlp", mlp, &b_mlp);
   fChain->SetBranchAddress("xvtx", &xvtx, &b_xvtx);
   fChain->SetBranchAddress("yvtx", &yvtx, &b_yvtx);
   fChain->SetBranchAddress("zvtx", &zvtx, &b_zvtx);
   fChain->SetBranchAddress("pxtr", pxtr, &b_pxtr);
   fChain->SetBranchAddress("pytr", pytr, &b_pytr);
   fChain->SetBranchAddress("pztr", pztr, &b_pztr);
   fChain->SetBranchAddress("thetr", thetr, &b_thetr);
   fChain->SetBranchAddress("phitr", phitr, &b_phitr);
   fChain->SetBranchAddress("trkmass", &trkmass, &b_trkmass);
   fChain->SetBranchAddress("qq", &qq, &b_qq);
   fChain->SetBranchAddress("the_pions_cm", &the_pions_cm, &b_the_pions_cm);
   fChain->SetBranchAddress("qq_mm", &qq_mm, &b_qq_mm);
   fChain->SetBranchAddress("the_muons_cm", &the_muons_cm, &b_the_muons_cm);
   fChain->SetBranchAddress("dista", &dista, &b_dista);
   fChain->SetBranchAddress("smtrk", &smtrk, &b_smtrk);
   fChain->SetBranchAddress("ndeid", &ndeid, &b_ndeid);
   fChain->SetBranchAddress("nsampling", nsampling, &b_nsampling);
   fChain->SetBranchAddress("nsampletrunc", nsampletrunc, &b_nsampletrunc);
   fChain->SetBranchAddress("dedxmean", dedxmean, &b_dedxmean);
   fChain->SetBranchAddress("trmean", trmean, &b_trmean);
   fChain->SetBranchAddress("pulle", pulle, &b_pulle);
   fChain->SetBranchAddress("pullm", pullm, &b_pullm);
   fChain->SetBranchAddress("pullp", pullp, &b_pullp);
   fChain->SetBranchAddress("nprompt", &nprompt, &b_nprompt);
   fChain->SetBranchAddress("enepro", enepro, &b_enepro);
   fChain->SetBranchAddress("tpro", tpro, &b_tpro);
   fChain->SetBranchAddress("xpro", xpro, &b_xpro);
   fChain->SetBranchAddress("ypro", ypro, &b_ypro);
   fChain->SetBranchAddress("zpro", zpro, &b_zpro);
   fChain->SetBranchAddress("Eneclu", Eneclu, &b_Eneclu);
   fChain->SetBranchAddress("Tclu", Tclu, &b_Tclu);
   fChain->SetBranchAddress("Xclu", Xclu, &b_Xclu);
   fChain->SetBranchAddress("Yclu", Yclu, &b_Yclu);
   fChain->SetBranchAddress("Zclu", Zclu, &b_Zclu);
   fChain->SetBranchAddress("secstr", secstr, &b_secstr);
   fChain->SetBranchAddress("secsph", secsph, &b_secsph);
   fChain->SetBranchAddress("secsrest", &secsrest, &b_secsrest);
   fChain->SetBranchAddress("xfirst", xfirst, &b_xfirst);
   fChain->SetBranchAddress("yfirst", yfirst, &b_yfirst);
   fChain->SetBranchAddress("zfirst", zfirst, &b_zfirst);
   fChain->SetBranchAddress("xpca", xpca, &b_xpca);
   fChain->SetBranchAddress("ypca", ypca, &b_ypca);
   fChain->SetBranchAddress("zpca", zpca, &b_zpca);
   fChain->SetBranchAddress("xlast", xlast, &b_xlast);
   fChain->SetBranchAddress("ylast", ylast, &b_ylast);
   fChain->SetBranchAddress("zlast", zlast, &b_zlast);
   fChain->SetBranchAddress("pxtrmc", pxtrmc, &b_pxtrmc);
   fChain->SetBranchAddress("pytrmc", pytrmc, &b_pytrmc);
   fChain->SetBranchAddress("pztrmc", pztrmc, &b_pztrmc);
   fChain->SetBranchAddress("trkmassmc", &trkmassmc, &b_trkmassmc);
   fChain->SetBranchAddress("qqmc", &qqmc, &b_qqmc);
   fChain->SetBranchAddress("the_pions_cmmc", &the_pions_cmmc, &b_the_pions_cmmc);
   fChain->SetBranchAddress("qqmc_mm", &qqmc_mm, &b_qqmc_mm);
   fChain->SetBranchAddress("the_muons_cmmc", &the_muons_cmmc, &b_the_muons_cmmc);
   fChain->SetBranchAddress("pidmc", pidmc, &b_pidmc);
   fChain->SetBranchAddress("pkinmc", pkinmc, &b_pkinmc);
   fChain->SetBranchAddress("Chi2f", Chi2f, &b_Chi2f);
   fChain->SetBranchAddress("probc", probc, &b_probc);
   fChain->SetBranchAddress("curf", curf, &b_curf);
   fChain->SetBranchAddress("ctf", ctf, &b_ctf);
   fChain->SetBranchAddress("phif", phif, &b_phif);
   fChain->SetBranchAddress("scur2", scur2, &b_scur2);
   fChain->SetBranchAddress("scurct", scurct, &b_scurct);
   fChain->SetBranchAddress("scurph", scurph, &b_scurph);
   fChain->SetBranchAddress("sct2", sct2, &b_sct2);
   fChain->SetBranchAddress("sctph", sctph, &b_sctph);
   fChain->SetBranchAddress("sphi2", sphi2, &b_sphi2);
   fChain->SetBranchAddress("curp", curp, &b_curp);
   fChain->SetBranchAddress("ctp", ctp, &b_ctp);
   fChain->SetBranchAddress("phip", phip, &b_phip);
   fChain->SetBranchAddress("scur2p", scur2p, &b_scur2p);
   fChain->SetBranchAddress("scurctp", scurctp, &b_scurctp);
   fChain->SetBranchAddress("scurphp", scurphp, &b_scurphp);
   fChain->SetBranchAddress("sct2p", sct2p, &b_sct2p);
   fChain->SetBranchAddress("sctphp", sctphp, &b_sctphp);
   fChain->SetBranchAddress("sphi2p", sphi2p, &b_sphi2p);
   fChain->SetBranchAddress("nhit", nhit, &b_nhit);
   Notify();
}

Bool_t StentuReader::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void StentuReader::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t StentuReader::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef StentuReader_cxx
