#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;
int main()
{
    // <p> hello </p>
    auto text = "hello";
    string output;
    output += "<p>";
    output += text;
    output += "</p>";

    printf("<p>%s</p>", text);

    string words[] = {"hello","world"};


    ostringstream oss;
    oss << "<ul>";
    for (auto w : words)
        oss << " <li>" << w << "</li>";

    oss << "</ul>";

    printf(oss.str().c_str());

    getchar();
    return 0;
}