/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:58:08 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/12 21:25:54 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("random wrong beastie"){
    std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type){
    std::cout << "WrongAnimal assignment constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &src ) : _type(src._type) {
    std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
    std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal & WrongAnimal::operator=( const WrongAnimal &src ) {
    std::cout << "WrongAnimal assignment operator called." << std::endl;
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

std::string WrongAnimal::getType( void ) const {
    return this->_type;
}

void    WrongAnimal::makeSound( void ) const {
    std::cout << "...mmmonmon (random wrong beastie sound)" << std::endl;
}