#!/bin/tcsh
source /opt/phenix/bin/phenix_setup.csh
echo "jobs " $1 "start"

#set DIR=/data7/xueliang/eRD11/eic_rich/modular_rich/likelihood
set DIR=/data9/ping/eic/likelihood/
#set EXE=$DIR/bin/analysis
set EXE=$DIR/bin/analysis_data

set INPUTLIST=$DIR/input/G4_datalist/$1.list
set INPUTROOT = `cat $INPUTLIST`
#set ROOTFILE=`echo $INPUTROOT | awk -F/ '{print $10}'`
set ROOTFILE=`echo $INPUTROOT | awk -F/ '{print $7}'`  #cut out the filename
set OUTPUTROOT=$DIR/output/G4_data/$ROOTFILE

set THETA = `echo $ROOTFILE | awk '{split($0,A,"_"); print A[3]}'`
set PHI = `echo $ROOTFILE | awk '{split($0,A,"_"); print A[4]}'`
set DBFILE = $DIR/input/DB_$THETA'_'$PHI

echo "INPUT filelist: $INPUTLIST ;"
echo "INPUT rootfile: $INPUTROOT ;"
echo "INPUT DB file: $DBFILE ;"
echo "OUTPUT rootfile: $OUTPUTROOT ;"

$EXE $INPUTLIST $DBFILE $OUTPUTROOT 

echo "jobs " $1 " done ;"
