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
[CodeBeauty C++ STL playlist](https://www.youtube.com/playlist?list=PL43pGnjiVwgR9BloyT0OgsMo8d_hylBv0)


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
1. Validade both files
2. Parse `data.csv` into map container (key: date, value: rate);