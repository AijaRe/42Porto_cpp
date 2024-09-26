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
	/*Fixed a( 6 );
	Fixed b( 5 );
	const Fixed c( 12 );
	const Fixed d( 15.5f );

	bool result = a > b;
	std::cout << " a > b " << std::boolalpha << result << std::endl;
	result = a != b;
	std::cout << " a != b " << std::boolalpha << result << std::endl;

	std::cout << "min: " << Fixed::min( a, b ) << std::endl;
	std::cout << "max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "const min: " << Fixed::min( c, d ) << std::endl;
	std::cout << "const max: " << Fixed::max( c, d ) << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	b = a++;
	std::cout << "b = a++ .. print b: " << b << std::endl;
	std::cout << "b = a++ .. print a: " << a << std::endl;
	std::cout << "++a " << ++a << std::endl;
	a = 6;
	b = 5;
	b = a--;
	std::cout << "b = a-- .. print b: " << b << std::endl;
	std::cout << "b = a-- .. print a: " << a << std::endl;
	std::cout << "--a " << --a << std::endl;*/

	return 0;
}
