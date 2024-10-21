/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:15:57 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/21 20:25:35 by arepsa           ###   ########.fr       */
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
		std::cout << "char: " << c << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void    printInt(int n) {
	std::cout << "int: " << n << std::endl;
}

//print the float representation
void    printFloat(float f, int precision) {
	std::cout << "float: " << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
}

void    printDouble(double d, int precision) {
	std::cout << "double: " << std::fixed << std::setprecision(precision) << d << std::endl;
}

static bool isChar(const std::string& str) {
	return (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]));
}

/* 
** allow + or - sign at the beginning of the string
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

/* static bool isPseudo(const std::string& str) {
	if (str == "nan" || str == "+inf" || str == "-inf" ||
		str == "nanf" || str == "+inff" || str == "-inff") {
		return true;
	}
	return false;
} */

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
	//} else if (isPseudo(str)) {
	//	return PSEUDO;
	} else if (isFloat(str)) {
		return FLOAT;
	} else if (isDouble(str)) {
		return DOUBLE;
	}
	return INVALID;
}

void	ScalarConverter::printConverter(Type type, int precision, char c, int n, float f, double d) {
	
	switch (type) {
		case CHAR:
			printChar(c);
			printInt(static_cast<int>(c));
			printFloat(static_cast<float>(c), precision);
			printDouble(static_cast<double>(c), precision);
			break;
		case INT:
			printChar(static_cast<char>(n));
			printInt(n);
			printFloat(static_cast<float>(n), precision);
			printDouble(static_cast<double>(n), precision);
			break;
		case FLOAT:
			printFloat(f, precision);
			break;
		case DOUBLE:
			printDouble(d, precision);
			break;
		default:
			std::cout << "Conversion not possible" << std::endl;
			break;
	}
}

/* 
** std::stringstream class allows to perform input and output operations on strings.
** >> operator to extracts the value from the string stream into the appropriate variable
**
*/
void ScalarConverter::convert(const std::string& str) {
	std::cout << str << std::endl;

	Type type = getType(str);
	char c = 0;
	int n = 0;
	float f = 0.0f;
	double d = 0.0;
	int precision = 1;
	
	std::cout << "Type: " << type << std::endl;
	
	std::stringstream ss(str);
	switch (type) {
		case CHAR:
			c = str[0];
			break;
		case INT:
			ss >> n;
			break;
		case FLOAT:
			ss >> f;
			break;
		case DOUBLE:
			ss >> d;
			break;
		//case PSEUDO:
		//	ss >> d;
		//	f = static_cast<float>(d);
		//	break;
		case INVALID:
			std::cout << "Invalid input" << std::endl;
		default:
			break;
	}

	if (type == FLOAT || type == DOUBLE)
		precision = getPrecision(str);
	printConverter(type, precision, c, n, f, d);
}

