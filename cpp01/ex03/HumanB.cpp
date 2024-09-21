/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:36:32 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/21 16:40:36 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	return ;
}

HumanB::~HumanB(void) {
	return ;
}

void	HumanB::setWeapon(Weapon& weapon){
	this->_weapon = &weapon;
}

/* protect attack in case of NULL pointer for weapon */
void	HumanB::attack(void){
	if (this->_weapon) {
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	}
	else
		std::cout << this->_name << " can only attack with personal charm. No weapon detected." << std::endl;
}
