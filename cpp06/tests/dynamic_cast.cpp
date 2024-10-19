#include <iostream>
#include <typeinfo>
#include <exception>

//Dynamic cast happens at runtime, not compilation
//Only works with polymorphism -> at least one virtual function

class Animal {public: virtual ~Animal(void){}};
class Cat : public Animal {};
class Dog : public Animal {};

int main (void) {
    Cat cat;
    Animal* animal = &cat;       //Implicit upcast - Ok

    //Explicit downcast
    Cat* cat2 = dynamic_cast<Cat*>(animal);
    if (cat2 == NULL){
        std::cout << "Explicit Cat downcast not ok" << std::endl;
    }
    else {
        std::cout << "Explicit Cat downcast is ok" << std::endl; //x
    }

    //Explicit downcast
    try {
        Dog& dog = dynamic_cast<Dog&>(*animal);
        std::cout << "Dog explicit conversion/cast is ok" << std::endl;
    }
    catch (std::bad_cast &bc) {
        std::cout << "Dog explicit conversion/cast NOT ok" << bc.what() << std::endl; //x
        return 1;
    }

    return 0;
}

//c++ -Wall -Wextra -Werror -Wno-unused -Wconversion -Werror dynamic_cast.cpp
