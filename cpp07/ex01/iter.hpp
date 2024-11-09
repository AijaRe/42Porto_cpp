/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:20:55 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/31 19:20:55 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template< typename T >
void	printItem(T const& item) {
	std::cout << item << " ";
}

/* 
** const T* for the array parameter allows it to work 
** with both const and non-const arrays.  
*/
template< typename T>
void	iter(T* arr, int len, void (*func)(const T & item)) {
	for (int i = 0; i < len; i++) {
		func(arr[i]);
	}
}

#endif
