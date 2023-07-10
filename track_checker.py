import ROOT
import numpy as np
import matplotlib.pyplot as plt
from BadRun import IsBadRun
from ROOT import gROOT
from BadRun import IsBadRun

bad_run_checker = IsBadRun()    # Class for checking bad runs

myFile = ROOT.TFile.Open("ppgphok5_stentu_pcadtm_all.root") 
ROOT.ROOT.EnableImplicitMT()
gROOT.SetStyle("Bold")

root_file = ROOT.TFile("output.root", "RECREATE")   # Output root file with histograms

ourTree = myFile.STENTU
h1 = ourTree.h1
branch_pxtr = h1.GetBranch("pxtr")
nentries = branch_pxtr.GetEntries()
scaledown = 5000
nn = int(nentries/scaledown)
print(nn)

rad2deg = 57.29578
mpi = 139.56995
mmu = 105.65839

### Histogram parameters ###
bxsize = 1.
bxmin = -550.
bxmax = 550
bysize = 1e-2
bymin = 0
bymax = 1.
### Histogram parameters ###

ev_counter = 0

bymax = 1.
bymin = 0.
bysize = 1e-2

h0_pxtr = ROOT.TH1F("h0_pxtr", "pxtr", int((bxmax-bxmin)/bxsize), int(bxmin), int(bxmax))
h0_pxtr1 = ROOT.TH1F("h0_pxtr1", "pxtr1", int((bxmax-bxmin)/bxsize), int(bxmin), int(bxmax))
h0_pxtr2 = ROOT.TH1F("h0_pxtr2", "pxtr2", int((bxmax-bxmin)/bxsize), int(bxmin), int(bxmax))
h0_pytr = ROOT.TH1F("h0_pytr", "pytr", int((bxmax-bxmin)/bxsize), int(bxmin), int(bxmax))
h0_pytr1 = ROOT.TH1F("h0_pytr1", "pytr1", int((bxmax-bxmin)/bxsize), int(bxmin), int(bxmax))
h0_pytr2 = ROOT.TH1F("h0_pytr2", "pytr2", int((bxmax-bxmin)/bxsize), int(bxmin), int(bxmax))
h0_pztr = ROOT.TH1F("h0_pztr", "pztr", int((bxmax-bxmin)/bxsize), int(bxmin), int(bxmax))
h0_pztr1 = ROOT.TH1F("h0_pztr1", "pztr1", int((bxmax-bxmin)/bxsize), int(bxmin), int(bxmax))
h0_pztr2 = ROOT.TH1F("h0_pztr2", "pztr2", int((bxmax-bxmin)/bxsize), int(bxmin), int(bxmax))

bxmax = 250.
bxmin = 50.
bxsize = 1

h_trkms = ROOT.TH1F("h_trkms","M_{trk}", int((bxmax-bxmin)/bxsize), int(bxmin), int(bxmax))
h_qq = ROOT.TH1F("h_qq","Q^{2}", int((bymax-bymin)/bysize), int(bymin), int(bymax))

h_qqtrkms = ROOT.TH2F("h_qqtrkms","Q^{2} M_{trk}", int((bymax-bymin)/bysize), int(bymin), int(bymax), 
                      int((bxmax-bxmin)/bysize), int(bxmin), int(bxmax))


