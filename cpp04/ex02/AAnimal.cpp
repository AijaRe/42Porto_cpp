/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:41 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/15 21:26:18 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type("random beastie") {
    std::cout << "AAnimal - " << this->_type << " - default constructor called." << std::endl;
}

AAnimal::AAnimal( std::string type ) : _type(type) {
    std::cout << "AAnimal  - " << this->_type << " - assignment constructor called." << std::endl;
}

AAnimal::AAnimal( const AAnimal &src ) : _type(src._type) {
    std::cout << "AAnimal  - " << this->_type << " - copy constructor called." << std::endl;
}

AAnimal::~AAnimal( void ) {
    std::cout << "AAnimal - " << this->_type << " - destructor called." << std::endl;
}

AAnimal & AAnimal::operator=( const AAnimal &src ) {
    std::cout << "AAnimal  - " << this->_type << " - assignment operator called." << std::endl;
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

std::string    AAnimal::getType( void ) const {
    return this->_type;
}

void    AAnimal::makeSound( void ) const {
    std::cout << "nomnommm... (random beastie sound)" << std::endl;
}
