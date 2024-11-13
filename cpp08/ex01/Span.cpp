/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:08:18 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/13 22:16:06 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(0) {
    //std::cout << "Span default constructor called." << std::endl;
    _array.reserve(0);
}

Span::Span(unsigned int N) : _N(N) {
    //std::cout << "Span assignment constructor called." << std::endl;
     _array.reserve(N);
}

Span::Span(const Span &copy) : _N(copy._N), _array(copy._array) {
    //std::cout << "Span copy constructor called." << std::endl;
}

Span::~Span(void) {
    //std::cout << "Span destructor called." << std::endl;
}

Span & Span::operator=(const Span &src) {
    //std::cout << "Span assignment operator called." << std::endl;
    if (this != &src) {
        _N = src._N;
        _array = src._array;
    }
    return *this;
}

const char* Span::FullSpanException::what( void ) const throw() {
    return "Cannot add number. Span is full!";
}

/* 
** add a single number to the span
** thorw an exception if there are already N elements stored
*/
void    Span::addNumber(int n) {
    if (_array.size() < _N)
        _array.push_back(n);
    else
        throw (Span::FullSpanException());
}

/* 
** calculate the largest difference between two numbers
** throw an exception if there is only one number or none stored
*/
unsigned int   Span::longestSpan(void) const {
    if (_array.size() < 2)
        throw (std::logic_error("Not enough numbers to calculate span."));
    std::vector<int>::const_iterator arrayMax = std::max_element(_array.begin(), _array.end());
    std::vector<int>::const_iterator arrayMin = std::min_element(_array.begin(), _array.end());
    return (*arrayMax - *arrayMin);
}

/* 
** calculate the smallest difference between two numbers
** throw an exception if there is only one number or none stored
*/
unsigned int    Span::shortestSpan(void) const {
    if (_array.size() < 2)
        throw (std::logic_error("Not enough numbers to calculate span."));
    std::vector<int> sorted = _array;
    std::sort(sorted.begin(), sorted.end());
    unsigned int shortestSpan = Span::longestSpan();
    for (size_t i = 1; i < sorted.size(); i++)
    {
        unsigned int span = sorted[i] - sorted[i - 1];
        if (span < shortestSpan)
            shortestSpan = span;
    }
    return (shortestSpan);
}