for event in h1:
    break_check = ev_counter < nn

    if not break_check:
        break
    ev_counter += 1
    
    if bad_run_checker.is_bad_run(event.Runnumber):
        continue

    pxtr_temp = np.array([event.pxtr[0], event.pxtr[1]])
    pytr_temp = np.array([event.pytr[0], event.pytr[1]])
    pztr_temp = np.array([event.pztr[0], event.pztr[1]])

    for ii in range(2):
       	if ((pxtr_temp[ii]*pytr_temp[ii]*pztr_temp[ii]) != 0): 
            h0_pxtr.Fill(pxtr_temp[ii])
            h0_pytr.Fill(pytr_temp[ii])
            h0_pztr.Fill(pztr_temp[ii])
    
    if ((pxtr_temp[0]*pytr_temp[0]*pztr_temp[0]) != 0):
            h0_pxtr1.Fill(pxtr_temp[0])
            h0_pytr1.Fill(pytr_temp[0])
            h0_pztr1.Fill(pztr_temp[0])

    if ((pxtr_temp[1]*pytr_temp[1]*pztr_temp[1]) != 0):
            h0_pxtr2.Fill(pxtr_temp[1])
            h0_pytr2.Fill(pytr_temp[1])
            h0_pztr2.Fill(pztr_temp[1])  
        
    pmodb_val = np.sqrt(event.pphix**2 + event.pphiy**2 + event.pphiz**2)

    if event.ppgtag == 0:
        continue
    if event.filfo == 0:
        continue
    if event.ivtx*event.ndtfs[0]*event.ndtfs[1] == 0:
        continue
    if np.sqrt((event.xvtx**2 + event.yvtx**2))>15. or np.abs(event.zvtx)>7:
        continue
    if event.nprompt > 10:
        continue

    flagdrch = True
    flagp = True
    flagass = True
    flaglog = True

    temp_xfirst = np.array([event.xfirst[0], event.xfirst[1]])
    temp_yfirst = np.array([event.yfirst[0], event.yfirst[1]])

    temp_xpca = np.array([event.xpca[0], event.xpca[1]])
    temp_ypca = np.array([event.ypca[0], event.ypca[1]])
    temp_zpca = np.array([event.zpca[0], event.zpca[1]])

    temp_assclu = np.array([event.assclu[0], event.assclu[1]])
    temp_logrl = np.array([event.logrl[0], event.logrl[1]])

    rhofh = np.sqrt(temp_xfirst**2 + temp_yfirst**2)
    rhopca = np.sqrt(temp_xpca**2 + temp_ypca**2)
    ptp = np.sqrt(pxtr_temp**2 + pytr_temp**2)

    if any(rhofh > 50) or any(rhopca >8) or any(np.abs(temp_zpca) > 12):
        flagdrch = False
    if np.any(np.abs(pztr_temp) < 90) or np.any(ptp < 160):
        flagp = False
    if np.any(pxtr_temp == 0):
        flagp = False
    if any(temp_assclu) == 0:
        flagass = False
    if temp_logrl[0] < 0 or temp_logrl[1] < 0:
        flaglog = False

    if (flagdrch == False or flagp == False or flagp == False or flagass == False or flaglog == False):
        continue

    pmodtr = np.sqrt(pxtr_temp**2 + pytr_temp**2 + pztr_temp**2)
    ephot = (event.pphix - (pxtr_temp[0] + pxtr_temp[1]))**2 + \
            (event.pphiy -(pytr_temp[0] + pytr_temp[1]))**2 + \
            (event.pphiz - (pztr_temp[0] + pztr_temp[1]))**2
    ephot = np.sqrt(ephot)
    eneb = np.sqrt(event.sqrts**2 + pmodb_val**2)

    asquared = (ephot-eneb)**2 - (pmodtr[0]**2+pmodtr[1]**2)
    asquared = 0.5*asquared

    trkms = (asquared**2 - pmodtr[0]**2*pmodtr[1]**2) / (2*asquared +(pmodtr[0]**2 + pmodtr[1]**2))
    trkms = np.sqrt(trkms)

    psx = pxtr_temp[0]+pxtr_temp[1]
    psy = pytr_temp[0]+pytr_temp[1]
    psz = pztr_temp[0]+pztr_temp[1]

    ps4 = np.sqrt(pmodtr[0]**2 + mpi**2) + np.sqrt(pmodtr[1]**2 + mpi**2)
    q2 = (ps4**2-psx**2-psy**2-psz**2)*1E-6

    h_trkms.Fill(trkms)
    h_qq.Fill(q2)
    h_qqtrkms.Fill(q2, trkms)

# Writing to ROOT file
h0_pxtr.Write()
h0_pxtr1.Write()
h0_pxtr2.Write()
h0_pytr.Write()
h0_pytr1.Write()
h0_pytr2.Write()
h0_pztr.Write()
h0_pztr1.Write()
h0_pztr2.Write()
h_trkms.Write()
h_qq.Write()
h_qqtrkms.Write()

root_file.Close()