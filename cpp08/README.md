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

Skills: templates, container basics, iterators

## Resources

[Cplusplus algorithms](https://cplusplus.com/reference/algorithm/)
[Cplusplus containers](https://cplusplus.com/reference/stl/)
[W3Schools C++ iterators](https://www.w3schools.com/cpp/cpp_iterators.asp)
[Geeksforgeeks - generate a vector with random values](https://www.geeksforgeeks.org/how-to-generate-a-vector-with-random-values-in-c/)
[CodeBeauty C++ STL playlist](https://www.youtube.com/playlist?list=PL43pGnjiVwgR9BloyT0OgsMo8d_hylBv0)


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


### ex01 - Span

Develop a `Span` class that can store a maximum of `N` integers. `N` is an unsigned int
variable and will be the only parameter passed to the constructor.

This class will have a member function called `addNumber()` to add a single number
to the Span. It will be used in order to fill it. Any attempt to add a new element if there are already N elements stored should throw an exception.

Next, implement two member functions: `shortestSpan()` and `longestSpan()`

They will respectively find out the shortest span or the longest span (or distance, if
you prefer) between all the numbers stored, and return it. If there are no numbers stored, or only one, no span can be found. Thus, throw an exception.

Of course, you will write your own tests and they will be way more thorough than the
ones below. Test your Span at least with a minimum of 10 000 numbers. More would be
even better.


### ex02 - Mutated abomination


The `std::stack` container is very nice. Unfortunately, it is one of the only STL Containers that is NOT iterable. That’s too bad.

But why would we accept this? Especially if we can take the liberty of butchering the original stack to create missing features.

To repair this injustice, you have to make the std::stack container iterable.

Write a `MutantStack` class. It will be implemented in terms of a `std::stack`.
It will offer all its member functions, plus an additional feature: `iterators`.

Of course, you will write and turn in your own tests to ensure everything works as expected.
