## MIT Root Style

This is a standalone setup to help styling your root plots in a reasonable way. The package consists really of one core file which defines and implements the MitRootStyle class. The implementation is done with inline statements.


## Installation

  cd MitRootStyle

  ./install.sh
  
This will compile the class and creates a shared library that can be loaded in your subsequent root sessions. The compilation requires root and g++ to be installed (gcc, gcc_c++). Otherwise it will fail.

The installation also creates a configuration file (setup.sh) which will when source setup the MIT_ROOT_STYLE environment variable to easily load this package in your subsequent root sessions.


## Setup for your root sessions

First source setup.sh then make sure to load the shared libraries following the rootlogon.C file.


## Requirements

### Packages

* the root and the gcc, gcc-c++ compilers