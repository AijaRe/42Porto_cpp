# C++ - Module 08
## Templated containers, iterators, algorithms

## General rules

- use C++98 standard
- headerfile for each class, no function implementation in headerfile
- using namespace <ns_name> and friend keywords is forbidden
- the goal of this module is using STL (Standard Template Library): Containers (vector/list/map/and so forth) and the Algorithms (defined in header <algorithm>).
- all classes must be designed in the Orthodox Canonical Form (containting default constructor, copy constructor, copy assignment operator, destructor)
- You can define your templates in the header files as usual. Or, if you want to, you
can write your template declarations in the header files and write their implementations in .tpp files. In any case, the header files are mandatory while the .tpp files are optional.

Skills: 

## Resources

[Cplusplus algorithms](https://cplusplus.com/reference/algorithm/)
[Cplusplus containers](https://cplusplus.com/reference/stl/)


### ex00 - Easy find

A first easy exercise is the way to start off on the right foot.

Write a function template `easyfind` that accepts a type `T`. It takes two parameters.
The first one has type `T` and the second one is an integer.

Assuming `T` is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.

If no occurrence is found, you can either throw an exception or return an error value
of your choice. If you need some inspiration, analyze how standard containers behave.

Of course, implement and turn in your own tests to ensure everything works as ex-
pected.

You don’t have to handle associative containers.
