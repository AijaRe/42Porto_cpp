/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:33:57 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/21 16:34:10 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
	this->_weapon = weapon;
}

HumanA::~HumanA(void) {
	return ;
}

void	HumanA::attack(void){
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
