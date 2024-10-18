/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:15:57 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/18 20:00:50 by arepsa           ###   ########.fr       */
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

void ScalarConverter::convert(const std::string& str) {
    std::cout << str << std::endl;
}

