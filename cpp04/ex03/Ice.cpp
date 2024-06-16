/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:44:09 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/16 17:01:41 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {
    std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice( const Ice &src ) : AMateria(src) {
    std::cout << "Ice copy constructor called." << std::endl;
}

Ice::~Ice( void ) {
    std::cout << "Ice destructor called." << std::endl;
}

Ice & Ice::operator=( const Ice &src ) {
    std::cout << "Ice assignment operator called." << std::endl;
    if (this != &src) {
       this->_type = src._type;
    }
    return *this;
}

/* 
** call Ice copy constructor
*/
AMateria*    Ice::clone( void ) const {
    return new Ice(*this);
}