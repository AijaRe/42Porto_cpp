/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:29 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/12 20:07:18 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ): Animal("dog") {
    std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog( const Dog &src ) : Animal(src) {
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog( void ) {
    std::cout << "Dog destructor called." << std::endl;
}

Dog & Dog::operator=( const Dog &src ) {
     std::cout << "Dog assignment operator called." << std::endl;
    if (this != &src) {
       Animal::operator=(src);
    }
    return *this;
}

void    Dog::makeSound( void ) const {
    std::cout << "Woof! Woof!" << std::endl;
}