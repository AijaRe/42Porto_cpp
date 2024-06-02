/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:14:09 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/02 16:14:10 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) {
    std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) {
    std::cout << "DiamondTrap assignment constructor called." << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &src ) {
    std::cout << "DiamondTrap copy constructor called." << std::endl;
    *this = src;
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout << "DiamondTrap destructor called." << std::endl;
}

DiamondTrap & DiamondTrap::operator=( const DiamondTrap &src ) {
    if (this != &src) {
        // Implement assignment
    }
    return *this;
}

void    DiamondTrap::whoAmI( void ) {
    std::cout << "Oh, the existential crisis..." << std::endl;
}