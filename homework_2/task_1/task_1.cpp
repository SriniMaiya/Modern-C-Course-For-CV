#include <iostream>

int main(int argc, char const *argv[])
{
    std::srand(time(0));
    int random = std::rand() % 99 + 0;
    int guess = -1;

    while (guess != random)
    {
        if ((guess > 0) && (guess < 99))
        {
            std::cout << "Your guess is " << ((guess < random) ? "less" : "greater")
                      << " than the Number!" << std::endl;
        }
        std::cout << "Guess the number: ";
        std::cin >> guess;

        if (std::cin.fail())
        {
            std::cout << "Error encountered, exiting..." << std::endl;
            return -1;
        }

        if (guess > 99 || guess < 0)
            std::cout << "[WARNING] : Number must be between 0 and 99" << std::endl;
    }

    std::cout << "Correct! The generated number was: " << random << std::endl;
    return 0;
}
