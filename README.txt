###################################################################################
#                                                                                 #
#                                    README                                       #
#                                                                                 #
#---------------------------------------------------------------------------------#
#  NOMAD - Nonlinear Optimization by Mesh Adaptive Direct Search -                #
#                                                                                 #
#  NOMAD - Version 4.0 has been created by                                        #
#                 Viviane Rochon Montplaisir  - Polytechnique Montreal            #
#                 Christophe Tribes           - Polytechnique Montreal            #
#                                                                                 #
#  The copyright of NOMAD - version 4.0 is owned by                               #
#                 Charles Audet               - Polytechnique Montreal            #
#                 Sebastien Le Digabel        - Polytechnique Montreal            #
#                 Viviane Rochon Montplaisir  - Polytechnique Montreal            #
#                 Christophe Tribes           - Polytechnique Montreal            #
#                                                                                 #
#  NOMAD v4 has been funded by Rio Tinto, Hydro-Québec, Huawei-Canada,            #
#  NSERC (Natural Sciences and Engineering Research Council of Canada),           #
#  InnovÉÉ (Innovation en Énergie Électrique) and IVADO (The Institute            #
#  for Data Valorization)                                                         #
#                                                                                 #
#  NOMAD v3 was created and developed by Charles Audet, Sebastien Le Digabel,     #
#  Christophe Tribes and Viviane Rochon Montplaisir and was funded by AFOSR       #
#  and Exxon Mobil.                                                               #
#                                                                                 #
#  NOMAD v1 and v2 were created and developed by Mark Abramson, Charles Audet,    #
#  Gilles Couture, and John E. Dennis Jr., and were funded by AFOSR and           #
#  Exxon Mobil.                                                                   #
#                                                                                 #
#  Contact information:                                                           #
#    Polytechnique Montreal - GERAD                                               #
#    C.P. 6079, Succ. Centre-ville, Montreal (Quebec) H3C 3A7 Canada              #
#    e-mail: nomad@gerad.ca                                                       #
#                                                                                 #
#  This program is free software: you can redistribute it and/or modify it        #
#  under the terms of the GNU Lesser General Public License as published by       #
#  the Free Software Foundation, either version 3 of the License, or (at your     #
#  option) any later version.                                                     #
#                                                                                 #
#  This program is distributed in the hope that it will be useful, but WITHOUT    #
#  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or          #
#  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License    #
#  for more details.                                                              #
#                                                                                 #
#  You should have received a copy of the GNU Lesser General Public License       #
#  along with this program. If not, see <http://www.gnu.org/licenses/>.           #
#                                                                                 #
#  You can find information on the NOMAD software at www.gerad.ca/nomad           #
#---------------------------------------------------------------------------------#

DESCRIPTION:

NOMAD is a C++ implementation of the Mesh Adaptive Direct Search (MADS)
algorithm, designed for constrained optimization of black-box functions.

The algorithms implemented are based on the book
"Derivative-Free and Blackbox Optimization", by Charles Audet and Warren Hare,
Springer 2017.


WEB PAGE:

https://www.gerad.ca/nomad/


CONTACT:

nomad@gerad.ca


COMPILATION (Release):

On Linux, Unix, and Mac OS X, NOMAD can be compiled using CMake.
The minimum version of CMake is 3.14. Older versions will trigger
an error. A recent C++ compiler is also required.

The procedure is the following. On the command line in the
 $NOMAD_HOME directory:

cmake -S . -B build/release     ---> Create the CMake files and directories for
                                     building (-B) in build/release.
                                     The source (-S) CMakeLists.txt file is in
                                       the $NOMAD_HOME directory.
                                     To enable time stats build:
                                       cmake -DTIME_STATS=ON -S . -B build/release
                                     To enable interfaces (C and Python) building:
                                       cmake -DBUILD_INTERFACES=ON -S . -B build/release
                                     To deactivate compilation with OpenMP:
                                       cmake -DTEST_OPENMP=OFF -S . -B build/release


cmake --build build/release     ---> Build the libraries and applications
                                     Option --parallel xx can be added for faster
                                     build

cmake --install build/release   ---> Copy binaries and headers in
                                     build/release/[bin, include, lib]
                                     and in the examples/tests directories

The executable "nomad" will installed into the directory:
build/release/bin/  (build/debug/bin/ when in debug mode).

It is possible to build only a single application in its working directory:
(with NOMAD_HOME environment variable properly set)

cd $NOMAD_HOME/examples/basic/library/example1
cmake --build $NOMAD_HOME/build/release --target example1_lib.exe
cmake --install $NOMAD_HOME/build/release

COMPILATION (Debug):

The procedure to build the debug version is the following.
On the command line in the $NOMAD_HOME directory:

cmake -S . -B build/debug -D CMAKE_BUILD_TYPE=Debug

cmake --build build/debug     ---> Build the libraries and applications
                                     Option --parallel xx can be added for faster
                                     build

cmake --install build/debug   ---> Copy binaries and headers in
                                     build/debug/[bin, include, lib]
                                     and in the examples/tests directories

EXAMPLES OF OPTIMIZATION:

Batch Mode:
There are examples in batch mode in examples/basic/batch/.
In each directory, the blackbox (usually named bb.exe) may be compiled using
the provided makefile.
The problem may be resolved using NOMAD and the parameter file:
nomad param.txt

Library Mode:
There are examples in library mode in examples/basic/library/.
In each directory, the executable may be compiled when building
Nomad application. The problems may be resolved by execution,
for instance:
example_lib.exe
