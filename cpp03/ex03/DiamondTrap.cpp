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

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor called." << std::endl;
    this->_name = "";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name), _name(name)  {
    std::cout << "DiamondTrap assignment constructor called." << std::endl;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap( const DiamondTrap &src ) : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name) {
    std::cout << "DiamondTrap copy constructor called." << std::endl;
    *this = src;
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout << "DiamondTrap destructor called." << std::endl;
}

DiamondTrap & DiamondTrap::operator=( const DiamondTrap &src ) {
    if (this != &src) {
        ClapTrap::operator=(src);
        ScavTrap::operator=(src);
        FragTrap::operator=(src);
        this->_name = src._name;
    }
    return *this;
}

std::string DiamondTrap::getDiamondName ( void ){
    return this->_name;    
}

void    DiamondTrap::whoAmI( void ) {
    std::cout << "DiamondTrap name: " << this->_name << std::endl;
    std::cout << "My ClapTrap name: " << ClapTrap::_name << std::endl;
}

std::ostream	&operator<<( std::ostream &out, const DiamondTrap &rhs ){
    out << "------------------------------------" << std::endl;
    //out << "DiamondTrap " << rhs.getDiamondName() << std::endl;
	out << "Hit Points: " << rhs.getHitPoints() << std::endl;
	out << "Energy Points: " << rhs.getEnergyPoints() << std::endl;
	out << "Attack Power: " << rhs.getAttackDamage() << std::endl;
	out << "------------------------------------" << std::flush;
	return out; 
}
