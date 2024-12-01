/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:50:57 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/01 20:42:59 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) : _stack() {
    //std::cout << "RPN default constructor called." << std::endl;
}

RPN::RPN(const RPN& copy) : _stack(copy._stack) {
    //std::cout << "RPN copy constructor called." << std::endl;
}

RPN::~RPN(void) {
    //std::cout << "RPN destructor called." << std::endl;
}

RPN & RPN::operator=(const RPN &src) {
    //std::cout << "RPN assignment operator called." << std::endl;
    if (this != &src) {
        _stack = src._stack;
    }
    return *this;
}

void    RPN::validateInput(std::string& input) {

    if (input.empty()) {
        throw std::invalid_argument("Error: empty input.");
    }
    for (size_t i = 0; i < input.length(); i++) {
        char c = input[i];
        if (!std::isdigit(c) && !std::isspace(c) && std::string("+-/*").find(c) == std::string::npos)
            throw std::invalid_argument("Error: invalid character in input.");
    }
}

void    RPN::processInput(std::string& input) {
    try{
        validateInput(input);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return ;
    }
}
