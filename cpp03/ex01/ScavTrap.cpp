/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:31:31 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/30 21:13:54 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
    std::cout << "ScavTrap default constructor called." << std::endl;
    this->_name = "";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap( const ScavTrap &src ) : ClapTrap( src ){
    std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name){
    std::cout << "ScavTrap assignment constructor called." << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::~ScavTrap( void ) {
    std::cout << "ScavTrap " + this->_name + " destructor called." << std::endl;
}

ScavTrap & ScavTrap::operator=( const ScavTrap &src ) {
    if (this != &src) {
        ClapTrap::operator=(src);
    }
    std::cout << "ScavTrap assignment operator overload called." << std::endl;
    return *this;
}

std::ostream	&operator<<( std::ostream &out, const ScavTrap &rhs){
    out << "------------------------------------" << std::endl;
    out << "ScavTrap " << rhs.getName() << std::endl;
	out << "Hit Points: " << rhs.getHitPoints() << std::endl;
	out << "Energy Points: " << rhs.getEnergyPoints() << std::endl;
	out << "Attack Power: " << rhs.getAttackDamage() << std::endl;
	out << "------------------------------------" << std::flush;
	return out; 
}

void    ScavTrap::guardGate(){
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}