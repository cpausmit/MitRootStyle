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

# compile the package
root -l -q MitRootStyle.C+

# generate the setup file
rm -f setup.sh
touch setup.sh
echo "# CAREFUL THIS FILE IS GENERATED AT INSTALL" >> setup.sh
echo "export MIT_ROOT_STYLE="`pwd`                 >> setup.sh
echo ""                                            >> setup.sh

exit 0
