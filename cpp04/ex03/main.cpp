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
	std::cout << "-------TEST ICE CLONE METHOD-------" << std::endl;
    AMateria* i1 = new Ice();
    AMateria* i2 = i1->clone(); // clone materia to create a separate instance
    std::cout << "Type of i1: " << i1->getType() << std::endl;
    std::cout << "Type of i2: " << i2->getType() << std::endl;
 
    std::cout << "\n------TEST CHARACTER METHODS------" << std::endl;
    AMateria* c1 = new Cure();
    AMateria* c2 = new Cure();
    AMateria* i3 = new Ice();
    Character bob("Bob");
    std::cout << "Initial state of Bob: \n" << std::endl;
    std::cout << bob << std::endl;
    bob.equip(i1);
    bob.equip(i2);
    std::cout << "Bob after equipping two Ice Materia: \n" << std::endl;
    std::cout << bob << std::endl;
    bob.equip(c1);
    bob.equip(c2);
    std::cout << "Bob after equipping two Cure Materia: \n" << std::endl;
    std::cout << bob << std::endl;
    std::cout << "\n------TEST EQUIPPING FULL SLOTS------" << std::endl;
    bob.equip(i3);
    std::cout << bob << std::endl; 
    std::cout << "\n-------TEST UNEQUIPPING A SLOT-------" << std::endl;
    bob.unequip(2);
    std::cout << "Bob after unequipping slot 2: \n" << std::endl;
    std::cout << bob << std::endl;

    std::cout << "\n-------TEST UNEQUIP EMPTY SLOT-------" << std::endl;
    Character ana("Ana");
    std::cout << "Initial state of Ana: \n" << std::endl;
    std::cout << ana << std::endl;
    ana.unequip(2);
    std::cout << "Ana after trying to unequip from empty slot 2: \n" << std::endl;
    std::cout << ana << std::endl;

    std::cout << "\n---TEST USE METHOD WITH EMPTY SLOT---" << std::endl;
    bob.use(2, ana);
    std::cout << "\n----TEST USE METHOD WITH MATERIA ----" << std::endl;
    bob.use(1, ana);
    std::cout << "\n--TEST USE METHOD WITH NONEXISTING SLOT--" << std::endl;
    bob.use(8, ana);

    std::cout << "\n------TEST CHARACTER DEEP COPY ------" << std::endl;
    std::cout << bob << std::endl;
    Character copy(bob);
    ana = bob;
    std::cout << "\nCharacter after copying from Bob: \n" << std::endl;
    std::cout << copy << std::endl;
    std::cout << "\nAna after assigning from Bob: \n" << std::endl;
    std::cout << ana << std::endl;
    std::cout << "\nCopy unequips slot 0: \n" << std::endl;
    copy.unequip(0);
    std::cout << "\nEx-Ana unequips slot 1: \n" << std::endl;
    ana.unequip(1);
    std::cout << "\nPrinting Bob - Copy - Ana: \n" << std::endl;
    std::cout << bob << std::endl;
    std::cout << copy << std::endl;
    std::cout << ana << std::endl;

    std::cout << "\n---------TEST MATERIA SOURCE---------" << std::endl;
    MateriaSource src;
    Character zaz("Zaz");
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());
    AMateria* tmp;  
    tmp = src.createMateria("ice");
    zaz.equip(tmp);
    tmp = src.createMateria("cure");
    zaz.equip(tmp);
    std::cout << "Zaz after equipping learned Materia: \n" << std::endl;
    std::cout << zaz << std::endl;
    zaz.use(0, bob);
    zaz.use(1, bob);

    std::cout << "\n-----END OF TESTS, LET'S DESTROY...-----" << std::endl;
    return 0;
}
