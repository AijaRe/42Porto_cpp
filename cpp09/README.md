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