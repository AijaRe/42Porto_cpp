/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:35 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/05 12:37:22 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat( const Cat &src ) : Animal(src) {
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat( void ) {
    std::cout << "Cat destructor called." << std::endl;
}

Cat & Cat::operator=( const Cat &src ) {
    std::cout << "Cat assignment operator called." << std::endl;
    if (this != &src) {
        Animal::operator=(src);
    }
    return *this;
}

void    Cat::makeSound( void ) const {
    std::cout << "Miaooow!!!" << std::endl;
}
