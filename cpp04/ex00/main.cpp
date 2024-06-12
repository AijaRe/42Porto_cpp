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
	std::cout << "------SUBJECT TEST------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	meta->makeSound();
	
	std::cout << "------WRONG SUBJCET TEST------" << std::endl;
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();
	std::cout << wmeta->getType() << std::endl;
	std::cout << wcat->getType() << std::endl;
	wmeta->makeSound(); 
    wcat->makeSound();  // will print "!!!woooaiM"

	std::cout << "------DELETING INSTANCES------" << std::endl;
	delete meta;
	delete cat;
	delete dog;
	delete wmeta;
    delete wcat;

	std::cout << "------CHECK COPY CONSTRUCTOR------" << std::endl;
	Cat chonk;
	Cat plonk(chonk);
	std::cout << "-----CHECK ASSIGNMENT OPERATOR-----" << std::endl;
	Cat bonk;
	bonk = chonk;
	
	std::cout << "-----ASSIGN CAT TO ANIMAL-----" << std::endl;
	Cat* heapChonk = new Cat();
	Animal *heapChonkPoly = heapChonk;
	Animal stackBonkPoly = bonk;
	std::cout << "Heap: assign to base class: " << heapChonkPoly->getType() << std::endl;
	std::cout << "Stack: assign to base class: " << stackBonkPoly.getType() << std::endl;

	// deleting only one pointer is enough since they both point to the same address
	delete heapChonk;

	return 0;
}