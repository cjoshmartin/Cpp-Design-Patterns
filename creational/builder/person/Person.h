//
// Created by Josh Martin on 7/22/17.
//

#include <string>
using namespace std;

class PersonBuilder;

class Person
{
    // address
    string street_address, post_code, city;

    // employment
    string company_name,position;
    int annual_income = 0;

    Person(){} // can't build a person using this class, have to build a person using the builder class

public:

    static PersonBuilder create();

    Person(Person&& other)
            : street_address{move(other.street_address)},
              post_code{move(other.post_code)},
              city{move(other.city)},
              company_name{move(other.company_name)},
              position{move(other.position)},
              annual_income{other.annual_income}
    {
    }

    Person& operator=(Person&& other)
    {
        if (this == &other)
            return *this;
        street_address = move(other.street_address);
        post_code = move(other.post_code);
        city = move(other.city);
        company_name = move(other.company_name);
        position = move(other.position);
        annual_income = other.annual_income;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Person& obj)
    {
        return os
                << "street_address: " << obj.street_address
                << " post_code: " << obj.post_code
                << " city: " << obj.city
                << " company_name: " << obj.company_name
                << " position: " << obj.position
                << " annual_income: " << obj.annual_income;
    }

    static PersonBuilder create();

    friend class PersonBuilder;
    friend class PersonAddressBuilder;
    friend class PersonJobBuilder;
};
