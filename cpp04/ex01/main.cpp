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
#include <cstdio> // for sprintf

std::string intToString(int number) {
    char buffer[20]; // Buffer to hold the string representation
    sprintf(buffer, "%d", number); // Format the integer into the buffer
    return std::string(buffer); // Return buffer converted to std::string
}

int	main( void ) {
	{
		std::cout << "-------------SUBJECT TEST-------------" << std::endl;
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		delete dog;
		delete cat;
	}
	{
		std::cout << "\n-------------BRAIN SCAN-------------" << std::endl;
		Cat chonk;
		std::cout << "\n----------Print empty brain----------" << std::endl;
		chonk.getBrain()->printIdeas();
		std::cout << "\n-----------Setting 2 ideas-----------" << std::endl;
		chonk.getBrain()->setIdea("I want to set the world on fire.");
		chonk.getBrain()->setIdea("These feet look tasty!");
		std::cout << "\n-------------Print ideas-------------" << std::endl;
		chonk.getBrain()->printIdeas();

		std::cout << "\n-----------DEEP COPY TEST-----------" << std::endl;
		Cat copycat(chonk);
		std::cout << "\n------Copycat gets one more idea------" << std::endl;
		copycat.getBrain()->setIdea("If I speed up, I will get into another dimension.");
		std::cout << std::endl;
		std::cout << "---------Original cat's ideas---------" << std::endl;
		chonk.getBrain()->printIdeas();
		std::cout << std::endl;
		std::cout << "-----------Copycat's ideas-----------" << std::endl;
		copycat.getBrain()->printIdeas();
		std::cout << copycat.getBrain()->getBusyCount() << std::endl;
		std::cout << copycat.getBrain()->getIdeaCount() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "\n--------MIXED ANIMAL ARRAY TEST--------" << std::endl;
		const int pack_size = 4;
		Animal* animal[pack_size] = {};

		std::cout << "\nCreating mixed pack...." << std::endl;
		for (int i = 0; i < pack_size; i++) {
			if (i < pack_size / 2) {
				animal[i] = new Cat;
			} else {
				animal[i] = new Dog;
			}
		}
		
		std::cout << "\nDeleting mixed pack...." << std::endl;
		for (int i = 0; i < pack_size; i++)
			delete animal[i];
	}
	/*{
		std::cout << "\n----------TEST IDEA ARRAY----------" << std::endl;
		Brain brain;
			for (int i = 0; i < 110; i++) {
			brain.setIdea("Idea #" + intToString(i + 1));
		}
		std::cout << "Printing ideas after adding more than 100:" << std::endl;
		brain.printIdeas();
	}*/
	return 0;
}
