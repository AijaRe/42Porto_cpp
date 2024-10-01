/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:56:24 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/28 18:11:09 by arepsa           ###   ########.fr       */
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
** num * (1 << _fract_bits) == 256
*/
Fixed::Fixed( const int num ) {
    long scaled_value = static_cast<long>(num) * (1 << _fract_bits);
    if (scaled_value > INT_MAX || scaled_value < INT_MIN) {
        std::cerr << "Overflow error: Value out of range." << std::endl;
        this->_raw_value = 0;
    } else {
        this->_raw_value = static_cast<int>(scaled_value);
    }
}

/* 
** round to avoid truncation when storing as int and preserve precision
** num * (1 << _fract_bits) == 256
*/
Fixed::Fixed( const float num ) {
    const int   scaling_factor = (1 << _fract_bits);
    
    if (num > (static_cast<float>(INT_MAX) / scaling_factor) ||
        num < (static_cast<float>(INT_MIN) / scaling_factor)) {
        std::cerr << "Overflow error: Value out of range." << std::endl;
        this->_raw_value = 0;
        return ;
    } else {
        float scaled_value = num * scaling_factor;
        if (scaled_value >= static_cast<float>(INT_MAX) ||
            scaled_value <= static_cast<float>(INT_MIN)) {
            std::cerr << "Overflow error: Scaled value out of range." << std::endl;
            this->_raw_value = 0;
        } else
            this->_raw_value = static_cast<int>(roundf(scaled_value));
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
    return static_cast<float>(this->_raw_value) / static_cast<float>((1 << _fract_bits));
}

int   Fixed::toInt( void ) const{
    return this->_raw_value / (1 << _fract_bits);
}
