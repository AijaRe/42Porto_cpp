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
** For each edge, check if the cross product is zero (indicating collinearity - three points on the same line) 
** and if the point lies within the bounds of the line segment using the dot product.
** Positive dot product - vectors are the same direction
** dot product of same length vectors == square length of a vector
*/
static bool    is_on_edge( Fixed const &cp,  Point const &A, Point const &B, Point const &point ){
    // Check if cross product is zero, indicating collinearity
    if (cp == Fixed(0)) {
        // Calculate vectors AP and AB
        Fixed APx = point.getX() - A.getX();
        Fixed APy = point.getY() - A.getY();
        Fixed ABx = B.getX() - A.getX();
        Fixed ABy = B.getY() - A.getY();

        // Calculate dot product of AP and AB
        Fixed dotProduct = APx * ABx + APy * ABy;

        // Check if point lies within the line segment AB 
        if (dotProduct >= Fixed(0) && dotProduct <= ABx * ABx + ABy * ABy) {
            return true;
        }
    }
    return false; // Point is not on the edge
}

/*
** cross product is either positive or negative, depending on the plane
** all cross products with the same signs mean the planes overlap
*/
bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed cp1 = crossProduct(a, b, point);
    Fixed cp2 = crossProduct(b, c, point);
    Fixed cp3 = crossProduct(c, a, point);

    if (is_on_edge(cp1, a, b, point) ||
        is_on_edge(cp2, b, c, point) ||
        is_on_edge(cp3, c, a, point)) {
            std::cout << "IS ON EDGE" << std::endl;
            return false;
    }

    // Check if all cross products have the same sign (point is inside the trangle)
    bool isInside = (cp1 > Fixed(0) && cp2 > Fixed(0) && cp3 > Fixed(0)) ||
                    (cp1 < Fixed(0) && cp2 < Fixed(0) && cp3 < Fixed(0));

    return isInside;
}