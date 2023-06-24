import ROOT
import numpy as np
import matplotlib.pyplot as plt

myFile = ROOT.TFile.Open("ppgphok5_stentu_pcadtm_all.root")
ROOT.ROOT.EnableImplicitMT()

ourTree = myFile.STENTU
h1 = ourTree.h1
branch = h1.GetBranch("pxtr")
print(branch)
nentries = branch.GetEntries()
print(nentries)

### Histogram parameters ###
bxsize = 1.
bxmin = -550.
bxmax = 550
bysize = 1e-2
bymin = 0
bymax = 1.
### Histogram parameters ###

how_many = 3

pxtr = np.empty((0, how_many))
pytr = np.empty((0, how_many))
pztr = np.empty((0, how_many))

scaledown = 500000
nn = int(nentries/scaledown)
for i in range(nn):
    branch.GetEntry(i)

    temp_x = np.array([])
    temp_y = np.array([])
    temp_z = np.array([])

    for j in range(how_many):

        temp_x = np.append(temp_x, branch.GetLeaf("pxtr").GetValue(j))
        temp_y = np.append(temp_y, branch.GetLeaf("pxtr").GetValue(j))
        temp_z = np.append(temp_z, branch.GetLeaf("pxtr").GetValue(j))

    pxtr = np.vstack((pxtr, temp_x))
    pytr = np.vstack((pytr, temp_y))
    pztr = np.vstack((pztr, temp_z))

filter_ar = pxtr*pytr*pztr
filter_ar_condition = filter_ar != 0

k = np.array(pxtr[filter_ar_condition])

plt.hist(k, bins=int((bxmax-bxmin)/bxsize))
plt.savefig("example.png")
