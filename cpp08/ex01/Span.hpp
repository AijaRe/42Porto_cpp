/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:08:21 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/12 22:04:15 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

/* 
** Vectors - sequence containers representing arrays that can change in size
*/
class Span {
    public:
        Span(void);
        Span(unsigned int N);
        Span(const Span &copy);
        ~Span(void);
        Span & operator=(const Span &src);

        //exceptions
        class FullSpanException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};
        
        //member funcrions
        void addNumber(int n);
        unsigned int    shortestSpan(void);
        unsigned int    longestSpan(void);

        //void  fillSpan(int min, int max);
        
    private:
        unsigned int _N; // Maximum number of elements
        std::vector<int> _array;
        
};

#endif // SPAN_HPP
