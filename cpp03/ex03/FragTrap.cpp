/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:14:01 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/03 19:22:56 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {
    std::cout << "FragTrap default constructor called." << std::endl;
    this->_name = "";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name){
    std::cout << "FragTrap assignment constructor called." << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap( const FragTrap &src ) : ClapTrap(src) {
    std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap::~FragTrap( void ) {
    std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap & FragTrap::operator=( const FragTrap &src ) {
    if (this != &src) {
        ClapTrap::operator=(src);
    }
    std::cout << "FragTrap Copy assignment operator overload called." << std::endl;
    return *this;
}

std::ostream	&operator<<( std::ostream &out, const FragTrap &rhs ){
    out << "------------------------------------" << std::endl;
    out << "ScavTrap " << rhs.getName() << std::endl;
	out << "Hit Points: " << rhs.getHitPoints() << std::endl;
	out << "Energy Points: " << rhs.getEnergyPoints() << std::endl;
	out << "Attack Power: " << rhs.getAttackDamage() << std::endl;
	out << "------------------------------------" << std::flush;
	return out; 
}

void    FragTrap::highFivesGuys( void ) {
    std::cout << "ScavTrap " << this->_name << ": Gimme five!" << std::endl;
}
