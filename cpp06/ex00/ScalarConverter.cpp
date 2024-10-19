/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:15:57 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/19 18:57:06 by arepsa           ###   ########.fr       */
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

//print the char representation
void    printChar(char c) {
    if (isprint(c)){
        std::cout << "char: " << c << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

//print the int representation
void    printInt(int n) {
    std::cout << "int: " << n << std::endl;
}

//print the float representation
void    printInt(float f) {
    std::cout << "float: " << f << std::endl;
}

//print the double representation
void    printDouble(double d) {
    std::cout << "double: " << d << std::endl;
}

/* 
** std::stringstream class allows to perform input and output operations on strings.
** >> operator to extracts the value from the string stream into the appropriate variable
**
*/
void ScalarConverter::convert(const std::string& str) {
    std::cout << str << std::endl;
    printChar('\t');
    printChar('a');

    Type type = INT;
    char c = 0;
    int n = 0;
    float f = 0.0f;
    double d = 0.0;
    
    std::stringstream ss(str);
    switch (type) {
        case CHAR:
            c = str[0];
            break;
        case INT:
            ss >> n;
            std::cout << "int: " << n << std::endl;
            break;
        case FLOAT:
            ss >> f;
            break;
        case DOUBLE:
            ss >> d;
            break;
        case PSEUDO:
            ss >> d;
            f = static_cast<float>(d);
            break;
        default:
            break;
    }
}

