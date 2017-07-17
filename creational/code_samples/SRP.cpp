#include <string>
#include <vector>
#include <fstream>

struct Journal
{
 std::string title;
 std::vector<std::string> entries;

 explicit Journal(const std::string& title)
     : title{title};
     {
     }

     void add(const std::string& entry)
     {
        entries.push_back(entry);
     }

     void save(const std::string& filename)
     {
         // don't  make a function like this inside a struct like this one 
        std::ofstream ofs(filename);
        for (auto& s: entries)
            ofs << s << std::endl;
     }
};
