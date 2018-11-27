#!/bin/bash

reset
pwd

g++ -fexceptions -std=c++11 -g -I../src corrupt.cpp                       -o  corrupt
g++ -fexceptions -std=c++11 -g -I../src wikipedia-pbm-ca.cpp              -o  wikipedia-pbm-ca
g++ -fexceptions -std=c++11 -g -I../src wikipedia-pbm-raw.cpp             -o  wikipedia-pbm-raw
g++ -fexceptions -std=c++11 -g -I../src wikipedia-pbm-vector.cpp          -o  wikipedia-pbm-vector
g++ -fexceptions -std=c++11 -g -I../src wikipedia-pbm-vector-save.cpp     -o  wikipedia-pbm-vector-save
g++ -fexceptions -std=c++11 -g -I../src wikipedia-pgm-ca.cpp              -o  wikipedia-pgm-ca
g++ -fexceptions -std=c++11 -g -I../src wikipedia-pgm-raw.cpp             -o  wikipedia-pgm-raw
g++ -fexceptions -std=c++11 -g -I../src wikipedia-pgm-vector.cpp          -o  wikipedia-pgm-vector
g++ -fexceptions -std=c++11 -g -I../src wikipedia-pgm-vector-save.cpp     -o  wikipedia-pgm-vector-save
g++ -fexceptions -std=c++11 -g -I../src wikipedia-ppm-ca.cpp              -o  wikipedia-ppm-ca
g++ -fexceptions -std=c++11 -g -I../src wikipedia-ppm-raw.cpp             -o  wikipedia-ppm-raw
g++ -fexceptions -std=c++11 -g -I../src wikipedia-ppm-vector.cpp          -o  wikipedia-ppm-vector
g++ -fexceptions -std=c++11 -g -I../src wikipedia-ppm-vector-save.cpp     -o  wikipedia-ppm-vector-save
g++ -fexceptions -std=c++11 -g -I../src wikipedia-probe.cpp               -o  wikipedia-probe

g++ -fexceptions -std=c++11 -g -I../src readme-01.cpp  -o readme-01
g++ -fexceptions -std=c++11 -g -I../src readme-02.cpp  -o readme-02
g++ -fexceptions -std=c++11 -g -I../src readme-03.cpp  -o readme-03
g++ -fexceptions -std=c++11 -g -I../src readme-04.cpp  -o readme-04
g++ -fexceptions -std=c++11 -g -I../src readme-05.cpp  -o readme-05


g++ -fexceptions -std=c++11 -g -I../src save-to-all-P1.cpp    -o save-to-all-P1
g++ -fexceptions -std=c++11 -g -I../src save-to-all-P2.cpp    -o save-to-all-P2
g++ -fexceptions -std=c++11 -g -I../src save-to-all-P3.cpp    -o save-to-all-P3