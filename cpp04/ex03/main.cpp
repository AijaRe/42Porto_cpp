/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:57:51 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/16 15:57:51 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>


int main() {
	std::cout << "-----TEST ICE CLONE METHOD-----" << std::endl;
    AMateria* m1 = new Ice();
    AMateria* m2 = m1->clone(); // clone m1 to create a separate instance
    std::cout << "Type of m1: " << m1->getType() << std::endl;
    std::cout << "Type of m2: " << m2->getType() << std::endl;
    delete m1;
    delete m2;

    std::cout << "-----TEST CURE ASSIGNMENT OPERATOR-----" << std::endl;
    Cure c1;
    Cure c2;
    std::cout << "Type of c1 before assignment: " << c1.getType() << std::endl; 
    std::cout << "Type of c2 before assignment: " << c2.getType() << std::endl; 
    c2 = c1; // Should not change the type of c2
    std::cout << "Type of c1 after assignment: " << c1.getType() << std::endl; 
    std::cout << "Type of c2 after assignment: " << c2.getType() << std::endl; 
    
    return 0;
}