/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:22:58 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/03 21:16:02 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap assignment constructor called." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &src ) : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage) {
    std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap( void ) {
    std::cout << "ClapTrap " + this->_name + " destructor called." << std::endl;
}

ClapTrap & ClapTrap::operator=( const ClapTrap &src ) {
    std::cout << "ClapTrap assignment operator overload called." << std::endl;
    if (this != &src) {
        this->_name = src._name;
        this->_hitPoints = src._hitPoints;
        this->_energyPoints = src._energyPoints;
        this->_attackDamage = src._attackDamage;
    }
    return *this;
}

std::ostream	&operator<<( std::ostream &out, const ClapTrap &rhs){
    out << "------------------------------------" << std::endl;
    out << "ClapTrap " << rhs.getName() << std::endl;
	out << "Hit Points: " << rhs.getHitPoints() << std::endl;
	out << "Energy Points: " << rhs.getEnergyPoints() << std::endl;
	out << "Attack Power: " << rhs.getAttackDamage() << std::endl;
	out << "------------------------------------" << std::flush;
	return out; 
}

void    ClapTrap::attack( const std::string& target ){
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        this->_energyPoints--;
        std::cout << "ClapTrap " + this->_name + " attacks " +  target;
        std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " + this->_name + " cannot attack." << std::endl;
    
}

void    ClapTrap::takeDamage( unsigned int amount ){
    if (this->_hitPoints == 0){
        std::cout << "You're tickling a ghost..." << std::endl;
        std::cout << "RIP ClapTrap " << this->_name << std::endl;
        return ;
    }
    if (this->_hitPoints <= amount) {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " was attacked by " << amount << " damage points!" << std::endl;
        std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
    }
    else {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " was attacked by " << amount << " damage points!" << std::endl;
        std::cout << "ClapTrap " << this->_name << " hit points decreased to " << this->_hitPoints << std::endl;
    }
}

/* 
** casting to int reduces the input range, 
** but let's do error treatment for negative values
** and values larger than unsigned int since
** larger values will wrap around and become negative
*/
void    ClapTrap::beRepaired( unsigned int amount ){
     if (static_cast<int>(amount) < 0) {
        std::cerr << "Silly repair number. Nothing to be done." << std::endl;
        return ; 
    }
    if (this->_energyPoints > 0 && this->_hitPoints > 0 ) {
        this->_energyPoints--;
        this->_hitPoints += amount;
        std::cout << "ClapTrap " << this->_name << " was repaired by " << amount << " points! " << std::endl;
        std::cout << "Hit points increased to " << this->_hitPoints << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->_name << " cannot be repaired." << std::endl;
}

std::string     ClapTrap::getName( void ) const {
    return this->_name;
}
unsigned int    ClapTrap::getHitPoints( void ) const {
    return this->_hitPoints;
}

unsigned int    ClapTrap::getEnergyPoints( void ) const{
    return this->_energyPoints;
}

unsigned int    ClapTrap::getAttackDamage( void ) const{
    return this->_attackDamage;
}

/* 
** casting to int reduces the input range, 
** but let's do error treatment for negative values
** and values larger than unsigned int since
** larger values will wrap around and become negative
*/
void            ClapTrap::setAttackDamage( unsigned int damage ){
    if (static_cast<int>(damage) < 0) {
        std::cerr << "Silly damage number. Nothing to be done." << std::endl;
        return ; 
    }
    this->_attackDamage = damage;
}
