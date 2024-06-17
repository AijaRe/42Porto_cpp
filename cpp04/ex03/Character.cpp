/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/17 19:36:34 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

/* 
** pointers (_inventory) by default are initialized to nullptr
*/
Character::Character( void ) : _name("nameless"), _inventory() {
    std::cout << "Character default constructor called." << std::endl;
}

Character::Character( const Character &src ) : _name(src._name) {
    std::cout << "Character copy constructor called." << std::endl;
     for (int i = 0; i < SLOTS; ++i) {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = nullptr;
    }
}

Character::Character( std::string name ) : _name(name), _inventory() {
    std::cout << "Character assignment constructor called." << std::endl;
}

Character::~Character( void ) {
    std::cout << "Character destructor called." << std::endl;
     for (int i = 0; i < SLOTS; ++i) {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
}

Character & Character::operator=( const Character &src ) {
    std::cout << "Character assignment operator called." << std::endl;
    if (this != &src) {
        if (this->_name != src._name)
            this->_name = src._name;
        for (int i = 0; i < SLOTS; ++i) {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
            else //is this else necessary? doesn't delete set pointer to null?
                this->_inventory[i] = nullptr;
        }
    }
    return *this;
}

std::string const & Character::getName( void ) const {
    return this->_name;
}

void    Character::equip( AMateria* m ) {
    for (int i = 0; i > SLOTS; i++) {
        if(!this->_inventory[i])
            this->_inventory[i] = m;
            std::cout << this->_name << " equiping " << m->getType() << std::endl;
            m = NULL; // what do you mean by Assuming ownership is transferred to _inventory?
            break ;
    }
}

void    Character::unequip( int idx ) {
    if (idx >= 0 && idx < SLOTS && this->_inventory[idx])
        this->_inventory[idx] = NULL;
}

void    Character::use( int idx, ICharacter& target ) {
    if (idx >= 0 && idx < SLOTS && _inventory[idx])
        _inventory[idx]->use(target);
        std::cout << "Using " << _inventory[idx]->getType();
        std::cout << " on " << target.getName() << std::endl;
}
