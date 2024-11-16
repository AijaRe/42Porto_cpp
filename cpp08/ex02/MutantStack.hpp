/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:55:24 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/16 11:10:23 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void);
		MutantStack<T>(const MutantStack<T> &copy);
		~MutantStack(void);
		MutantStack<T> & operator=(const MutantStack<T> &src);
		
	/* The c refers to the underlying container of the std::stack.
	** The std::stack class is a container adaptor that uses another container
	** (by default, std::deque) to store the elements. 
	** The c represents this underlying container.
	** By accesing c, you can use the iterators of the underlying container 
	** to iterate over the elements of the stack.
	*/
};

#include "MutantStack.tpp"

#endif
