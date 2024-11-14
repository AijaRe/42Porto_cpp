/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:08:18 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/14 18:44:40 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(0) {
	//std::cout << "Span default constructor called." << std::endl;
	_elements.reserve(0);
}

Span::Span(unsigned int N) : _N(N) {
	//std::cout << "Span assignment constructor called." << std::endl;
	 _elements.reserve(N);
}

Span::Span(const Span &copy) : _N(copy._N), _elements(copy._elements) {
	//std::cout << "Span copy constructor called." << std::endl;
}

Span::~Span(void) {
	//std::cout << "Span destructor called." << std::endl;
}

Span & Span::operator=(const Span &src) {
	//std::cout << "Span assignment operator called." << std::endl;
	if (this != &src) {
		_N = src._N;
		_elements = src._elements;
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
	if (_elements.size() < _N)
		_elements.push_back(n);
	else
		throw (Span::FullSpanException());
}

/* 
** calculate the largest difference between two numbers
** throw an exception if there is only one number or none stored
*/
unsigned int   Span::longestSpan(void) const {
	if (_elements.size() < 2)
		throw (std::logic_error("Not enough numbers to calculate span."));
	std::vector<int>::const_iterator arrayMax = std::max_element(_elements.begin(), _elements.end());
	std::vector<int>::const_iterator arrayMin = std::min_element(_elements.begin(), _elements.end());
	return (*arrayMax - *arrayMin);
}

/* 
** calculate the smallest difference between two numbers
** throw an exception if there is only one number or none stored
*/
unsigned int    Span::shortestSpan(void) const {
	if (_elements.size() < 2)
		throw (std::logic_error("Not enough numbers to calculate span."));
	std::vector<int> sorted = _elements;
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

/* 
** create vector iterator
** check if the iterator is within the bounds of the span
** generate random numbers by calling rand()
** add the numbers to the span vector 
*/
void	Span::fillSpan(std::vector<int> numbers) {
	std::vector<int>::iterator begin = numbers.begin();
	std::vector<int>::iterator end = numbers.end();
	
	if (std::distance(begin, end) > _N)
		throw (Span::FullSpanException());
	
	std::srand(time(0));
	std::generate(begin, end, rand);
	
	std::vector<int>::iterator it;
	for (it = begin; it != end; it++) {
		_elements.push_back(*it);
	}
	std::cout << std::endl;
}

