#include "homework_3.h"
#include <iostream>

using namespace image_browser;
using namespace html_writer;

void image_browser::AddFullRow(const ImageRow &row, bool first_row)
{
    OpenRow();
    int counter = 0;
    bool highlight;

    for (const auto &scored_image_tuple : row)
    {
        counter++;
        if (counter == 1 && first_row)
            highlight = true;
        else
            highlight = false;

        auto [img_path, score] = scored_image_tuple;

        AddImage(img_path, score, highlight);
    }
    CloseRow();
}

void image_browser::CreateImageBrowser(const std::string &title,
                                       const std::string &stylesheet,
                                       const std::vector<ImageRow> &rows)
{
    OpenDocument();
    AddTitle(title);
    AddCSSStyle(stylesheet);
    OpenBody();
    int counter = 0;
    for (const auto &row : rows)
    {
        counter++;
        if (counter == 1)
            image_browser::AddFullRow(row, true);
        else
            image_browser::AddFullRow(row, false);
    }
    CloseBody();
    CloseDocument();
}