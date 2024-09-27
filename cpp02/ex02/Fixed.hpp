/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:56:34 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/27 18:47:35 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <climits>

class Fixed {
private:
    int _raw_value;
    static const int _fract_bits;
    
public:
    Fixed( void ); //Canonical default constructor
    Fixed( const int num );
    Fixed( const float num );
    Fixed( const Fixed &copy ); //Canonical copy constructor
    ~Fixed( void ); //Canonical destructos
    Fixed   &operator=(const Fixed &src); //Canonical copy assignment operator overload
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;

    bool	operator>( const Fixed rhs ) const;
    bool	operator<( const Fixed rhs ) const;
    bool	operator>=( const Fixed rhs ) const;
    bool	operator<=( const Fixed rhs ) const;
    bool	operator==( const Fixed rhs ) const;
    bool	operator!=( const Fixed rhs ) const;

    Fixed	operator+( const Fixed rhs ) const;
    Fixed	operator-( const Fixed rhs ) const;
    Fixed	operator*( const Fixed rhs ) const;
    Fixed	operator/( const Fixed rhs ) const;

    Fixed   operator++( int );
    Fixed   &operator++( void );
    Fixed   operator--( int );
    Fixed   &operator--( void );
    
    static Fixed &min( Fixed &num1, Fixed &num2 );
    static Fixed &max( Fixed &num1, Fixed &num2 );
    static const Fixed &min( const Fixed &num1, const Fixed &num2 );
    static const Fixed &max( const Fixed &num1, const Fixed &num2 );
};

std::ostream	&operator<<( std::ostream &o, const Fixed &rhs);

#endif // FIXED_HPP
