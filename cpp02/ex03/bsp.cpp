/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:08:18 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/26 20:08:18 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** Function to calculate cross product of vectors AB and AP 
*/
static Fixed crossProduct(const Point &A, const Point &B, const Point &P) {
    Fixed ABx = B.getX() - A.getX();
    Fixed ABy = B.getY() - A.getY();
    Fixed APx = P.getX() - A.getX();
    Fixed APy = P.getY() - A.getY();
    return ABx * APy - ABy * APx;
}

/*
** cross product is either positive or negative, depending on the plane
** all cross products with the same signs mean the planes overlap
*/
bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed cp1 = crossProduct(a, b, point);
    Fixed cp2 = crossProduct(b, c, point);
    Fixed cp3 = crossProduct(c, a, point);

    // Check if all cross products have the same sign (point is inside the trangle)
    // If any cross product is zero, the point is on the edge or vertex, or outside
    bool isInside = (cp1 > Fixed(0) && cp2 > Fixed(0) && cp3 > Fixed(0)) ||
                    (cp1 < Fixed(0) && cp2 < Fixed(0) && cp3 < Fixed(0));

    return isInside;
}
