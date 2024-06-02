/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:56:34 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/23 19:49:06 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _raw_value;
    static const int _fract_bits;
public:
    Fixed(void); //Canonical default constructor
    Fixed(const Fixed &copy); //Canonical copy constructor
    ~Fixed(void); //Canonical destructos
    Fixed &operator=(const Fixed &src); //Canonical copy assignment operator overload
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
};

#endif // FIXED_HPP