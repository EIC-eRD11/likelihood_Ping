#!/bin/tcsh 
source /opt/phenix/bin/phenix_setup.csh
echo Merge G4_data histograms
#-------- set path to input files --------#
set DIR = /data9/ping/eic/likelihood
cd $DIR/output/G4_data

#-------- initialize momenta and angles -----------#
set mom = (3.0 3.2 3.4 3.6 3.8 4.0 4.2 4.4 4.6 4.8 \
           5.0 5.2 5.4 5.6 5.8 6.0 6.2 6.4 6.6 6.8 \
           7.0 7.2 7.4 7.6 7.8 8.0 8.2 8.4 8.6 8.8 \
           9.0 9.2 9.4 9.6 9.8 10.0 10.2 10.4 10.6 10.8 \
           11.0 11.2 11.4 11.6 11.8 12.0 12.2 12.4 12.6 12.8 \
           13.0 13.2 13.4 13.6 13.8 14.0 14.2 14.4 14.6 14.8 15.0)
set PHI = 45

#--------------------- foreach THETA ----------------------#
set OUTPUTFILE = $DIR/output/reproduced_G4_data_all.root
#echo 'OUPUTFILE= '$OUTPUTFILE
set INPUT_STRING =""

foreach  THETA (5 25 45)
#--------------- foreach PARTICLE ----------------#
foreach PARTICLE ("pi-" "kaon-" "proton")
#echo $PARTICLE' :'
set i=1

#-----------while (i)---------#
while ($i<62)
set SINGLE_INPUTFILE = $PARTICLE'_'$mom[$i]'GeV_theta'$THETA'_phi'$PHI'.root'
if (-e $SINGLE_INPUTFILE) then
#echo 'i= '$i
#echo 'add input file : '$SINGLE_INPUTFILE
set INPUT_STRING = "$INPUT_STRING $SINGLE_INPUTFILE"
#echo 'INPUT_STRING= '$INPUT_STRING
endif
@ i++
end #end of while

end #end of foreach Particle

end #end of foreach THETA

#echo do -- hadd $OUTPUTFILE $INPUT_STRING
hadd $OUTPUTFILE $INPUT_STRING

