/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:29 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/05 15:40:34 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ): Animal("Dog") {
    std::cout << "Dog default constructor called." << std::endl;
     this->_brain = new Brain;
}

Dog::Dog( const Dog &src ) : Animal(src) {
    std::cout << "Dog copy constructor called." << std::endl;
    this->_brain = new Brain(*src._brain);
}

Dog::~Dog( void ) {
    std::cout << "Dog destructor called." << std::endl;
    delete this->_brain;
}

Dog & Dog::operator=( const Dog &src ) {
     std::cout << "Dog assignment operator called." << std::endl;
    if (this != &src) {
        Animal::operator=(src);
        if (this->_brain != NULL)
		    delete this->_brain;
		this->_brain = new Brain(*src._brain);
    }
    return *this;
}

void    Dog::makeSound( void ) const {
    std::cout << "Woof! Woof!" << std::endl;
}

Brain*  Dog::getBrain( void ) const {
    return this->_brain;
}
