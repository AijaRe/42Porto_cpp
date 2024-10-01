# C++ - Module 02
## Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form, fixed-point class and binary space partitioning

## General rules

- use C++98 standard
- headerfile for each class, no function implementation in headerfile
- using namespace <ns_name> and friend keywords is forbidden
- using the STL is forbidden (no Containers and no Algorithms)
- all classes must be designed in the Orthodox Canonical Form (containting default constructor, copy constructor, copy assignment operator, destructor)


Skills: fixed-point number implementation, operator overload, canonical form, binary space partitioning basics.

### ex00 - My First Class in Orthodox Canonical Form

This exercise will create a basic structure for fixed-point number.

Create a class in Orthodox Canonical Form that represents a fixed-point number:
Private members:
- An integer to store the fixed-point number value.
- A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8.

Public members:
- all elements of Orthodox Canonical Form (default constructor, copy constructor, copy assignment operator, destructor).
- A member function ```int getRawBits( void ) const;``` that returns the raw value of the fixed-point value.
- A member function ```void setRawBits( int const raw );``` that sets the raw value of the fixed-point number.


### ex01 - Towards a more useful fixed-point number class

Continue work on fixed-point number implementation.

Add the following public constructors and public member functions to your class:
- A constructor that takes a constant integer as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in exercise 00.
- A constructor that takes a constant floating-point number as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in exercise 00.
- A member function ```float toFloat( void ) const;``` that converts the fixed-point value to a floating-point value.
- A member function ```int toInt( void ) const;``` that converts the fixed-point value to an integer value.
- An overload of the insertion («) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.


### ex02 - Now we’re talking

Add public member functions to your class to overload the following operators:
- The 6 comparison operators: >, <, >=, <=, == and !=.
- The 4 arithmetic operators: +, -, *, and /.
- The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators, that will increase or decrease the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1.

Add these four public overloaded member functions to your class:
- A static member function min that takes as parameters two references on fixed-point numbers, and returns a reference to the smallest one.
- A static member function min that takes as parameters two references to constant fixed-point numbers, and returns a reference to the smallest one.
- A static member function max that takes as parameters two references on fixed-point numbers, and returns a reference to the greatest one.
- A static member function max that takes as parameters two references to constant fixed-point numbers, and returns a reference to the greatest one.


### ex03 - BSP

Apply created fixed-point number class in practice.

Implement a function which indicates whether a point is inside of a triangle or not.

BSP stands for Binary space partitioning.


