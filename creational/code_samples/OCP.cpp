#include <string>

enum class Color {Red, Green, Blue};
enum class Size {Small, Medium, Large};

struct Product
{
    std::string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    typedef std::vector<Product*> Items;
    static Items by_color(Items items, Color color){
        Items result;
        for (auto& i :items)
            if(i->color == color )
                result.push_back(i);

        return result;
    } 
    
    static Items by_color_and_size(Items items, Color color){
        Items result;
        for (auto& i :items)
            if(i->color == color && ai->size == size)
                result.push_back(i);

        return result;
    } 
};
