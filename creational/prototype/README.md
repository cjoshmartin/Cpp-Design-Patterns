 # Prototype 
 - A partially or fully initialized object that you can clone and make use of.
 - Always uses deep copy and not shallow copy
 ## Implement 
 construct an object and store it somewhere
 
 ## Using Prototypes 
 Clone the prototype and then customize the instance
 ```c++
 
 	static Contact employee{"", new Address{"124 East Drive", "London", 0}}; 
 	
 	Contact john{ employee }; // copying the prototype into john
	
	john.name="John"; // customizing the john contact, by replace the name with `John`
	john.work_address->suite =100;
	
	Contact jane{ employee };
	
	jane.name = "Jane";
	jane.work_address->suite = 123;
	
 ```
 
