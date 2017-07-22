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

    cout << output << endl;

    getchar();
    return 0;
}