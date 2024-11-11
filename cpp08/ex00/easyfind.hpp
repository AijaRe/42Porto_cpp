/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:08:43 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/11 19:43:52 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

class ValueNotFoundException : public std::exception{
	public:
		const char* what() const throw(){
			return "Value not found.";
		}
};

/* 
** Find the int value in a container that holds integers
** (e.g., vector, list, deque)
*/
template<typename T>
typename T::const_iterator	easyfind(T& container, int value){
	typename T::const_iterator it;
	
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw ValueNotFoundException();
	}
	return it;
}

#endif
