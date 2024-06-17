/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/17 18:04:41 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name("nameless") {
    std::cout << "Character default constructor called." << std::endl;
}

Character::Character( const Character &src ) : _name(src._name) {
    std::cout << "Character copy constructor called." << std::endl;
    *this = src;
}

Character::Character( std::string name ) : _name(name) {
    std::cout << "Character assignment constructor called." << std::endl;
}

Character::~Character( void ) {
    std::cout << "Character destructor called." << std::endl;
}

Character & Character::operator=( const Character &src ) {
    std::cout << "Character assignment operator called." << std::endl;
    if (this != &src) {
        this->_name = src._name;
    }
    return *this;
}

std::string const & Character::getName( void ) const {
    return this->_name;
}
