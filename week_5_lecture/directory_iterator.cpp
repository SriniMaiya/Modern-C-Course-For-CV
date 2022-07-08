#include <filesystem>
#include <iostream>
#include <fstream>
namespace fs = std::filesystem;

int main(int argc, char const *argv[])
{
    fs::create_directories("sandbox/a/b");
    fs::create_directories("sandbox/b/a");

    std::ofstream("sandbox/a/f1.txt");
    std::ofstream("sandbox/f1.txta");
    std::ofstream("sandbox/b/f22.txt");
    std::ofstream("sandbox/f1221.txtb");

    for (auto &path : fs::directory_iterator("sandbox"))
    {
        std::cout << "\t----> Path: " << path.path() << "\n";
        std::cout << "filename: " << path.path().filename() << "\tstem: " << path.path().stem() << "\textension: " << path.path().extension() << "\tDirectory: "
                  << path.is_directory() << "\tAbsolute Path ?: " << path.path().is_absolute() << "\tRelative Path ?: " << path.path().is_relative()
                  << std::endl
                  << std::endl;
    }
    if (fs::exists("sandbox"))
        fs::remove_all("sandbox");
    return 0;
}
