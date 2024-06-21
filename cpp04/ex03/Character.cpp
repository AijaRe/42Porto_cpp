/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/21 17:57:18 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

/* 
** pointers (_inventory) by default are initialized to NULL
*/
Character::Character( void ) : _name("nameless"), _inventory(), _droppedItems(), _dropCount(0), _dropCapacity(0) {
    std::cout << "Character default constructor called." << std::endl;
}

Character::Character( std::string name ) : _name(name), _inventory(), _droppedItems(), _dropCount(0), _dropCapacity(0) {
    std::cout << "Character assignment constructor called." << std::endl;
}

Character::Character( const Character &src ) : _name(src._name), _dropCount(src._dropCount), _dropCapacity(src._dropCapacity) {
    std::cout << "Character copy constructor called." << std::endl;
    for (int i = 0; i < INVENTORY_SLOTS; ++i) {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
    _droppedItems = new AMateria*[_dropCapacity];
    for (int i = 0; i < _dropCount; ++i) {
        _droppedItems[i] = src._droppedItems[i]->clone();
    }
}

Character::~Character( void ) {
    std::cout << "Character destructor called." << std::endl;
    for (int i = 0; i < INVENTORY_SLOTS; ++i) {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
    for (int i = 0; i < _dropCount; ++i) {
        delete _droppedItems[i];
    }
    delete[] _droppedItems;
}

Character & Character::operator=( const Character &src ) {
    std::cout << "Character assignment operator called." << std::endl;
    if (this != &src) {
        if (this->_name != src._name)
            this->_name = src._name;
        for (int i = 0; i < INVENTORY_SLOTS; ++i) {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
            else //is this else necessary? doesn't delete set pointer to null?
                this->_inventory[i] = NULL;
        }
        
        for (int i = 0; i < _dropCount; ++i) {
            delete _droppedItems[i];
        }
        delete[] _droppedItems;
        _dropCount = src._dropCount;
        _dropCapacity = src._dropCapacity;
        _droppedItems = new AMateria*[_dropCapacity];
        for (int i = 0; i < _dropCount; ++i) {
            _droppedItems[i] = src._droppedItems[i]->clone();
        }
    }
    return *this;
}

std::string const & Character::getName( void ) const {
    return this->_name;
}

void    Character::equip( AMateria* m ) {
    for (int i = 0; i < INVENTORY_SLOTS; i++) {
        if(!this->_inventory[i]) {
            this->_inventory[i] = m;
            std::cout << this->_name << " equiping " << m->getType() << std::endl;
            m = NULL; // ownership is transferred to _inventory
            return ;
        }
    }
    // Inventory is full, add to dropped items
    if (m) {
        resizeDropArray();
        _droppedItems[_dropCount++] = m;
        std::cout << this->_name << " Slots full. Dropping " << m->getType() << std::endl;
        m = NULL;
    }   
}

void    Character::unequip( int idx ) {
    if (idx >= 0 && idx < INVENTORY_SLOTS && this->_inventory[idx]) {
        if (this->_dropCount >= this->_dropCapacity) {
            resizeDropArray();
        }
        _droppedItems[_dropCount++] = _inventory[idx];
        std::cout << this->_name << " dropping " << _inventory[idx]->getType() << std::endl;
        this->_inventory[idx] = NULL;
    }
}

void    Character::use( int idx, ICharacter& target ) {
    if (idx >= 0 && idx < INVENTORY_SLOTS && _inventory[idx]) {
        _inventory[idx]->use(target);
        std::cout << "Using " << _inventory[idx]->getType();
        std::cout << " on " << target.getName() << std::endl;
    }
}

AMateria* const * Character::getInventory() const {
    return _inventory;
}

/* 
** multiply capacity by 2 every time the limit is reached to
** optimize operation frequency vs used space
*/
void    Character::resizeDropArray( void ) {
      if (_dropCapacity == 0) {
        _dropCapacity = 2;
        _droppedItems = new AMateria*[_dropCapacity];
    } else {
        _dropCapacity *= 2;
        AMateria** newArray = new AMateria*[_dropCapacity];
        for (int i = 0; i < _dropCount; i++) {
            newArray[i] = _droppedItems[i];
        }
        delete[] _droppedItems;
        _droppedItems = newArray;
    }
}

std::ostream	&operator<<( std::ostream &out, const Character &rhs){
    out << "------------------------------------" << std::endl;
    out << "Character " << rhs.getName() << std::endl;
	for (int i = 0; i < INVENTORY_SLOTS; ++i) {
        if (rhs.getInventory()[i]) {
            out << "  Slot " << i << ": " << rhs.getInventory()[i]->getType() << "\n";
        } else {
            out << "  Slot " << i << ": Empty\n";
        }
    }
	out << "------------------------------------" << std::flush;
	return out; 
}