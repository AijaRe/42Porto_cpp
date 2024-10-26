/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:47:23 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/26 16:45:43 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
    std::cout << "Serializer default constructor called." << std::endl;
}

Serializer::Serializer(const Serializer &copy) {
    std::cout << "Serializer copy constructor called." << std::endl;
    *this = copy;
}

Serializer::~Serializer(void) {
    std::cout << "Serializer destructor called." << std::endl;
}

Serializer & Serializer::operator=(const Serializer &src) {
    std::cout << "Serializer assignment operator called." << std::endl;
    if (this != &src) {
        return *this;
    }
    return *this;
}

/* 
**  reinterpret_cast converts any pointer type to any other pointer type
** (or an integer type) and vice versa,
** without changing the underlying bit pattern. 
*/
uintptr_t	Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
}
