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
#include "MateriaSource.hpp"
#include <iostream>


int main() {
	std::cout << "-----TEST ICE CLONE METHOD-----" << std::endl;
    AMateria* i1 = new Ice();
    AMateria* i2 = i1->clone(); // clone m1 to create a separate instance
    std::cout << "Type of m1: " << i1->getType() << std::endl;
    std::cout << "Type of m2: " << i2->getType() << std::endl;

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
    AMateria* i3 = new Ice();
    Character bob("Bob");
    std::cout << bob << std::endl;
    bob.equip(i1);
    bob.equip(i2);
    std::cout << bob << std::endl;
    bob.equip(c3);
    bob.equip(c4);
    std::cout << "\n-----TEST EQUIPPING FULL SLOTS-----" << std::endl;
    bob.equip(i3);
    std::cout << bob << std::endl; 
    bob.unequip(2);
    std::cout << bob << std::endl;

    std::cout << "\n-----TEST UNEQUIP EMPTY SLOT-----" << std::endl;
    Character ana("Ana");
    ana.unequip(2);
    std::cout << ana << std::endl;

    std::cout << "\n-----TEST USE METHOD WITH EMPTY SLOT-----" << std::endl;
    bob.use(2, ana);
    std::cout << "\n-----TEST USE METHOD WITH MATERIA-----" << std::endl;
    bob.use(1, ana);

    std::cout << "\n-----TEST CHARACTER DEEP COPY-----" << std::endl;
    std::cout << bob << std::endl;
    ana = bob;
    std::cout << ana << std::endl;

    std::cout << "\n--------TEST MATERIA SOURCE--------" << std::endl;
    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    AMateria* tmp;  
    tmp = src.createMateria("ice");
    tmp->use(bob);
    tmp = src.createMateria("cure");
    tmp->use(bob);

    std::cout << "\n-----END OF TESTS, LET'S DESTROY...-----" << std::endl;
    return 0;
}