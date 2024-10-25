/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:15:57 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/25 22:09:24 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	std::cout << "ScalarConverter default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	std::cout << "ScalarConverter copy constructor called." << std::endl;
	*this = copy;
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << "ScalarConverter destructor called." << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &src) {
	std::cout << "ScalarConverter assignment operator called." << std::endl;
	if (this != &src) {
		*this = src;
	}
	return *this;
}

void    printChar(char c) {
	if (isprint(c)){
	std::cout << "char: '" << c << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void    printInt(int n) {
	std::cout << "int: " << n << std::endl;
}

//print the float representation
void    printFloat(float f) {
	std::cout << "float: " << f << std::endl;
}

void    printDouble(double d) {
	std::cout << "double: " << d << std::endl;
}

static bool isChar(const std::string& str) {
	return (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]));
}

/* 
** allow + or - sign at the beginning of the string (strtol takes care of this)
** allow only digits in the string (check if ends with '\0')
*/
static bool isInt(const std::string& str) {
	if (str.length() == 1 && !isdigit(str[0])) {
		return false;
	}
	char *end;
	long value = strtol(str.c_str(), &end, 10);
	if (*end != '\0' || value > INT_MAX || value < INT_MIN) {
		return false;
	}
	return true;
}

static bool isFloat(const std::string& str) {
	if (str == "-inff" || str == "+inff" || str == "nanf") {
		return true;
	}
	char *end;
	errno = 0;
	float value = std::strtof(str.c_str(), &end);
	if (*end != 'f' || *(end + 1) != '\0' || errno == ERANGE) {
		return false;
	}
	return true;
}

static bool isDouble(const std::string& str) {
	if (str == "-inf" || str == "+inf" || str == "nan") {
		return true;
	}
	char *end;
	errno = 0;
	double value = std::strtod(str.c_str(), &end);
	if (*end != '\0' || errno == ERANGE) {
		return false;
	}
	return true;
}

int	getPrecision(const std::string& str) {
    size_t dotPos = str.find('.');
    if (dotPos == std::string::npos) {
        return 1;
    }
    return str.length() - dotPos - 1;
}

ScalarConverter::Type     ScalarConverter::getType(const std::string& str) {
	if (isChar(str)) {
		return CHAR;
	} else if (isInt(str)) {
		return INT;
	} else if (isFloat(str)) {
		return FLOAT;
	} else if (isDouble(str)) {
		return DOUBLE;
	}
	return INVALID;
}

static void printConverterInvalid() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void printConverterChar(char c) {
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void 		printConverterInt(int n) {
	if (n >= 0 && n <= 127) {
		printChar(static_cast<char>(n));
	} else {
		std::cout << "char: impossible" << std::endl;
	}
	
	std::cout << "int: " << n << std::endl;
	
    std::stringstream ss;
	ss << static_cast<float>(n);
	std::string floatStr = ss.str();
	std::cout << "float: " << static_cast<float>(n);
	//find() : if no matches were found, the function returns string::npos.
	if (floatStr.find('e') == std::string::npos) {
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;

	ss.str("");
	ss << static_cast<double>(n);
	std::string doubleStr = ss.str();
	std::cout << "double: " << static_cast<double>(n);
	if (doubleStr.find('e') == std::string::npos) {
		std::cout << ".0";
	}
	std::cout << std::endl;
	
}

/* 
** std::stringstream class allows to perform input and output operations on strings.
** >> operator to extracts the value from the string stream into the appropriate variable
**
*/
void ScalarConverter::convert(const std::string& str) {

	Type type = getType(str);
	char c = 0;
	int n = 0;
	float f = 0.0f;
	double d = 0.0;
	
	std::cout << "Type: " << type << std::endl;
	
	std::stringstream ss(str);
	switch (type) {
		case CHAR:
			c = str[0];
			printConverterChar(c);
			break;
		case INT:
			ss >> n;
			printConverterInt(n);
			break;
		case FLOAT:
			ss >> f;
			break;
		case DOUBLE:
			ss >> d;
			break;
		case INVALID:
			printConverterInvalid();
			return;
	}
}

