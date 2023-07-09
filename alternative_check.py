import ROOT
import numpy as np
import matplotlib.pyplot as plt
from BadRun import IsBadRun
from ROOT import gROOT
from alternative_badrun import IsBadRun

bad_run_checker = IsBadRun()

myFile = ROOT.TFile.Open("ppgphok5_stentu_pcadtm_all.root")
ROOT.ROOT.EnableImplicitMT()
gROOT.SetStyle("Bold")

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

how_many = 2

pxtr = np.empty((0, how_many))
pytr = np.empty((0, how_many))
pztr = np.empty((0, how_many))
trkms_ar = np.array([])
q2_ar = np.array([])

ev_counter = 0
passed_events = 0

bymax = 1.
bymin = 0.
bysize = 1e-2

hist = ROOT.TH1F("hist", "Histogram", int((bymax-bymin)/bysize), int(bymin), int(bymax))

for event in h1:
    # print(ev_counter / nn)
    break_check = ev_counter < nn

    if not break_check:
        break
    ev_counter += 1
    
    if bad_run_checker.is_bad_run(event.Runnumber):
        continue

    pxtr_temp = np.array([event.pxtr[0], event.pxtr[1]])
    pytr_temp = np.array([event.pytr[0], event.pytr[1]])
    pztr_temp = np.array([event.pztr[0], event.pztr[1]])

    pxtr = np.vstack((pxtr, pxtr_temp))
    pytr = np.vstack((pytr, pytr_temp))
    pztr = np.vstack((pztr, pztr_temp))

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
    passed_events += 1

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
    print(psx, psy, psz, ps4, q2)

    trkms_ar = np.append(trkms_ar, trkms)
    q2_ar = np.append(q2_ar, q2)
    # hist.Fill(q2)
    # print(q2)

# canvas = ROOT.TCanvas("canvas", "Histogram Canvas", 800, 600)
# hist.Draw()
# canvas.Update()
# canvas.SaveAs("test_histogram.png")

      
bxmax = 250.
bxmin = 50. 
bxsize = 1

plt.hist(trkms_ar, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
plt.savefig("trkms.png")
plt.clf()

bymax = 1.
bymin = 0.
bysize = 1E-2
plt.hist(q2_ar, bins=int((bymax-bymin)/bysize), range=(int(bymin), int(bymax)), edgecolor='red', linewidth=1.5)
plt.savefig("q2.png")
plt.clf()

# plt.hist2d(q2_ar, trkms_ar, bins=[int((bxmax-bxmin)/bxsize), int((bymax-bymin)/bysize)], 
#            range=[np.array([int(bxmin), int(bxmax)]), np.array([int(bymin), int(bymax)])])
# plt.savefig("qqtrkms.png")
# plt.clf()

print(len(q2_ar), q2_ar.mean(), q2_ar.std())
# print(q2_ar)
print(passed_events)

print("---------------------------")
print(len(trkms_ar), trkms_ar.mean(), trkms_ar.std())
# print(trkms_ar)

# ptr_check = pxtr*pytr*pztr

# filter_ar_condition = ptr_check != 0

# pxtr_0 = np.array(pxtr[filter_ar_condition])
# pytr_0 = np.array(pytr[filter_ar_condition])
# pztr_0 = np.array(pztr[filter_ar_condition])

# plt.hist(pxtr_0, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
# plt.savefig("pxtr_0.png")
# plt.clf()

# plt.hist(pytr_0, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
# plt.savefig("pytr_0.png")

# plt.clf()
# plt.hist(pztr_0, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
# plt.savefig("pztr_0.png")


