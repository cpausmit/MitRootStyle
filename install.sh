#!/bin/bash
#---------------------------------------------------------------------------------------------------
# Install the shared library of the MitRootStyle so nobody has to make it.
#---------------------------------------------------------------------------------------------------


# root must be in the path
if [ "`which root`" == "" ]
then
  echo ""
  echo " ERROR - the program 'root' must be in your path. EXIT!"
  echo ""
  exit 0
fi 

root -l -q MitRootStyle.C+

exit 0