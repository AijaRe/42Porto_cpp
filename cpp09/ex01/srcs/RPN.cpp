/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:50:57 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/01 21:48:05 by arepsa           ###   ########.fr       */
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

bool    RPN::isTokenNumber(const std::string& token) {
    return (((token[0] == '+' || token[0] == '-') && 
            token.size() > 1 && std::isdigit(token[1]))) ||
            (std::isdigit(token[0]));
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

long  RPN::calculate(long num1, long num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0)
                throw std::runtime_error("Error: division by zero.");
            return num1 / num2;
        default:
            throw std::invalid_argument("Error: invalid operator.");
    }
}

void    RPN::processInput(std::string& input) {
    try {
        validateInput(input);
        
        std::istringstream iss(input);
        std::string token;

        while (iss >> token) {
            if (isTokenNumber(token)) {
                char *end;
                long num = std::strtol(token.c_str(), &end, 10);
                if (*end != '\0' || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
                    throw std::invalid_argument("Error: invalid number.");
                _stack.push(num);
            } else if (std::string("+-/*").find(token) != std::string::npos && token.size() == 1) {
                if (_stack.size() < 2)
                    throw std::runtime_error("Error: not enough operands.");
                long num2 = _stack.top();
                _stack.pop();
                long num1 = _stack.top();
                _stack.pop();
                long result = calculate(num1, num2, token[0]);
                if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
                    throw std::runtime_error("Error: result out of range.");
                _stack.push(result);

            } else {
                throw std::invalid_argument("Error: invalid token.");
            }
            
        }

        
        if (_stack.size() != 1) {
            throw std::runtime_error("Error: invalid RPN expression.");
        }
        
        std::cout << _stack.top() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return ;
    }
}
