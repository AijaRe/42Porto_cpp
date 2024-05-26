/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:56:24 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/25 13:11:46 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
  
/* 
** convert int or float to binary representation (an int)
** limited range and sacrificed precision, but gained space and speed
** when printing the number convert back again to float
** 0000 0001 << 8 = 0000 0001 0000 0000
** binary for 256 
*/
Fixed::Fixed( void ) : _raw_value(0) {
    std::cout << "Default constructor called." << std::endl;
}

/* 
** convert integer into fixed-point by multiplying it with 2^8 
*/
Fixed::Fixed( const int num ) {
    std::cout << "Int constructor called." << std::endl;
    if (num > (INT_MAX >> _fract_bits) || num < (INT_MIN >> _fract_bits)) {
        std::cerr << "Overflow error: Value out of range." << std::endl;
        this->_raw_value = 0;
    } else {
        this->_raw_value = num * (1 << _fract_bits);
    }
}

/* 
** round to avoid truncation when storing as int and preserve precision
*/
Fixed::Fixed( const float num ) {
    std::cout << "Float constructor called." << std::endl;
    float scaled_value = num * (1 << _fract_bits);
    if (scaled_value > INT_MAX || scaled_value < INT_MIN) {
        std::cerr << "Overflow error: Value out of range for fixed-point conversion." << std::endl;
        this->_raw_value = 0;
    } else {
        this->_raw_value = roundf(scaled_value);
    }
}

Fixed::Fixed( const Fixed &src ) {
    std::cout << "Copy constructor called." << std::endl;
    *this = src;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called." << std::endl;
}

/* 
** Assign one instance of a class to another.
** Check for self-assignment to avoid redundant operations.
** Copy the data from the source object to the target object.
** Return a reference to the current object, to allow chaining.
*/
Fixed &Fixed::operator=( const Fixed &copy ) {
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &copy) {
        this->_raw_value = copy._raw_value;
    }
    return *this;
}

/* 
** Output class contents
** in this case fixed-point number as float
*/
std::ostream	&operator<<( std::ostream &out, const Fixed &rhs){
	out << rhs.toFloat();
	return out;
}

int     Fixed::getRawBits( void ) const {
    return this->_raw_value;
}

void    Fixed::setRawBits( int const raw ) {
    this->_raw_value = raw;
    return ;
}

float   Fixed::toFloat( void ) const{
    return (float)this->_raw_value / (float)(1 << _fract_bits);
}

int   Fixed::toInt( void ) const{
    return this->_raw_value / (1 << _fract_bits);
}
