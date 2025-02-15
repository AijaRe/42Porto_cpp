/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:57:59 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/09 18:25:35 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {
    return ;
}

Weapon::Weapon(std::string type) : _type(type) {
    return ;  
}

Weapon::~Weapon(void) {
    return ;
}

void    Weapon::setType(std::string type){
    this->_type = type;
}

const std::string&  Weapon::getType(void) const {
    return this->_type;
}
