# C++ - Module 09
## STL (Standard Template Library)

## General rules

- use C++98 standard
- headerfile for each class, no function implementation in headerfile
- using namespace <ns_name> and friend keywords is forbidden
- It is mandatory to use the standard containers to perform each exercise in this module.
Once a container is used you cannot use it for the rest of the module.
- all classes must be designed in the Orthodox Canonical Form (containting default constructor, copy constructor, copy assignment operator, destructor)

Skills: 

## Resources

[Cplusplus algorithms](https://cplusplus.com/reference/algorithm/)
[Cplusplus containers](https://cplusplus.com/reference/stl/)
[Cplusplus time struct / mktime](https://cplusplus.com/reference/ctime/)
[CodeBeauty C++ STL playlist](https://www.youtube.com/playlist?list=PL43pGnjiVwgR9BloyT0OgsMo8d_hylBv0)
[Computing Tutor - Reverse Polish Notation](https://www.youtube.com/watch?v=HDwRlIc75w4)


### ex00 - Bitcoin Exchange


You have to create a program which outputs the value of a certain amount of bitcoin
on a certain date.

This program must use a database in csv format which will represent bitcoin price
over time. This database is provided.
The program will take as input a second database, storing the different prices/dates
to evaluate.

Your program must respect these rules:
- The program name is btc.
- Your program must take a file as argument.
- Each line in this file must use the following format: "date | value".
- A valid date will always be in the following format: Year-Month-Day.
- A valid value must be either a float or a positive integer, between 0 and 1000.

Your program will use the value in your input file.

Your program should display on the standard output the result of the value multiplied
by the exchange rate according to the date indicated in your database.

Input example:
```
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
```

..should produce this output:
```
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number
```

#### Plan:
1. Validade both files - check if files exist, can be opened and are not empty.
2. Parse `data.csv` into map container (key: date, value: rate):
	- validate the header
	- split each line by comma: pass left side as key and right side as value to the map container 
3. Process input file: 
	- validate the header
	- validate each line of the input file: validate date and the value
	- look up exchange rate in map container and calculate the converted value
	- print the results or error message.


### ex01 - Reverse Polish Notation


You must create a program with these constraints:
- The program name is `RPN`.
- Your program must take an inverted Polish mathematical expression as an argument.
- The numbers used in this operation and passed as arguments will always be less
than 10. The calculation itself but also the result do not take into account this rule.
- Your program must process this expression and output the correct result on the
standard output.
- If an error occurs during the execution of the program an error message should be
displayed on the standard error.
- Your program must be able to handle operations with these tokens: `"+ - / *"`.
- You don’t need to manage the brackets or decimal numbers.


Example of standard use:
```
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
```

#### RPN structure:
1. Place all operands(numbers) in a stack 
2. When an operator appears, pop first 2 elements from the stack 
3. Apply the operator to the popped elements (second popped element - operator - first popped element) and place the result back on stack.
4. After processing the entire input string, the stack should contain a single value aka result.


### ex02 - PmergeMe


You must create a program with these constraints:
- The name of the program is PmergeMe.
- Your program must be able to use a positive integer sequence as argument.
- Your program must use the merge-insert sort algorithm to sort the positive integer sequence.
- If an error occurs during program execution, an error message should be displayed on the standard error.

You need to use the Ford-Johnson algorithm.
(source: [Art Of Computer Programming, Vol.3.](https://seriouscomputerist.atariverse.com/media/pdf/book/Art%20of%20Computer%20Programming%20-%20Volume%203%20(Sorting%20&%20Searching).pdf) Merge Insertion,
Page 184.)

You must use at least two different containers in your code to
validate this exercise. Your program must be able to handle at
least 3000 different integers.

It is strongly advised to implement your algorithm for each container
and thus to avoid using a generic function.

ere are some additional guidelines on the information you should display line by line on the standard output:
- On the first line you must display an explicit text followed by the unsorted positive integer sequence.
- On the second line you must display an explicit text followed by the sorted positive integer sequence.
- On the third line you must display an explicit text indicating the time used by your algorithm by specifying the first container used to sort the positive integer sequence.
- On the last line you must display an explicit text indicating the time used by your algorithm by specifying the second container used to sort the positive integer sequence.

Here is an example of a standard use:
```
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
```

The indication of the time is deliberately strange in this example.
You have to indicate the time used to perform all your
operations, both the sorting part and the data management part.

#### Algorithm steps:
1. Group elements into pairs.
2. Sort the bigger numbers of each pair using merge insert (how exatcly?) -> create the main chain.
3. Insert the smaller elements into the main chain one by one (how exactly? Jacobsthal?)
