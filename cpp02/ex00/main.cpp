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

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << "get raw bits  for three 0 constructed points" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "set raw bits for point a to 256" << std::endl;
	a.setRawBits(256);
	std::cout << a.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "test assignment operator with value" << std::endl;
	b = a;
	std::cout << b.getRawBits() << std::endl;
	std::cout << std::endl;

	return 0;
}
