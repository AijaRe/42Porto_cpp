/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:56:24 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/26 20:22:34 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _raw_value(0) {
    
    std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed( const Fixed &src ) {
    std::cout << "Copy constructor called." << std::endl;
    *this = src;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called." << std::endl;
}

Fixed &Fixed::operator=( const Fixed &copy ) {
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &copy) {
        this->_raw_value = copy.getRawBits();
    }
    return *this;
}

int     Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called." << std::endl;
    return this->_raw_value;
    
}

void    Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called." << std::endl;
    this->_raw_value = raw;
    
    return ;
}
