/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:47:26 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/26 16:19:21 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

/* 
** uintptr_t is an unsigned integer type 
** that is capable of storing a data pointer
*/
class Serializer {
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	private:
		// Private constructors and destructor to prevent instantiation
		Serializer(void);
		Serializer(const Serializer &copy);
		~Serializer(void);
		Serializer & operator=(const Serializer &src);
};

#endif // SERIALIZER_HPP
