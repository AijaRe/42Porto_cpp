/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:57:33 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/28 11:53:31 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
    //std::cout << "Point default constructor called." << std::endl;
}

Point::Point ( const float x, const float y) : _x(x), _y(y){
     //std::cout << "Point assignment constructor called." << std::endl;
}

Point::Point( const Point &src ) : _x(src._x), _y(src._y) {
    //std::cout << "Point copy constructor called." << std::endl;
}

Point::~Point( void ) {
    //std::cout << "Point destructor called." << std::endl;
}

//can't change const initialized variables
Point & Point::operator=( const Point &src ) {
    (void) src;
    return *this;
}

Fixed   Point::getX ( void ) const {
    return this->_x;
}

Fixed   Point::getY ( void ) const {
    return this->_y;
}
