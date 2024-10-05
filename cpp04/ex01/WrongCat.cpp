/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:58:17 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/05 15:40:54 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("wrong cat") {
    std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat( const WrongCat &src ) : WrongAnimal(src) {
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat( void ) {
    std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat & WrongCat::operator=( const WrongCat &src ) {
    std::cout << "WrongCat assignment operator called." << std::endl;
    if (this != &src) {
       WrongAnimal::operator=(src);
    }
    return *this;
}

void    WrongCat::makeSound( void ) const {
    std::cout << "!!!woooaiM" << std::endl;
}
