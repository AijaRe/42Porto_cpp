/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:38:57 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/04 15:38:45 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Zombie default constructor called." << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->name << " destroyed." << std::endl;
	return ;
}

void    Zombie::announce(void){
    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name){
    this->name = name;
}

std::string Zombie::getName(void) const{
    return this->name;
}
