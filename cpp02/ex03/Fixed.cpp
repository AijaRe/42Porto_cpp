/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:56:24 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/27 19:23:28 by arepsa           ###   ########.fr       */
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
    return ;
}

/* 
** cast to long to be able to scale max numbers
** 1 << _fract_bits = 256 
** shift 1 by _fract_bits (8) -> from least significant bit to 9th
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
    *this = src;
}

Fixed::~Fixed( void ) {
    return ;
}

Fixed &Fixed::operator=( const Fixed &copy ) {
    if (this != &copy) {
        this->_raw_value = copy._raw_value;
    }
    return *this;
}

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
    return static_cast<float>(this->_raw_value) / static_cast<float>(1 << _fract_bits);
}

int   Fixed::toInt( void ) const{
    return this->_raw_value / (1 << _fract_bits);
}
/* -------------- comparison operator overload -------------- */
bool	Fixed::operator>( const Fixed rhs ) const {
    return this->toFloat() > rhs.toFloat();
}

bool	Fixed::operator<( const Fixed rhs ) const {
    return this->toFloat() < rhs.toFloat();
}

bool	Fixed::operator>=( const Fixed rhs ) const {
    return this->toFloat() >= rhs.toFloat();
}

bool	Fixed::operator<=( const Fixed rhs ) const {
    return this->toFloat() <= rhs.toFloat();
}

bool	Fixed::operator==( const Fixed rhs ) const {
    return this->toFloat() == rhs.toFloat();
}

bool	Fixed::operator!=( const Fixed rhs ) const {
    return this->toFloat() != rhs.toFloat();
}

/* ------------------ arithmetic operators ------------------ */
Fixed   Fixed::operator+( const Fixed rhs ) const {
    return this->toFloat() + rhs.toFloat();
}

Fixed   Fixed::operator-( const Fixed rhs ) const {
    return this->toFloat() - rhs.toFloat();
}

Fixed   Fixed::operator*( const Fixed rhs ) const {
    return this->toFloat() * rhs.toFloat();
}

Fixed   Fixed::operator/( const Fixed rhs ) const {
    if (rhs == 0) {
        std::cerr << "Can't divide by zero!" << std::endl;
        return 0;
    }
    return this->toFloat() / rhs.toFloat();
}

/* ------------- increment & decrement operators ------------- */
// Postfix increment operator (x++) return original value and then increment the object
// int in the parameters indicates to the compiler that this is postfix version
Fixed   Fixed::operator++( int ) {
    Fixed temp(*this);
    this->_raw_value++;
    return temp;
}

// Prefix increment operator (++x)
Fixed   &Fixed::operator++( void ) {
    ++this->_raw_value;
    return *this;
}

//Postfix decrement operator (x--) return original value and then decrement the object
// int in the parameters indicates to the compiler that this is postfix version
Fixed   Fixed::operator--( int ) {
    Fixed temp(*this);
    this->_raw_value--;
    return temp;
}

// Prefix decrement operator (--x)
Fixed   &Fixed::operator--( void ) {
    --this->_raw_value;
    return *this;
}


/* ---------- min & max overloaded member functions ---------- */
Fixed &Fixed::min( Fixed &num1, Fixed &num2 ){
    return num1 < num2 ? num1 : num2;
}

Fixed &Fixed::max( Fixed &num1, Fixed &num2 ){
    return num1 > num2 ? num1 : num2;
}

const Fixed &Fixed::min( const Fixed &num1, const Fixed &num2 ){
    return num1 < num2 ? num1 : num2;
}

const Fixed &Fixed::max( const Fixed &num1, const Fixed &num2 ){
    return num1 > num2 ? num1 : num2;
}
