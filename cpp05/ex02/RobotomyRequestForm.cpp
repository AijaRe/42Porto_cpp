/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:27:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/15 21:27:57 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) {
    std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &copy ) {
    std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
    std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm &src ) {
    std::cout << "RobotomyRequestForm assignment operator called." << std::endl;
    if (this != &src) {
        // Implement assignment
    }
    return *this;
}
