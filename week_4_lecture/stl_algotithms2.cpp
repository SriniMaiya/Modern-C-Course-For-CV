#include <iostream>
#include <algorithm>
#include <random>
int main(int argc, char const *argv[])
{
    const double MAX = 1.0F;
    const double MIN = 0.05F;

    std::cout << "---> 1. CLAMP";
    std::cout << "1.8 --> " << std::clamp(1.8, MIN, MAX) << std::endl;
    std::cout << "-0.25 --> " << std::clamp(-0.25, MIN, MAX) << std::endl
              << std::endl;
    std::cout << "---> 2. SAMPLE";

    std::string src = "This string is the source of the samples!", out;
    auto rand_dev = std::mt19937{std::random_device{}()};
    const int kNLetters = 12;

    std::sample(src.begin(), src.end(), std::back_inserter(out), kNLetters, rand_dev);
    std::cout << "Source string: " << src << "\n Result (rand str): " << out << std::endl;
    return 0;
}
