/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:50:38 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/09 20:50:38 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _slots() {
	//std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &src ) {
	//std::cout << "MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < LEARN_SLOTS; i++ ) {
		if (src._slots[i])
			this->_slots[i] = src._slots[i]->clone();
	}
}

MateriaSource::~MateriaSource( void ) {
	//std::cout << "MateriaSource destructor called." << std::endl;
	 for (int i = 0; i < LEARN_SLOTS; i++ ) {
		if (this->_slots[i])
			delete this->_slots[i];
	}
}

MateriaSource & MateriaSource::operator=( const MateriaSource &src ) {
	//std::cout << "MateriaSource assignment operator called." << std::endl;
	if (this != &src) {
		for (int i = 0; i < LEARN_SLOTS; i++ ) {
			if (this->_slots[i])
				delete this->_slots[i];
			if (src._slots[i])
				this->_slots[i] = src._slots[i]->clone();
		}
	}
	return *this;
}

/* 
** learn at most 4 materias, do nothing if slots are full
*/
void    MateriaSource::learnMateria( AMateria* m ) {
	for (int i = 0; i < LEARN_SLOTS; i++) {
		if (this->_slots[i] == NULL) {
			this->_slots[i] = m;
			std::cout << "Learning " << m->getType() << std::endl;
			m = NULL;
			return ;
		}
	}
	std::cout << "No available slots, deleting the materia." << std::endl;
	delete m;
}

/* 
** returns AMateria clone
** delete after using
*/
AMateria*   MateriaSource::createMateria( std::string const & type ){
	if (type == "cure" || type == "ice") {
		for (int i = 0; i < LEARN_SLOTS; i++) {
			if (this->_slots[i] && this->_slots[i]->getType() == type) {
				std::cout << "Creating " << this->_slots[i]->getType() << std::endl;
				return (this->_slots[i]->clone());
			}
		}
	}
	std::cout << "Materia not found." << std::endl;
	return 0;
}
