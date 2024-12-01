/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:50:57 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/01 12:50:58 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {
    std::cout << "RPN default constructor called." << std::endl;
}

RPN::RPN(const RPN &copy) {
    std::cout << "RPN copy constructor called." << std::endl;
    *this = copy;
}

RPN::~RPN(void) {
    std::cout << "RPN destructor called." << std::endl;
}

RPN & RPN::operator=(const RPN &src) {
    std::cout << "RPN assignment operator called." << std::endl;
    if (this != &src) {
        // Implement assignment
    }
    return *this;
}
