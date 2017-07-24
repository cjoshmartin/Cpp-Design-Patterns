#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct Address {
	string street;
	string city; 
}

struct Contact{
	string name;
	Address* work_address;

}

int main()
{
Contact john{"John Doe", new Address{"123 East dr",}}
getchar();
return 0;
}