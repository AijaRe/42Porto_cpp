/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:38:57 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/05 18:04:32 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    //std::cout << "Zombie default constructor called." << std::endl;
	return ;
}
Zombie::Zombie(std::string name) : name(name)
{
    //std::cout << "Zombie " << this->name << " created." << std::endl;
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->name << " destroyed." << std::endl;
	return ;
}

void    Zombie::announce(void){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}