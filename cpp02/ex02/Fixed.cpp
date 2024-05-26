/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:56:24 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/25 16:34:26 by arepsa           ###   ########.fr       */
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

Fixed::Fixed( const int num ) {
    if (num > (INT_MAX >> _fract_bits) || num < (INT_MIN >> _fract_bits)) {
        std::cerr << "Overflow error: Value out of range." << std::endl;
        this->_raw_value = 0;
    } else {
        this->_raw_value = num * (1 << _fract_bits);
    }
}

Fixed::Fixed( const float num ) {
    float scaled_value = num * (1 << _fract_bits);
    if (scaled_value > INT_MAX || scaled_value < INT_MIN) {
        std::cerr << "Overflow error: Value out of range." << std::endl;
        this->_raw_value = 0;
    } else {
        this->_raw_value = roundf(scaled_value);
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
    return (float)this->_raw_value / (float)(1 << _fract_bits);
}

int   Fixed::toInt( void ) const{
    return this->_raw_value / (1 << _fract_bits);
}
/* -------------- comparison operator overload -------------- */
bool	Fixed::operator>( const Fixed rhs ) const{
    return this->toFloat() > rhs.toFloat();
}

bool	Fixed::operator<( const Fixed rhs ) const{
    return this->toFloat() < rhs.toFloat();
}

bool	Fixed::operator>=( const Fixed rhs ) const{
    return this->toFloat() >= rhs.toFloat();
}

bool	Fixed::operator<=( const Fixed rhs ) const{
    return this->toFloat() <= rhs.toFloat();
}

bool	Fixed::operator==( const Fixed rhs ) const{
    return this->toFloat() == rhs.toFloat();
}

bool	Fixed::operator!=( const Fixed rhs ) const{
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
    return this->toFloat() / rhs.toFloat();
}

/* ------------- increment & decrement operators ------------- */
// Postfix increment operator (x++) return original value and then increment the object
Fixed   Fixed::operator++( int ) {
    Fixed temp(*this);
    ++this->_raw_value;
    return temp;
}

// Prefix increment operator (++x)
Fixed   &Fixed::operator++( void ) {
    ++this->_raw_value;
    return *this;
}

Fixed   Fixed::operator--( int ) {
    Fixed temp(*this);
    --this->_raw_value;
    return temp;
}

// Prefix increment operator (++x)
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
