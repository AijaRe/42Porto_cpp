/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:50 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/16 16:43:49 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

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

AMateria & AMateria::operator=( const AMateria &src ) {
    std::cout << "AMateria assignment operator called." << std::endl;
    if(this != &src) {
        this->_type = src._type;
    }
    return *this;
}

std::string const & AMateria::getType( void ) const {
    return this->_type;
}
