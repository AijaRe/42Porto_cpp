#include <iostream>

//most open: allows reinterpretations, upcasts and downcasts
//reinterpret any address as any other address

class A {};
class B {};

int main (void) {
    {
        //does not make sense but works 0_0
        A * a = new A;
        B * b = reinterpret_cast<B*>(a);
    }
    {
        float   a = 42.002f;

        void* b = &a;                       //Implicit promotion - Ok
        int* c = reinterpret_cast<int*>(b); //Explicit demotion - Ok, I obey
        int& d = reinterpret_cast<int&>(b); //Explicit demotion - Ok, I obey
        std::cout << c << std::endl;
        std::cout << d << std::endl;
    }

    return 0;
}

//c++ -Wall -Wextra -Werror -Wno-unused -Wconversion -Werror reinterpret_cast.cpp
