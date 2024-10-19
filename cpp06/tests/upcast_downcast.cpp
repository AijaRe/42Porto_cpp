#include <iostream>

class Animal {};
class Cat : public Animal {};
class Dog : public Animal {};

int main (void) {
	Cat cat;
	
	Animal* ani = &cat;  //Implicit upcast - ok
	Cat* cat2 = ani;    //Implicit downcast - No!!! Won't compile
	Dog* dog = (Dog*)ani; //Explicit downcast - Ok, but can lead to undefined behavior if b does not actually point to a Dog object
	
	return 0;
}