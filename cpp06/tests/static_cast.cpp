#include <iostream>

class Animal {};
class Cat : public Animal {};
class Dog : public Animal {};

class Random {};

int main (void) {
	{
		int a = 42;

		double b = a;					//implicit promotion - Ok
		//int c = b;					//implicit demotion - No!!!
		int d = static_cast<int>(b);	//Explicit demotion - Ok, I obey
	}
	{
		Cat cat;
	
		Animal* ani = &cat;						//Implicit upcast - ok
		//Cat* cat2 = ani;						//Implicit downcast - No!!! Won't compile
		Dog* dog = static_cast<Dog*>(ani);		//Explicit downcast - Ok, I obey

		//Random* random = static_cast<Random*>(&cat);	//Explicit conversion - No!!!
	}
}

// c++ -Wall -Wextra -Werror -Wno-unused -Wconversion -Werror static_cast.cpp