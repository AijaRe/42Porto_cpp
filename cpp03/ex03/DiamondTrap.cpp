/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:14:09 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/26 19:19:46 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* 
** the last derived class constructor that is called 
** determines the values ofshared member variables
** => attributes from FragTrap are used
*/
DiamondTrap::DiamondTrap( void ) : _name("") {
    std::cout << "DiamondTrap default constructor called." << std::endl;
    ClapTrap::_name = "_clap_trap";
    ScavTrap scav;
    this->_hitPoints = FragTrap::getEnergyPoints(); //100
    this->_energyPoints = scav.getEnergyPoints(); //50
    this->_attackDamage = FragTrap::getAttackDamage(); //30
}

DiamondTrap::DiamondTrap( std::string name ) : _name(name)  {
    std::cout << "DiamondTrap assignment constructor called." << std::endl;
    ClapTrap::_name = name + "_clap_trap";
    ScavTrap scav(name);
    this->_hitPoints = FragTrap::getHitPoints(); //100
    this->_energyPoints = scav.getEnergyPoints(); //50
    this->_attackDamage = FragTrap::getAttackDamage(); //30
}

DiamondTrap::DiamondTrap( const DiamondTrap &src ) : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name) {
    std::cout << "DiamondTrap copy constructor called." << std::endl;
    *this = src;
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout << "DiamondTrap " + this->_name + " destructor called." << std::endl;
}

DiamondTrap & DiamondTrap::operator=( const DiamondTrap &src ) {
    std::cout << "DiamondTrap assignment operator overload called." << std::endl;
    if (this != &src) {
        this->_name = src._name;
        this->_hitPoints = src._hitPoints;
        this->_energyPoints = src._energyPoints;
        this->_attackDamage = src._attackDamage;
        this->ClapTrap::_name = src.ClapTrap::_name;
    }
    return *this;
}

std::string DiamondTrap::getDiamondName ( void ) const {
    return this->_name;    
}

void    DiamondTrap::whoAmI( void ) {
    std::cout << "DiamondTrap name: " << this->_name << std::endl;
    std::cout << "My ClapTrap name: " << ClapTrap::_name << std::endl;
}

std::ostream	&operator<<( std::ostream &out, const DiamondTrap &rhs ){
    out << "------------------------------------" << std::endl;
    out << "DiamondTrap " << rhs.getDiamondName() << std::endl;
	out << "Hit Points: " << rhs.getHitPoints() << std::endl;
	out << "Energy Points: " << rhs.getEnergyPoints() << std::endl;
	out << "Attack Power: " << rhs.getAttackDamage() << std::endl;
	out << "------------------------------------" << std::flush;
	return out; 
}
