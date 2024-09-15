/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:28:02 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/15 21:28:03 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) {
    std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &copy ) {
    std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
    std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src ) {
    std::cout << "ShrubberyCreationForm assignment operator called." << std::endl;
    if (this != &src) {
        // Implement assignment
    }
    return *this;
}
