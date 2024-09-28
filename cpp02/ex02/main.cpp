/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:23:30 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/21 20:23:30 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* 
** binary approximation of floats have inherent precision errors
** toFloat() necessary for display but behind the scenes
** fixed point number is an int and controls precision in storage and calculation
** also when storing float as fixed point number, it has to be
** rounded to represent int
*/

const int Fixed::_fract_bits = 8;

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\nMORE TESTS.. LET'S GO!" << std::endl;
	std::cout << "Set c = 6, d = 5, e = 2, f = 15.5f" << std::endl;
	Fixed c( 6 );
	Fixed d( 5 );
	const Fixed e( 2 );
	const Fixed f( 15.5f );

	bool result = c > d;
	std::cout << " c > d " << std::boolalpha << result << std::endl;
	result = c != d;
	std::cout << " c != d " << std::boolalpha << result << std::endl;

	std::cout << "min: " << Fixed::min( c, d ) << std::endl;
	std::cout << "max: " << Fixed::max( c, d ) << std::endl;
	std::cout << "const min: " << Fixed::min( e, f ) << std::endl;
	std::cout << "const max: " << Fixed::max( e, f ) << std::endl;
	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "e * f = " << e * f << std::endl;
	std::cout << "c / d = " << c / d << std::endl;
	d = c++;
	std::cout << "\n1 fract_bit = 1/256 = 0.00390625" << std::endl;
	std::cout << "d = c++ .. print d: " << d << " ; print c: " << c << std::endl;
	std::cout << "++c .. print c: " << ++c << std::endl;
	std::cout << "Reset c = 6, d = 5" << std::endl;
	c = 6;
	d = 5;
	d = c--;
	std::cout << "d = c-- .. print d: " << d << " ; print c: " << c << std::endl;
	std::cout << "--c print c: " << --c << std::endl;

	std::cout << "\nLET'S PUSH THE LIMITS!" << std::endl;
	std::cout << std::endl;
	a = INT_MAX;
	std::cout << "a = INT_MAX, trigger overflow: " << a << std::endl;
	a = INT_MAX / 256;
	std::cout << "a = INT_MAX / 256 -> upper limit: " << a << std::endl;
	a = INT_MIN;
	std::cout << "a = INT_MIN, trigger overflow: " << a << std::endl;
	a = INT_MIN/ 256;
	std::cout << "a = INT_MIN / 256 -> lower limit: " << a << std::endl;
	std::cout << std::endl;
	Fixed f1(8388609.0f);
	std::cout << "f1 = 8388609.0f just above limit, trigger overflow: " << f1 << std::endl;
	Fixed f2(8388607.0f);
	std::cout << "f2 = 8388607.0f just below limit: " << f2 << std::endl;
	std::cout << "\nAnd now let's go crazy and divide by zero!" << std::endl;
	a / 0;

	return 0;
}
