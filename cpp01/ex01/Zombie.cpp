/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:38:57 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/21 15:31:09 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	//std::cout << "Zombie default constructor called." << std::endl;
	return ;
}
void Zombie::setName( std::string name )
{
	this->name = name;
	return ;
}

void Zombie::setIndex( int index )
{
	this->index = index;
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << this->name << " " << this->index << " destroyed." << std::endl;
	return ;
}

void	Zombie::announce( void ){
	if (!this->name.empty() && this->index >= 0)
		std::cout << this->name << " " << this->index << ": Moar BraiiinnnzzZ..." << std::endl;
	else
		std::cout << "...announce: Missing information for a zombie..." << std::endl;
}
