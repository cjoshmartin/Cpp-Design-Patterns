#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct Address {
	string street;
	string city;
	int suite;


	friend std::ostream& operator<<(std::ostream& os, const Address& obj)
	{
		return os
			<< "street: " << obj.street
			<< " city: "  << obj.city
			<< " suite: " << obj.suite;
	}
};

struct Contact{
	string name;
	Address* work_address;

	Contact(const string& name, Address* const work_address) // this construct is so that John and Jane still work.
			: name{name},
			  work_address{new Address{*work_address}} {}

	Contact(const Contact& other) // this construct is how Jill works
			: name{other.name},
			work_address(new Address{*other.work_address}) {}

	~Contact(){
		delete work_address;
	}

	friend std::ostream& operator<<(std::ostream& os, const Contact& obj)
	{
		return os
			<< "name: " 		 << obj.name
			<< " work_address: " << *obj.work_address;
	}
};

struct  EmployeeFactory
{
	static unique_ptr<Contact> NewMainOfficeEmployee() // a smart pointer function makes it easier to deep copy
	{
		static Contact employee{"", new Address{"124 East Drive", "London", 0}}; // employee prototype
		return make_unique<Contact(employee)>; // passes a COPY of employee
	}
};

int main()
{

	/*
	Contact john{ employee }; // copying the prototype into john
	john.name="John"; // customizing the john contact, by replace the name with `John`
	john.work_address->suite =100;

	Contact jane{ employee };
	jane.name = "Jane";
	jane.work_address->suite = 123;

	cout << john << endl << jane << endl;*/

	auto john = EmployeeFactory::NewMainOfficeEmployee();
	john->name = "John";
	

	getchar();
	return 0;
}