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
			  work_address{work_address} {}

	Contact(const Contact& other) // this construct is how Jill works
			: name{other.name},
			work_address(new Address{*other.work_address}) {}

	~Contact(){
		//delete work_address;
	}

	friend std::ostream& operator<<(std::ostream& os, const Contact& obj)
	{
		return os
			<< "name: " 		 << obj.name
			<< " work_address: " << *obj.work_address;
	}
};

int main()
{
    Address* addr = new Address{"123 East Dr", "London" }; // want to prototype

	Contact john{"John Doe",addr};
	john.work_address->suite=100;

	Contact jane{"Jane Doe",addr};
	jane.work_address->suite=123;

	cout << john << endl << jane <<endl;   // print john and jane to have the same suit address ( that is not what we want ).
										  //  The problem comes from that we are shallow copying all the everything
										 //   which means, copies the address of pointers not the value of said pointer
										//	  ==> john.work_address <===> jane.work_address
	Contact jill { jane };
	jill.work_address->suite = 1000;
	cout << jill << endl; 				//   However this will work because of the new constructor have added
									   //	 allowing us to deep copy the pointer.
	delete addr;

	getchar();
	return 0;
}