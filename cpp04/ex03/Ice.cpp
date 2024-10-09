/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:44:09 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/09 21:07:15 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice( void ) : AMateria("ice") {
	//std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice( const Ice &src ) : AMateria(src) {
	//std::cout << "Ice copy constructor called." << std::endl;
}

Ice::~Ice( void ) {
	//std::cout << "Ice destructor called." << std::endl;
}

/* 
** any materia's type is set on inicialization
** and does not change throughout lifecycle 
*/
Ice & Ice::operator=( const Ice &src ) {
	//std::cout << "Ice assignment operator called." << std::endl;
	(void)src;
	return *this;
}

/* 
** call Ice copy constructor with dereferenced current instance pointer
*/
AMateria*    Ice::clone( void ) const {
	return new Ice(*this);
}

void    Ice::use( ICharacter& target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
