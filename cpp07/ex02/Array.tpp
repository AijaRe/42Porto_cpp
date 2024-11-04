/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:59:09 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/03 21:25:53 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename A>
Array<A>::Array(void) : _size(0) {
    _array = new A[_size];
    std::cout << "Array default constructor called." << std::endl;
}

template<typename A>
Array<A>::Array(unsigned int n) : _size(n) {
    _array = new A[_size];
    std::cout << "Array default constructor called." << std::endl;
}

template<typename A>
Array<A>::Array(const Array &copy) {
    std::cout << "Array copy constructor called." << std::endl;
    *this = copy;
}

template<typename A>
Array<A>::~Array(void) {
    std::cout << "Array destructor called." << std::endl;
}

template<typename A>
Array<A> & Array<A>::operator=(const Array &src) {
    std::cout << "Array assignment operator called." << std::endl;
    if (this != &src) {
        // Implement assignment
    }
    return *this;
}

template<typename A>
const char*	Array<A>::OutOfBoundsException::what( void ) const throw() {
	return "Array is out of bounds!";
}
