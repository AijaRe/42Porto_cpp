/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:56:34 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/25 12:29:02 by arepsa           ###   ########.fr       */
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
    Fixed(void); //Canonical default constructor
    Fixed( const int num );
    Fixed( const float num );
    Fixed(const Fixed &copy); //Canonical copy constructor
    ~Fixed(void); //Canonical destructos
    Fixed &operator=(const Fixed &src); //Canonical copy assignment operator overload
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;
};

std::ostream	&operator<<( std::ostream &o, const Fixed &rhs);

#endif // FIXED_HPP
