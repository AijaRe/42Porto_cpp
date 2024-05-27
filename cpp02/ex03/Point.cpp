/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:57:33 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/26 20:32:26 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
    //std::cout << "Point default constructor called." << std::endl;
}

Point::Point ( const float x, const float y) : _x(x), _y(y){
     //std::cout << "Point assignment constructor called." << std::endl;
}

Point::Point( const Point &src ) : _x(src._x), _y(src._y){
    //std::cout << "Point copy constructor called." << std::endl;
}

Point::~Point( void ) {
    //std::cout << "Point destructor called." << std::endl;
}

Point & Point::operator=( const Point &src ) {
    if (this != &src) {
        (Fixed)this->_x = src._x;
        (Fixed)this->_y = src._y;
    }
    return *this;
}

Fixed   Point::getX ( void ) const {
    return this->_x;
}

Fixed   Point::getY ( void ) const {
    return this->_y;
}