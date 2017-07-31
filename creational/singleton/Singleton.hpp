#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <boost/lexical_cast.hpp>

class SingletonDatabase
{
    SingletonDatabase(){

        std::cout << "Initializing database" << std::endl;

        std::ifstream ifs("capitals.txt");

        std::string s,s2;
        while (std::getline(ifs,s))
        {
            getline(ifs,s2);
            int pop = boost::lexical_cast<int>(s2);
            capitals[s]=pop;

        }
        instance_count++;
    }
    std::map<std::string,int> capitals;

    static SingletonDatabase* instance;

public:
    static int instance_count;
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;

    static SingletonDatabase& get(){

        static SingletonDatabase db;
        return db;

    }
};

int SingletonDatabase::instance_count = 0;