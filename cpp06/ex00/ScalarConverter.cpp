/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:15:57 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/27 18:22:13 by arepsa           ###   ########.fr       */
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
		return *this;
	}
	return *this;
}

/* 
** std::numeric_limits<float>::max(): The largest positive finite value a float can represent.
** 3.40282e+38
** -std::numeric_limits<float>::max(): The largest negative finite value a float can represent.
** std::numeric_limits<float>::min(): The smallest positive normalized value a float can represent.
** 1.17549e-38
*/
static bool floatOverflow(float f) {
	return (f < -std::numeric_limits<float>::max() ||
			f > std::numeric_limits<float>::max());
}

/* 
** double max: 1.79769e+308
*/
static bool doubleOverflow(double d) {
	return (d < -std::numeric_limits<double>::max() ||
			d > std::numeric_limits<double>::max());
}

void    printChar(char c) {
	if (isprint(c)){
	std::cout << "char: '" << c << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

static bool isChar(const std::string& str) {
	return (str.length() == 1 && static_cast<unsigned char>(str[0]) <= 127 && !isdigit(str[0]));
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

static bool isPseudo(const std::string& str) {
    if (str == "nan" || str == "+inf" || str == "-inf" ||
        str == "nanf" || str == "+inff" || str == "-inff") {
        return true;
    }
    return false;
}

static bool isFloat(const std::string& str) {
	if (isPseudo(str)) {
		return false;
	}
	char *end;
	errno = 0;
	std::strtof(str.c_str(), &end);
	if (*end != 'f' || *(end + 1) != '\0' || errno == ERANGE) {
		return false;
	}
	return true;
}

/* 
** double is the only one that does not check the range
** to fail at overflow in later stage
*/
static bool isDouble(const std::string& str) {
	if (isPseudo(str)) {
		return false;
	}
	char *end;
	std::strtod(str.c_str(), &end);
	if (*end != '\0') {
		return false;
	}
	return true;
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
	} else if (isPseudo(str)) {
		return PSEUDO;
	}
	return INVALID;
}

static void printConverterInvalid() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void printConverterPseudo(const std::string& str) {
	if (str == "nan" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (str == "+inf" || str == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (str == "-inf" || str == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
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
	if (floatStr.find('e') == std::string::npos &&
		floatStr.find('E') == std::string::npos) {
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;

	ss.str("");
	ss << static_cast<double>(n);
	std::string doubleStr = ss.str();
	std::cout << "double: " << static_cast<double>(n);
	if (doubleStr.find('e') == std::string::npos &&
		doubleStr.find('E') == std::string::npos) {
		std::cout << ".0";
	}
	std::cout << std::endl;
}

/* 
** float precision: 7 decimal digits
*/
static void 		printConverterFloat(float f) {
	if (f >= 0 && f <= 127) {
		printChar(static_cast<char>(f));
	} else {
		std::cout << "char: impossible" << std::endl;
	}

	if (f > static_cast<float>(INT_MIN) && f < static_cast<float>(INT_MAX)) {
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}

	if (!floatOverflow(f)) {
		std::cout << "float: " << f;
		std::stringstream ss;
		ss << f;
		std::string floatStr = ss.str();
		if (floatStr.find('e') == std::string::npos &&
			floatStr.find('E') == std::string::npos &&
			floatStr.find('.') == std::string::npos) {
			std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	} else {
		std::cout << "float: overflow" << std::endl;
	}

	std::cout << "double: " << static_cast<double>(f);
	std::stringstream ss;
	ss << static_cast<double>(f);
	std::string doubleStr = ss.str();
	if (doubleStr.find('e') == std::string::npos &&
		doubleStr.find('E') == std::string::npos &&
		doubleStr.find('.') == std::string::npos) {
		std::cout << ".0";
	}
	std::cout << std::endl;
}

/* 
** double precision: 15 decimal digits
*/
static void	printConverterDouble(double d) {
	if (d >= 0 && d <= 127) {
		printChar(static_cast<char>(d));
	} else {
		std::cout << "char: impossible" << std::endl;
	}

	if (d > static_cast<double>(INT_MIN) && d < static_cast<double>(INT_MAX)) {
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}

	if (!floatOverflow(static_cast<float>(d))) {
		std::cout << "float: " << static_cast<float>(d);
		std::stringstream ss;
		ss << static_cast<float>(d);
		std::string floatStr = ss.str();
		if (floatStr.find('e') == std::string::npos &&
			floatStr.find('E') == std::string::npos &&
			floatStr.find('.') == std::string::npos) {
			std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	} else {
		std::cout << "float: overflow" << std::endl;
	}

	if (!doubleOverflow(d)) {
		std::cout << "double: " << d;
		std::stringstream ss;
		ss << static_cast<double>(d);
		std::string doubleStr = ss.str();
		if (doubleStr.find('e') == std::string::npos &&
			doubleStr.find('E') == std::string::npos &&
			doubleStr.find('.') == std::string::npos) {
			std::cout << ".0";
		}
		std::cout << std::endl;
	} else {
		std::cout << "double: overflow" << std::endl;
	}
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
	
	switch (type) {
		case CHAR:
			c = str[0];
			printConverterChar(c);
			break;
		case INT:
			n = std::atoi(str.c_str());
			printConverterInt(n);
			break;
		case FLOAT:
			f = std::strtof(str.c_str(), NULL);
			printConverterFloat(f);
			break;
		case DOUBLE:
			d = std::strtod(str.c_str(), NULL);
			printConverterDouble(d);
			break;
		case PSEUDO:
			printConverterPseudo(str);
			break;
		case INVALID:
			printConverterInvalid();
			break;
	}
}

