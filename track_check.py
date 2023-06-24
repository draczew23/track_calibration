import numpy as np
import os
import glob
import uproot

rad2deg = 57.29578
mpi = 139.56995
mmu = 105.65839

my_place = os.getcwd()  # find my path location
os.chdir(my_place)  # change the path to the working directory

our_files = []  # list of our data files
files_list = os.listdir(my_place)  # list of our data files)

for file in files_list:  # creating list of files
    file_path = os.path.join("", file)  # construct the full file path
    if os.path.isfile(file_path) and file.startswith("ppg"):
        our_files.append(file)

### Histogram parameters ###
bxsize = 1.
bxmin = -550.
bxmax = 550
bysize = 1e-2
bymin = 0
bymax = 1.
### Histogram parameters ###

if our_files:   # check if we have an empty list
    print("Non empty")
    for datafile in our_files:
        print("----------------------")
        print("Loading file: " + datafile)
        print("----------------------")
        with uproot.open(datafile) as file:

            file_keys = file.keys()
            key_to_find = "STENTU/h1"

            tree = file[key_to_find]
            nentries = tree.num_entries
            print("Number of entries " + str(nentries))

            pmodb = 0
            eneb = 0
            rhofh = np.zeros(2)
            rhopca = np.zeros(2)
            ptp = np.zeros(2)
            pmodtr = np.zeros(2)
            ephot = 0
            asquared = 0
            trkms = 0
            psx = 0
            psy = 0
            psz = 0
            ps4 = 0
            q2 = 0

            scaledown = 5
            nn = nentries/scaledown
            k = tree['pztr']
            print(tree)
else:
    print("empty file list")

