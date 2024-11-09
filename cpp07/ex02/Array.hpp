/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:59:17 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/09 12:10:58 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
    public:
        Array<T>(void);
        Array<T>(unsigned int n);
        Array<T>(const Array<T> &copy);
        ~Array<T>(void);
        Array <T>& operator=(const Array<T> &src);
        T& operator[](int index);
        const T& operator[](int index) const;

        size_t size() const;

        class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};
        
    private:
        T* _array;
        size_t _size;
};

#include "Array.tpp"

#endif // ARRAY_HPP
