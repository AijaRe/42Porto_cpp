/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:50 by arepsa            #+#    #+#             */
/*   Updated: 2024/07/31 20:16:14 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria( void ) : _type("typeless") {
    std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type) {
    std::cout << "AMateria assignment constructor called." << std::endl;
}

AMateria::AMateria( const AMateria &src ) : _type(src._type) {
    std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria::~AMateria( void ) {
    std::cout << "AMateria destructor called." << std::endl;
}

/* 
** While assigning a Materia to another,
** copying the type doesn’t make sense. 
** and since type is the only private attribute, do nothing.
*/
AMateria & AMateria::operator=( const AMateria &src ) {
    std::cout << "AMateria assignment operator called." << std::endl;
    (void)src;
    return *this;
}

std::string const & AMateria::getType( void ) const {
    return this->_type;
}

void    AMateria::use( ICharacter& target ) {
    std::cout << "* " << this->_type << " used on " << target.getName() << " *" << std::endl;
}
