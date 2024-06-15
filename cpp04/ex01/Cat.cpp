/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:35 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/14 19:10:36 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("cat") {
    std::cout << "Cat default constructor called." << std::endl;
    this->_brain = new Brain;
}

Cat::Cat( const Cat &src ) : Animal(src) {
    std::cout << "Cat copy constructor called." << std::endl;
    this->_brain = new Brain(*src._brain);
}

Cat::~Cat( void ) {
    std::cout << "Cat destructor called." << std::endl;
    delete this->_brain;
}

Cat & Cat::operator=( const Cat &src ) {
    std::cout << "Cat assignment operator called." << std::endl;
    if (this != &src) {
        Animal::operator=(src);
        if (this->_brain != NULL)
		    delete this->_brain;
		this->_brain = new Brain(*src._brain);
    }
    return *this;
}

void    Cat::makeSound( void ) const {
    std::cout << "Miaooow!!!" << std::endl;
}

Brain*  Cat::getBrain( void ) const {
    return this->_brain;
}
