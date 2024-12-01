# C++ - Module 06
## Casts

## General rules

- use C++98 standard
- headerfile for each class, no function implementation in headerfile
- using namespace <ns_name> and friend keywords is forbidden
- using the STL is forbidden (no Containers and no Algorithms)
- all classes, except ex02, must be designed in the Orthodox Canonical Form (containting default constructor, copy constructor, copy assignment operator, destructor)

Skills: C++ cast types and usecases: static_cast, reinterpret_cast, dynamic_cast

## Resources

[GeeksforGeeks Casting Operators in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/casting-operators-in-cpp/)

[cplusplus.com typecasting](https://cplusplus.com/doc/oldtutorial/typecasting/)

[Programiz: Float and Double in C++](https://www.programiz.com/cpp-programming/float-double)

[uintptr_t data type](https://stackoverflow.com/questions/1845482/what-is-the-uintptr-t-data-type)


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


### ex01 - Serialization

Implement a class Serializer, who will not be initializable by the user by any way,
with the following static methods:

`uintptr_t serialize(Data* ptr);`

It takes a pointer and converts it to the unsigned integer type uintptr_t.

`Data* deserialize(uintptr_t raw);`

It takes an unsigned integer parameter and converts it to a pointer to Data.
Write a program to test that your class works as expected.

You must create a non-empty (it means it has data members) Data structure.

Use `serialize()` on the address of the Data object and pass its return value to
`deserialize()`. Then, ensure the return value of `deserialize()` compares equal to the
original pointer.

Do not forget to turn in the files of your Data structure.

Exercise skills: explore how data pointers can be represented as integers and to practice converting between these representations. Use `reinterpret_cast`.

`uintptr_t` -	unsigned integer type capable of holding a pointer.

Pointers might vary in size across different architectures (32-bit vs 64-bit). The C++ standard guarantees that uintptr_t can handle all valid pointer values, ensuring portability.

Hashing. Pointers can be used as unique identifiers for objects. Sometimes, when you want to create a hash table, you might want to use pointers as keys. However, most hash functions work on integers, so you convert pointers to integers for this purpose.


### ex02 - Identify real type

Implement a `Base` class that has a public virtual destructor only. Create three empty
classes `A`, `B` and `C`, that publicly inherit from Base.

Implement the following functions:

`Base * generate(void);` 

It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.

`void identify(Base* p);`

It prints the actual type of the object pointed to by p: "A", "B" or "C".

`void identify(Base& p);`

It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.

Including the typeinfo header is forbidden.

Write a program to test that everything works as expected.
