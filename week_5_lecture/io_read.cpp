#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[])
{
    int row = 256, col = 256, ctr = 0;
    long size;
    std::string file_bin = "image";
    std::string file_txt = "image.txt";
    std::string temp;

    std::ifstream read_bin(file_bin, std::ios_base::in | std::ios_base::binary);
    if (!read_bin)
        EXIT_FAILURE;

    std::vector<int> buffer(row * col);
    std::vector<std::vector<int>> img_bin(row, std::vector<int>(col));
    for (auto &row : buffer)
    {
        read_bin.read(reinterpret_cast<char *>(&buffer.front()), buffer.size() * sizeof(buffer.front()));
    }
    read_bin.close();

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            img_bin[i][j] = buffer[(i + 1) * j];

    std::cout << "---> Reading from binary file: \n";
    std::cout << "img_bin[0][0]: " << img_bin[0][0] << std::endl;
    std::cout << "buffer[(0+1)*0]: " << buffer[0] << std::endl;
    std::cout << "img_bin[128][128]: " << img_bin[128][128] << std::endl;
    std::cout << "buffer[(128+1)*128]: " << buffer[129 * 128] << std::endl;
    std::cout << "img_bin[255][255]: " << img_bin[255][255] << std::endl;
    std::cout << "buffer[(255+1)*255]: " << buffer[256 * 255] << std::endl;

    std::vector<std::vector<int>> img_txt(row, std::vector<int>(col));
    std::ifstream read_txt(file_txt, std::ios_base::in);
    while (std::getline(read_txt, temp, ' '))
    {
        auto rm1 = std::find(temp.begin(), temp.end(), '[');
        auto rm2 = std::find(temp.begin(), temp.end(), ']');

        if (rm1 != std::end(temp) || rm2 != std::end(temp))
            continue;
        img_txt[ctr / 256][ctr % 256] = std::stoi(temp);
        ctr++;
    }
    std::cout << "---> Reading from txt file & Comparison: \n";

    std::cout << "img_bin[0][0]: " << img_bin[0][0] << "\timg_txt[0][0]: " << img_txt[0][0] << std::endl;
    std::cout << "img_bin[128][128]: " << img_bin[128][128] << "\timg_txt[128][128]: " << img_txt[128][128] << std::endl;
    std::cout << "img_bin[255][255]: " << img_bin[255][255] << "\timg_txt[255][255]: " << img_txt[255][255] << std::endl;

    return 0;
}
