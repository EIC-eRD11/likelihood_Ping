#!/bin/csh 

set DIR = /data9/ping/eic/likelihood/condor
set FILE = $DIR/processdata.con

#set i = 1
set i = 0
set numFile =`ls -1 /data9/ping/eic/likelihood/input/G4_datalist | wc -l` 
while ($i<$numFile)
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
echo "Executable      = $DIR/rundata.csh" >> $FILE
echo "Arguments       = $i" >> $FILE
echo 'Log             = '$DIR/rundata_log/$i'.log' >> $FILE
echo 'Output          = '$DIR/rundata_log/$i'.out' >> $FILE
echo 'Error           = '$DIR/rundata_log/$i'.err' >> $FILE
echo '+Experiment     = "phenix"' >> $FILE
echo '+Job_Type       = "gsu"' >> $FILE
echo "Queue    1" >> $FILE
@ i++
condor_submit $FILE
end
end
