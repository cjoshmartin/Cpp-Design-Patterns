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
	static Contact main,aux; // Main Office and Auxiliary Office
	static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suite) // a smart pointer function makes it easier to deep copy
	{
		return NewEmployee(name,suite, main);
	}

	static unique_ptr<Contact> NewAuxOfficeEmployee(string name, int suite) // a smart pointer function makes it easier to deep copy
	{
		return NewEmployee(name,suite, aux);
	}
private:
	static unique_ptr<Contact> NewEmployee(string name, int suite, Contact& proto)
	{
		auto result = make_unique<Contact>(proto);
		result->name= name;
		result->work_address->suite = suite;
		return result;
	}
};

Contact EmployeeFactory::main{"",new Address{"123 East Dr", "London", 0}};
Contact EmployeeFactory::aux{"",new Address{"123B East Dr", "London", 0}};


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