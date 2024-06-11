/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:41 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/11 21:46:03 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type("random beastie") {
    std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal( std::string type ) : _type(type) {
    std::cout << "Animal assignment constructor called." << std::endl;
}

Animal::Animal( const Animal &src ) : _type(src._type) {
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal( void ) {
    std::cout << "Animal - " << this->_type << " - destructor called." << std::endl;
}

Animal & Animal::operator=( const Animal &src ) {
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

std::string    Animal::getType( void ) const {
    return this->_type;
}

void    Animal::makeSound( void ) const {
    std::cout << "mhmhummm... (random beastie sound)" << std::endl;
}
