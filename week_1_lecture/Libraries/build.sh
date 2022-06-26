








g++ -c random.cpp -o random.o
ar rcs librandom.a random.o
g++ -std=c++17 main.cpp -L . -lrandom -o main
./main 
