/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:35 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/11 21:54:50 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("cat") {
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat( const Cat &src ) : Animal(src) {
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat( void ) {
    std::cout << "Cat destructor called." << std::endl;
}

Cat & Cat::operator=( const Cat &src ) {
    if (this != &src) {
        Animal::operator=(src);
    }
    return *this;
}

void    Cat::makeSound( void ) const {
    std::cout << "Miaooow!!!" << std::endl;
}
