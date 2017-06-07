

Attached is the likelihood analysis code I used. I made quite a lot modifications from Liang's code to simplify the work flow. Yet, it is still a complicated process. I wrote a few README files about the running procedures last year, I hope they help a bit.

 

Here I would like to clarify the difference between two labels, "data" (G4_data, G4_data.list, analysis_data, rundata.csh, etc) and "db" (G4_db, G4_db.list, analysis_db, rundb.csh, etc), which appear frequently throughout the directory. Codes or files with label "data" are used to generate 2D histograms, while codes or files with label "db" are used to generate 3D histograms. On making the 3D histogram, I need to source PHENIX setup to stack 2D histograms into 3D histogram. I am not sure how stacking work in ROOT alone.

 

A technical note, written by Liang, gives details on the Likelihood analysis and results. One way to familiar with the analysis code is to produce plots like figure 15-27 in the technical note. However, you will need to modify some numbers, such as hit position cut. Since the attached code still aims to the 1st prototype study. In the single modular RICH simulation study, the front side of sensor is at z=173.725mm. To figure out the position of each component, you can look up the position and half size in xyz of the components that are printed out on screen when configuring detector geometry ($ ./geometry.pl config.dat).

 

