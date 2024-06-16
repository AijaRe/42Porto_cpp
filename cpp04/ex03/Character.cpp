/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/15 21:43:57 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) {
    std::cout << "Character default constructor called." << std::endl;
}

Character::Character( const Character &src ) {
    std::cout << "Character copy constructor called." << std::endl;
    *this = src;
}

Character::~Character( void ) {
    std::cout << "Character destructor called." << std::endl;
}

Character & Character::operator=( const Character &src ) {
    std::cout << "Character assignment operator called." << std::endl;
    if (this != &src) {
        // Implement assignment
    }
    return *this;
}
