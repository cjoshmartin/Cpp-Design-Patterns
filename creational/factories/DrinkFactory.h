#pragma once

#include <string>
#include <map>
using namespace std;
struct HotDrink;

class DrinkFactory
{
    map<string, unique_ptr<HotDrinkFactory>> factories;
public:

    DrinkFactory()
    {
        factories["coffee"] = make_unique<CoffeeFactory>();
        factories["tea"] = make_unique<TeaFactory>();
    }
 unique_ptr<HotDrink> make_drink(const string& name)
 {
     auto drink = factories[name]->make();
     drink->prepare(200); // fix, maybe!
     return drink;
};
