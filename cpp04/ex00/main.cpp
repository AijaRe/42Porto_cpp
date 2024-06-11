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
	
	std::cout << "------DELETING INSTANCES------" << std::endl;
	delete meta;
	delete cat;
	delete dog;

	std::cout << "------CHECK COPY CONSTRUCTOR------" << std::endl;
	Cat chonk;
	Cat plonk(chonk);
	std::cout << "-----CHECK ASSIGNMENT OPERATOR-----" << std::endl;
	Cat bonk=chonk;
	

	return 0;
}