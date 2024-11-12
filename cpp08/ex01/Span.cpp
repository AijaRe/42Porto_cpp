/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:08:18 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/12 22:08:47 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(0) {
    //std::cout << "Span default constructor called." << std::endl;
}

Span::Span(unsigned int N) : _N(N) {
    //std::cout << "Span assignment constructor called." << std::endl;
}

Span::Span(const Span &copy) : _N(copy._N) {
    std::cout << "Span copy constructor called." << std::endl;
}

Span::~Span(void) {
    std::cout << "Span destructor called." << std::endl;
}

Span & Span::operator=(const Span &src) {
    std::cout << "Span assignment operator called." << std::endl;
    if (this != &src) {
        this->_N = src._N;
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
    std::cout << "addNumber placeholder" << n << std::endl;
}

unsigned int    Span::shortestSpan(void) {
    std::cout << "shortestSpan placeholder" << std::endl;
    if (_array.size() < 2)
        throw (std::logic_error("Not enough numbers to calculate span."));
}

unsigned int    Span::longestSpan(void) {
    std::cout << "longestSpan placeholder" << std::endl;
    if (_array.size() < 2)
        throw (std::logic_error("Not enough numbers to calculate span."));
}
