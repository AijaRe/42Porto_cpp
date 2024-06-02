/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:57:37 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/02 11:34:26 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point( void );
        Point ( const float x, const float y);
        Point( const Point &src );
        ~Point( void );
        Point & operator=( const Point &src );
        Fixed getX( void ) const;
        Fixed getY( void ) const;
};

bool    bsp( Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP