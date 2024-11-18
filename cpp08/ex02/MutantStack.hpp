/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:55:24 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/18 22:15:16 by arepsa           ###   ########.fr       */
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

		//define the iterator types based on the underlying container's iterators
		//container_type is a typedef within std::stack that represents this underlying container type
		typedef typename std::stack<T>::container_type::iterator	iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

		iterator		begin();
		iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;
		
};

#include "MutantStack.tpp"

#endif
