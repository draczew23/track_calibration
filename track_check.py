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
files_list = os.listdir(my_place) # list of our data files)

for file in files_list: # creating list of files
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

if our_files:
    print("Non empty")
else:
    print("empty file list")

print(our_files)
