#include <fstream>
#include <vector>
#include <iomanip>
#include <random>
#include <iostream>

int main(int argc, char const *argv[])
{
    int row = 256, col = 256;
    std::string fname_bin = "image";
    std::string fname_txt = "image.txt";

    std::vector<std::vector<int>> img(row, std::vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            img[i][j] = rand() % 256 + 0;
    }

    std::ofstream out_bin(fname_bin, std::ios::binary | std::ios::out);
    std::ofstream out_txt(fname_txt);

    std::cout << "--> Writing to binary file\n";
    if (!out_bin.is_open())
        EXIT_FAILURE;

    for (auto &it : img)
    {
        out_bin.write(reinterpret_cast<char *>(&it.front()), it.size() * sizeof(int));
    }

    std::cout << "--> Writing to txt file \n";
    if (!out_txt.is_open())
        EXIT_FAILURE;

    for (auto &it_outer : img)
    {
        out_txt << "[ ";
        for (auto &elem : it_outer)
            out_txt << elem << " ";
        out_txt << "]\n";
    }
    return 0;
}
