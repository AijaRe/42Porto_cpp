/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:36:17 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/16 10:36:17 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

//initialize explicitly the base class std::stack<T>
template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {
	//std::cout << "MutantStack default constructor called." << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy) {
	//std::cout << "MutantStack copy constructor called." << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack(void) {
	//std::cout << "MutantStack destructor called." << std::endl;
}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> &src) {
	//std::cout << "MutantStack assignment operator called." << std::endl;
	if (this != &src) {
		std::stack<T>::operator=(src);
	}
	return *this;
}

/* 
** The std::stack class is a container adaptor that uses another container
** (by default, std::deque) to store the elements. 
** The c refers to the underlying container of the std::stack.
** By accesing c, you can use the iterators of the underlying container 
** to iterate over the elements of the stack.
*/

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(){
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(){
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const{
	return this->c.end();
}

