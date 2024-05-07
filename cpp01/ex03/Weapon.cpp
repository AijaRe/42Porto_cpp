/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:57:59 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/07 19:59:32 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {
    std::cout << "Weapon default constructor called." << std::endl;
}

Weapon::Weapon(std::string type) : _type(type) {
    std::cout << "Weapon with type constructor called." << std::endl;    
}

Weapon::~Weapon(void) {
    std::cout << "Weapon destructor called." << std::endl;
}

void    Weapon::setType(std::string type){
    this->_type = type;
}

const std::string&  Weapon::getType(void) const {
    return this->_type;
}
