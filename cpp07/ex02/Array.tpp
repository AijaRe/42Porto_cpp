/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:59:09 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/08 18:27:11 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(void) :  _array(NULL), _size(0) {
    //std::cout << "Array default constructor called." << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    _array = new T[_size];
    //std::cout << "Array assignment constructor called." << std::endl;
}

template<typename T>
Array<T>::Array(const Array &copy) : _size(copy._size) {
    //std::cout << "Array copy constructor called." << std::endl;
    this->_array = new T[this->_size];
    for (unsigned int i = 0; i < this->_size; i++ ) {
        this->_array[i] = copy._array[i];
    }
}

template<typename T>
Array<T>::~Array(void) {
    //std::cout << "Array destructor called." << std::endl;
    delete[] this->_array;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array &src) {
    //std::cout << "Array assignment operator called." << std::endl;
    if (this != &src) {
        delete[] this->_array;
        this->_size = src._size;
        this->_array = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++ ) {
            this->_array[i] = src._array[i];
        }
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](int index) {
    if (index >= static_cast<int>(this->_size) || index < 0)
        throw OutOfBoundsException();
    return this->_array[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const {
    if (index >= static_cast<int>(this->_size) || index < 0)
        throw OutOfBoundsException();
    return this->_array[index];
}

template<typename T>
size_t  Array<T>::size ( void ) const {
    return this->_size;
}

template<typename T>
const char*	Array<T>::OutOfBoundsException::what( void ) const throw() {
	return "Array is out of bounds!";
}
