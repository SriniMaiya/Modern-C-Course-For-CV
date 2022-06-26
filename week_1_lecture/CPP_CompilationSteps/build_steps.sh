echo "Precompilation with -E flag: g++ -E main.cpp > main.i"
g++ -E main.cpp > main.i
echo "Compilation of expanded program (main.i) to main.s with -S flag: g++ -S main.i > main.s"
g++ -S main.i > main.s
echo "Compiled program (main.s) to Assembly(main.o) with -c flag: g++ -c main.i"
g++ -c main.s
echo "Linking of main.o to executable: g++ main.o -o main"
g++ main.o -o main

