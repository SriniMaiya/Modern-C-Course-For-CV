#include "random.hpp"
#include <iostream>
#include <ctime>
#include <bitset>
int number()
{
    std::srand(std::time(0));
    int rno = rand() % 10000 + 1;
    std::cout << "Random number between 0-100: " << rno << std::endl;
    return rno;
}

void number_in_bin(int a)
{
    std::string binary = std::bitset<16>(a).to_string();
    std::cout
        << a << " in binary:  " << binary << std::endl;
}