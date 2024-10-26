# C++ - Module 06
## Casts

## General rules

- use C++98 standard
- headerfile for each class, no function implementation in headerfile
- using namespace <ns_name> and friend keywords is forbidden
- using the STL is forbidden (no Containers and no Algorithms)
- all classes must be designed in the Orthodox Canonical Form (containting default constructor, copy constructor, copy assignment operator, destructor)

Skills: C++ cast types

## Resources

[GeeksforGeeks Casting Operators in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/casting-operators-in-cpp/)

[cplusplus.com](https://cplusplus.com/doc/oldtutorial/typecasting/)

[Programiz: Float and Double in C++](https://www.programiz.com/cpp-programming/float-double)


### ex00 - Conversion of scalar types


Write a class ScalarConverter that will contain only one static method "convert"
that will takes as parameter a string representation of a C++ literal in its most common
form and output its value in the following serie of scalar types :
- char
- int
- float
- double
As this class doesn’t need to store anything at all, this class must not be instanciable by
users.
Except for char parameters, only the decimal notation will be used.

Examples of char literals: ’c’, ’a’, ...

To make things simple, please note that non displayable characters shouldn’t be used as
inputs. If a conversion to char is not displayable, prints an informative message.

Examples of int literals: 0, -42, 42...

Examples of float literals: 0.0f, -4.2f, 4.2f...

You have to handle these pseudo literals as well (you know, for science): -inff, +inff and nanf.

Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan.

Write a program to test that your class works as expected.

You have to first detect the type of the literal passed as parameter, convert it from
string to its actual type, then convert it explicitly to the three other data types.

If a conversion does not make any sense or overflows, display a message to inform
the user that the type conversion is impossible. 

Include any header you need in order to
handle numeric limits and special values.

#### Plan

- Create a ScalarConverter class that will contain only a static convert method.
- Use functions to detect the type of the literal based on the input format.
- Convert the literal to the detected type.
- Convert input type to all the other types.
- Handle edge cases for non-displayable characters, special floating-point values, and overflow conditions.
