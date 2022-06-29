#include "homework_3.h"
#include <string>
#include <filesystem>
#include <iostream>
#include <istream>
#include <iomanip>

namespace fs = std::filesystem;
void html_writer::OpenDocument()
{
    std::cout << "<!DOCTYPE html>" << std::endl;
    std::cout << "<html>" << std::endl;
}
void html_writer::CloseDocument() { std::cout << "</html>" << std::endl; }

void html_writer::AddTitle(const std::string &title)
{
    std::cout << "<title>" << title << "</title>" << std::endl;
}

void html_writer::AddCSSStyle(const std::string &stylesheet)
{
    std::cout << "<head>" << std::endl
              << R"(<link rel="stylesheet" type="text/css" href=")" << stylesheet
              << R"(" />)" << std::endl;
    std::cout << "</head>" << std::endl;
}

void html_writer::OpenBody() { std::cout << "<body>" << std::endl; }
void html_writer::CloseBody() { std::cout << "</body>" << std::endl; }

void html_writer::OpenRow() { std::cout << "<div class=\"row\">" << std::endl; }
void html_writer::CloseRow() { std::cout << R"(</div>)" << std::endl; }

void html_writer::AddImage(const std::string &ImgPath, float score, bool highlight)
{
    fs::path fs_img_path(ImgPath);
    if (!fs::exists(fs_img_path))
    {
        std::cerr << "[ERROR] : Image " << fs_img_path << " does not exist!\n";
        exit(EXIT_FAILURE);
    }

    std::string fname = fs_img_path.filename();

    if (fname.find("jpg") == std::string::npos ||
        fname.find("png") == std::string::npos)
    {
        std::cerr << "[ERROR] : Incorrect image type!\n";
    }

    if (highlight)
        std::cout << R"(<div class="column" style="border: 5px solid green;">)"
                  << std::endl;
    else
    {
        std::cout << R"(<div class="column")" << std::endl;
    }
    std::cout << "<h2>" << fname << "</h2>" << std::endl;
    std::cout << R"(<img src=")" << fs_img_path << R"(" />)" << std::endl;
    std::cout << "<p>score = " << score << "</p>" << std::endl;
    std::cout << "</div>" << std::endl;
}
