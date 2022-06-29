#include <iostream>
#include <stdio.h>
#include <string>

int main(int argc, char const *argv[])
{
    // std::cout << argc << "\n"
    //           << argv[0] << std::endl
    //           << argv[1];

    std::string value[2];
    std::string extension[2];
    if (argc != 3)
    {
        std::cerr << "Pass only two arguments!" << std::endl;
        return -1;
    }

    for (auto i = 0; i < argc - 1; i++)
    {
        value[i] = argv[i + 1];
        // std::cout << value[i] << std::endl;

        size_t pos = value[i].find(".");
        extension[i] = value[i].substr(pos + 1, value->length());
        // std::cout << extension[i] << std::endl;
        value[i] = value[i].substr(0, value[i].find("."));
        // std::cout << value[i] << std::endl;
    }

    if ((extension[0] == "txt") && (extension[1] == "txt"))
    {
        std::cout << (std::stof(value[0]) + std::stof(value[1])) / 2 << std::endl;
    }

    else if ((extension[0] == "png") && (extension[1] == "png"))
    {
        std::cout << std::stof(value[0]) + std::stof(value[1]) << std::endl;
    }

    else if ((extension[0] == "txt") && (extension[1] == "png"))
    {
        std::cout << std::stoi(value[0]) % std::stoi(value[1]) << std::endl;
    }
    else
        std::cerr << "Check the extensions!" << std::endl;

    return 0;
}
