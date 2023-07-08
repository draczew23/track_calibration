import ROOT
import numpy as np
import matplotlib.pyplot as plt
from BadRun import IsBadRun
from ROOT import gROOT

myFile = ROOT.TFile.Open("ppgphok5_stentu_pcadtm_all.root")
ROOT.ROOT.EnableImplicitMT()
gROOT.SetStyle("Bold")

ourTree = myFile.STENTU
h1 = ourTree.h1
branch_pxtr = h1.GetBranch("pxtr")
branch_pytr = h1.GetBranch("pytr")
branch_pztr = h1.GetBranch("pztr")
branch_Runnumber = h1.GetBranch("Runnumber")

BadRun_checker = IsBadRun()     # BadRun initialization

nentries = branch_pxtr.GetEntries()
print(nentries)

### Histogram parameters ###
bxsize = 1.
bxmin = -550.
bxmax = 550
bysize = 1e-2
bymin = 0
bymax = 1.
### Histogram parameters ###

how_many = 3    # number of values per leaf

# Creation of (3, nentries) arrays
# Columns: pxtr, pxtr1, pxtr2
 
pxtr = np.empty((0, how_many))
pytr = np.empty((0, how_many))
pztr = np.empty((0, how_many))

scaledown = 500000
nn = int(nentries/scaledown)
runnumber = np.array([])

# Test
hist = ROOT.TH1F("hist", "Histogram", int((bxmax-bxmin)/bxsize), int(bxmin), int(bxmax))

for i in range(nn):
    branch_pxtr.GetEntry(i)
    branch_pytr.GetEntry(i)
    branch_pztr.GetEntry(i)
    branch_Runnumber.GetEntry(i)

    runnumber = np.append(runnumber, branch_Runnumber.GetLeaf("Runnumber").GetValue(i))

    if BadRun_checker.is_bad_run(runnumber):
        continue

    temp_x = np.array([])
    temp_y = np.array([])
    temp_z = np.array([])

    for j in range(how_many):

        if (branch_pxtr.GetLeaf("pxtr").GetValue(j) * branch_pytr.GetLeaf("pytr").GetValue(j) * branch_pztr.GetLeaf("pztr").GetValue(j) != 0):
            hist.Fill(branch_pztr.GetLeaf("pztr").GetValue(j))
        temp_x = np.append(temp_x, branch_pxtr.GetLeaf("pxtr").GetValue(j))
        temp_y = np.append(temp_y, branch_pytr.GetLeaf("pytr").GetValue(j))
        temp_z = np.append(temp_z, branch_pztr.GetLeaf("pztr").GetValue(j))

    pxtr = np.vstack((pxtr, temp_x))
    pytr = np.vstack((pytr, temp_y))
    pztr = np.vstack((pztr, temp_z))

filter_ar = pxtr*pytr*pztr
filter_ar_condition = filter_ar != 0

pxtr_0 = np.array(pxtr[filter_ar_condition])
pytr_0 = np.array(pytr[filter_ar_condition])
pztr_0 = np.array(pztr[filter_ar_condition])

plt.hist(pxtr_0, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
plt.savefig("pxtr_0.png")
plt.clf()

plt.hist(pytr_0, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
plt.savefig("pytr_0.png")

plt.clf()
plt.hist(pztr_0, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
plt.savefig("pztr_0.png")

# canvas = ROOT.TCanvas("canvas", "Histogram Canvas", 800, 600)
# hist.Draw()
# canvas.Update()
# canvas.SaveAs("test_histogram.png")

filter_ar_prim = pxtr[:, 0]*pytr[:, 0]*pztr[:, 0]
filter_ar_condition = filter_ar_prim != 0

pxtr_filt = pxtr[:, 0]
pxtr_1 = pxtr_filt[filter_ar_condition]

pytr_filt = pytr[:, 0]
pytr_1 = pytr_filt[filter_ar_condition]

pztr_filt = pztr[:, 0]
pztr_1 = pztr_filt[filter_ar_condition]


plt.clf()
plt.hist(pxtr_1, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
plt.savefig("pxtr_1.png")

plt.clf()
plt.hist(pytr_1, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
plt.savefig("pytr_1.png")

plt.clf()
plt.hist(pztr_1, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
plt.savefig("pztr_1.png")

filter_ar_prim = pxtr[:, 1]*pytr[:, 1]*pztr[:, 1]
filter_ar_condition = filter_ar_prim != 0

pxtr_filt = pxtr[:, 1]
pxtr_2 = pxtr_filt[filter_ar_condition]

pytr_filt = pytr[:, 1]
pytr_2 = pytr_filt[filter_ar_condition]

pztr_filt = pztr[:, 1]
pztr_2 = pztr_filt[filter_ar_condition]

plt.clf()
plt.hist(pxtr_2, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
plt.savefig("pxtr_2.png")

plt.clf()
plt.hist(pytr_2, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
plt.savefig("pytr_2.png")

plt.clf()
plt.hist(pztr_2, bins=int((bxmax-bxmin)/bxsize), range=(int(bxmin), int(bxmax)), edgecolor='red', linewidth=1.5)
plt.savefig("pztr_2.png")


# plt.hist(k1, bins=int((bxmax-bxmin)/bxsize))
# plt.hist(k1[:, 0], bins=int((bxmax-bxmin)/bxsize))
# plt.clf()

# plt.hist(l, bins=int((bxmax-bxmin)/bxsize))
# plt.savefig("example1.png")
# plt.clf()

# plt.hist(m, bins=int((bxmax-bxmin)/bxsize))
# plt.savefig("example2.png")
# plt.clf()