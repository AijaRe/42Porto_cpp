# C++ - Module 07
## Templates

## General rules

- use C++98 standard
- headerfile for each class, no function implementation in headerfile
- using namespace <ns_name> and friend keywords is forbidden
- using the STL is forbidden (no Containers and no Algorithms)
- all classes, except ex02, must be designed in the Orthodox Canonical Form (containting default constructor, copy constructor, copy assignment operator, destructor)

Skills: C++ templates

## Resources

Watch intra videos, big fan.
Apart form exercise content, check also class templates, default type templates and specializations (you can find examples in `test` folder).


### ex00 - Start with a few functions

Implement the following function templates:

- `swap`: Swaps the values of two given arguments. Does not return anything.

- `min`: Compares the two values passed in its arguments and returns the smallest one. If the two of them are equal, then it returns the second one.

- `max`: Compares the two values passed in its arguments and returns the greatest one. If the two of them are equal, then it returns the second one.

These functions can be called with any type of argument. The only requirement is
that the two arguments must have the same type and must support all the comparison
operators.

Templates must be defined in the header files.


### ex01 - Iter

Implement a function template iter that takes 3 parameters and returns nothing.
- The first parameter is the address of an array.
- The second one is the length of the array.
- The third one is a function that will be called on every element of the array.

Turn in a main.cpp file that contains your tests. Provide enough code to generate a
test executable.

Your iter function template must work with any type of array. The third parameter
can be an instantiated function template.


### ex02 - Array

Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:

- Construction with no parameter: Creates an empty array.
- Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.

Tip: Try to compile `int * a = new int();` then display `*a`.
- Construction by copy and assignment operator. In both cases, modifying either the original array or its copy after copying musn’t affect the other array.
- You MUST use the operator `new[]` to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.
- Elements can be accessed through the subscript operator: `[ ]`.
- When accessing an element with the `[ ]` operator, if its index is out of bounds, an `std::exception` is thrown.
- A member function size() that returns the number of elements in the array. This member function takes no parameter and musn’t modify the current instance.

As usual, ensure everything works as expected and turn in a main.cpp file that con-
tains your tests.
