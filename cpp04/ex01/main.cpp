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
#include "Brain.hpp"

int	main( void ) {
	std::cout << "----------SUBJECT TEST----------" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	delete dog;
	delete cat;

	std::cout << "\n----------BRAIN SCAN----------" << std::endl;
	Cat chonk;
	chonk.getBrain()->setIdea("I want to set the world on fire.");
	chonk.getBrain()->setIdea("These feet look tasty!");
	chonk.getBrain()->printIdeas();

	std::cout << "\n--------DEEP COPY TEST--------" << std::endl;
	Cat copycat;
	copycat = chonk;
	copycat.getBrain()->setIdea("If I speed up, I will get into another dimension.");
	std::cout << "--------Original cat's ideas--------" << std::endl;
	chonk.getBrain()->printIdeas();
	std::cout << "--------Copycat's ideas--------" << std::endl;
	copycat.getBrain()->printIdeas();

	std::cout << "\n--------MIXED ANIMAL ARRAY TEST--------" << std::endl;
	const int pack_size = 4;
 	Animal* animal[pack_size] = {};

	std::cout << "Creating mixed pack...." << std::endl;
	for (int i = 0; i < pack_size; i++) {
		if (i < pack_size / 2) {
			animal[i] = new Cat;
		} else {
			animal[i] = new Dog;
		}
	}
	std::cout << "Deleting mixed pack...." << std::endl;
	for (int i = 0; i < pack_size; i++)
		delete animal[i];
	
	return 0;
}