#!/bin/tcsh
source /opt/phenix/bin/phenix_setup.csh
echo "jobs " $1 "start"

#set DIR=/data7/xueliang/eRD11/eic_rich/modular_rich/likelihood
set DIR=/data9/ping/eic/likelihood/
#set EXE=$DIR/bin/analysis
set EXE=$DIR/bin/analysis_db

set INPUTLIST=$DIR/input/G4_dblist/$1.list
set INPUTROOT = `cat $INPUTLIST`
#set ROOTFILE=`echo $INPUTROOT | awk -F/ '{print $10}'`
set ROOTFILE=`echo $INPUTROOT | awk -F/ '{print $7}'`
set OUTPUTROOT=$DIR/output/G4_db/$ROOTFILE

$EXE $INPUTLIST $OUTPUTROOT 

echo "jobs " $1 " done ;"
