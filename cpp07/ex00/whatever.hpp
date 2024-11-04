/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:07:06 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/31 19:07:06 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void swap(T& x, T& y){
	T temp;

	temp = x;
	x = y;
	y = temp;
}

template<typename T>
T const& min(T const& x, T const& y){
	return (x < y ? x : y);
}

template<typename T>
T const& max(T const& x, T const& y){
	return (x > y ? x : y);
}

#endif
