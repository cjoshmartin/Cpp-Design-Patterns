#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"


int main()
{
    Person::create()
            .lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
            .work().at("PragmaSoft").as_a("Consultant").earning(10e6);
    getchar();
    return 0;
}