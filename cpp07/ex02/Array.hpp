/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:59:17 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/03 21:18:43 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename A>
class Array {
    public:
        Array<A>(void);
        Array<A>(unsigned int n);
        Array<A>(const Array<A> &copy);
        ~Array<A>(void);
        Array <A>& operator=(const Array<A> &src);

        size_t size() const;

        class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};
        
    private:
        A* _array;
        size_t _size;
};

#include "Array.tpp"

#endif // ARRAY_HPP
