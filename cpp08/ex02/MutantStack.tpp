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

template<typename T>
MutantStack<T>::MutantStack(void) :  {
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