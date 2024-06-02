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
#include "Point.hpp"

const int Fixed::_fract_bits = 8;

int main( void ) {
	bool test;

 	Point p1(1.5f, 2.5f);
    Point p2(3.0f, 4.0f);

    std::cout << "Before assignment:" << std::endl;
    std::cout << "p1: " << p1.getX() << " " << p1.getY()  << std::endl;
    std::cout << "p2: "<< p2.getX() << " " << p2.getY() << std::endl;

    p2 = p1;

    std::cout << "After assignment:" << std::endl;
    std::cout << "p1: " << p1.getX() << " " << p1.getY() << std::endl;
    std::cout << "p2: " << p2.getX() << " " << p2.getY() << std::endl;

	Point p3(1.5f, 2.5f);
    Point p4(p3);
	std::cout << "p3: " << p3.getX() << " " << p3.getY() << std::endl;
    std::cout << "p4: " << p4.getX() << " " << p4.getY() << std::endl;

	std::cout << "For the triangle with the points A(0,0) B(10 ,30) and C(20,0): " << std::endl;
    test = bsp(Point(0, 0), Point(10, 20), Point(25, 0), Point(10,10));
	std::cout << "Point: 10, 10 (inside): " << std::boolalpha << test << std::endl;
	test = bsp(Point(0, 0), Point(10, 20), Point(25, 0), Point(30,15));
    std::cout << "Point 30, 15(outside): " << std::boolalpha << test << std::endl;
	test = bsp(Point(0, 0), Point(10, 20), Point(25, 0), Point(5,10));
    std::cout << "Point 5,10(line AB): " << std::boolalpha << test << std::endl;
	test = bsp(Point(0, 0), Point(10, 20), Point(25, 0), Point(20,0));
	std::cout << "Point 20,0(line AC): " << std::boolalpha << test << std::endl;
	test = bsp(Point(0, 0), Point(10, 20), Point(25, 0), Point(17.5,10));
	std::cout << "Point 17.5,10(line BC): " << std::boolalpha << test << std::endl;
	test = bsp(Point(0, 0), Point(10, 20), Point(25, 0), Point(10,20));
	std::cout << "Point 10,20(vertix): " << std::boolalpha << test << std::endl;
	test = bsp(Point(0, 0), Point(10, 20), Point(10, 20), Point(10,10));
	std::cout << "Repeated B and C: " << std::boolalpha << test << std::endl;
	test = bsp(Point(0, 0), Point(10, 20), Point(25, 0), Point(15,5));
	std::cout << "Point 15,5(inside): " << std::boolalpha << test << std::endl;
	
	return 0;
}
