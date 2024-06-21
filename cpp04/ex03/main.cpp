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
#include "Character.hpp"
#include <iostream>


int main() {
	std::cout << "-----TEST ICE CLONE METHOD-----" << std::endl;
    AMateria* m1 = new Ice();
    AMateria* m2 = m1->clone(); // clone m1 to create a separate instance
    std::cout << "Type of m1: " << m1->getType() << std::endl;
    std::cout << "Type of m2: " << m2->getType() << std::endl;

    std::cout << "\n-----TEST CURE ASSIGNMENT OPERATOR-----" << std::endl;
    Cure c1;
    Cure c2;
    std::cout << "Type of c1 before assignment: " << c1.getType() << std::endl; 
    std::cout << "Type of c2 before assignment: " << c2.getType() << std::endl; 
    c2 = c1; // Should not change the type of c2
    std::cout << "Type of c1 after assignment: " << c1.getType() << std::endl; 
    std::cout << "Type of c2 after assignment: " << c2.getType() << std::endl; 
    
    std::cout << "\n-----TEST CHARACTER METHODS-----" << std::endl;
    AMateria* c3 = new Cure();
    AMateria* c4 = new Cure();
    AMateria* m3 = new Ice();
    Character bob("Bob");
    std::cout << bob << std::endl;
    bob.equip(m1);
    bob.equip(m2);
    std::cout << bob << std::endl;
    bob.equip(c3);
    bob.equip(c4);
    //bob.equip(m3);
    std::cout << bob << std::endl;
    bob.unequip(2);
    std::cout << bob << std::endl;

    delete m3;
    return 0;
}