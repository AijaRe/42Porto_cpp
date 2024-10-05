/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:44:03 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/05 18:19:17 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure( void ) : AMateria("cure") {
	std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure( const Cure &src ) : AMateria(src) {
	std::cout << "Cure copy constructor called." << std::endl;
}

Cure::~Cure( void ) {
	std::cout << "Cure destructor called." << std::endl;
}

/* 
** any materia's type is set on inicialization
** and does not change throughout lifecycle 
*/
Cure & Cure::operator=( const Cure &src ) {
	std::cout << "Cure assignment operator called." << std::endl;
	(void)src;
	return *this;
}

/* 
** call Cure copy constructor
*/
AMateria*    Cure::clone( void ) const {
	return new Cure(*this);
}

void    Cure::use( ICharacter& target ) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
