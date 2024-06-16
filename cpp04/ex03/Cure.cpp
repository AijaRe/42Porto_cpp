/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:44:03 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/16 17:03:04 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {
    std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure( const Cure &src ) : AMateria(src) {
    std::cout << "Cure copy constructor called." << std::endl;
}

Cure::~Cure( void ) {
    std::cout << "Cure destructor called." << std::endl;
}

Cure & Cure::operator=( const Cure &src ) {
    std::cout << "Cure assignment operator called." << std::endl;
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

/* 
** call Cure copy constructor
*/
AMateria*    Cure::clone( void ) const {
    return new Cure(*this);
}