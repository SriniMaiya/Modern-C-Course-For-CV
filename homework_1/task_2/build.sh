#!/usr/bin/bash
echo "Build Script"
c++ -c -I include/ src/sum.cpp -o build/sum.o
echo "  --> Built sum.o in build/sum.o"
c++ -c -I include/ src/subtract.cpp -o build/subtract.o
echo "  --> Built subtract.o in build/subtract.o"
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o
echo "  --> Combining sum.o & subtract.o modules into libipb_arithmetic.a library. Created in build/libipb_arithmetic.a"
c++ -std=c++17 -I include/ src/main.cpp -o results/bin/main -L build/ build/libipb_arithmetic.a
echo "	--> Building 'main' at results/bin/main"
echo "-> Done! <-"
