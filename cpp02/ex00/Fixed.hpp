/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:56:34 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/28 12:36:37 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <climits>

class Fixed {
private:
    int _raw_value;
    static const int _fract_bits = 8;
public:
    Fixed( void ); //Canonical default constructor
    Fixed( const Fixed &copy ); //Canonical copy constructor
    ~Fixed( void ); //Canonical destructor
    Fixed &operator=( const Fixed &src ); //Canonical assignment operator overload
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
};

#endif // FIXED_HPP
