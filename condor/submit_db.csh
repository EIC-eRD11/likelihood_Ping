#!/bin/csh 

#set DIR = /data9/ping/eic/modularRICH_condor/script
set DIR = /data9/ping/eic/likelihood/condor

set FILE = $DIR/processdb.con

#set i = 1
set i = 0
set numFile =`ls -1 /data9/ping/eic/likelihood/input/G4_dblist | wc -l`

while ($i<numFile)
#while ($i<62)
if (-e $FILE) then
rm $FILE
endif
touch $FILE
echo "Universe        = vanilla" >> $FILE
echo "GetEnv          = True" >> $FILE
echo "Notification    = Error" >> $FILE
echo "Notify_user     = cwong14@student.gsu.edu" >> $FILE
echo "Priority        = +0" >> $FILE
echo "Initialdir      = $DIR" >> $FILE 
echo "Executable      = $DIR/rundb.csh" >> $FILE
echo "Arguments       = $i" >> $FILE
echo 'Log             = '$DIR/rundb_log/ver$i'.log' >> $FILE
echo 'Output          = '$DIR/rundb_log/ver$i'.out' >> $FILE
echo 'Error           = '$DIR/rundb_log/ver$i'.err' >> $FILE
echo '+Experiment     = "phenix"' >> $FILE
echo '+Job_Type       = "gsu"' >> $FILE
echo "Queue    1" >> $FILE
@ i++
condor_submit $FILE
end
end
