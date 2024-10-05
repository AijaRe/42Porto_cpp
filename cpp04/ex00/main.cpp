/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:47:29 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/11 20:47:29 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main( void ) {
	{
		std::cout << "---------SUBJECT TEST---------" << std::endl;
		const Animal* meta = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << ">> Animal type: " << meta->getType() << std::endl;
		std::cout << ">> Cat type: " << cat->getType() << std::endl;
		std::cout << ">> Dog type: " << dog->getType() << std::endl;
		std::cout << ">> Animal sound: "; 
		meta->makeSound();
		std::cout << ">> Cat sound: "; 
		cat->makeSound();
		std::cout << ">> Dog sound: "; 
		dog->makeSound();
		std::cout << std::endl;
		std::cout << "-------DELETING INSTANCES-------" << std::endl;
		delete meta;
		delete cat;
		delete dog;
		std::cout << std::endl;
	}
	{
		std::cout << "-------WRONG SUBJCET TEST-------" << std::endl;
		const WrongAnimal* wmeta = new WrongAnimal();
		const WrongAnimal* wcat = new WrongCat();
		std::cout << ">> Wrong Animal type: " << wmeta->getType() << std::endl;
		std::cout << ">> Wrong Cat type: " << wcat->getType() << std::endl;
		std::cout << ">> Wrong Animal sound: "; 
		wmeta->makeSound();
		std::cout << ">> Wrong Cat sound: "; 
		wcat->makeSound();
		std::cout << std::endl;

		std::cout << "-------DELETING INSTANCES-------" << std::endl;
		delete wmeta;
		delete wcat;
		std::cout << std::endl;
	}
	{
		std::cout << "------CHECK COPY CONSTRUCTOR------" << std::endl;
		Cat chonk;
		Cat plonk(chonk);
		std::cout << ">> Cat chonk type: " << chonk.getType() << std::endl;
		std::cout << ">> Copied plonk type: " << plonk.getType() << std::endl;
		std::cout << std::endl;

		std::cout << "-----CHECK ASSIGNMENT OPERATOR-----" << std::endl;
		Cat bonk;
		bonk = chonk;
		std::cout << ">> Assigned cat bonk type: " << bonk.getType() << std::endl;
		std::cout << std::endl;
		
		std::cout << "------ASSIGN CAT TO ANIMAL------" << std::endl;
		Cat* heapChonk = new Cat();
		Animal *heapChonkPoly = heapChonk;
		Animal stackBonkPoly = bonk;
		std::cout << ">> Heap: assign to base class: " << heapChonkPoly->getType() << std::endl;
		std::cout << ">> Stack: assign to base class: " << stackBonkPoly.getType() << std::endl;
		std::cout << std::endl;

		// deleting only one pointer is enough since they both point to the same address
		std::cout << "----------DELETE INSTANCE----------" << std::endl;
		delete heapChonk;
		std::cout << std::endl;
		std::cout << "-----ROLL STACK DESTRUCTORS...-----" << std::endl;
	}
	return 0;
}
