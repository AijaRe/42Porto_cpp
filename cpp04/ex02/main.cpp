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

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main( void ) {
	std::cout << "\n-----CREATING ANIMALS: CAT & DOG-----" << std::endl;
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << "\n----UNCOMMENT TO TEST THE ABSTRACT ANIMAL----" << std::endl;
	std::cout << "-----not possible to instantiate AAnimal-----" << std::endl;
	//AAnimal beastie;
	//AAnimal* beastie = new AAnimal();

	std::cout << "\n-------------SOUND CHECK-------------" << std::endl;
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n---------DELETING INSTANCES----------" << std::endl;
	delete dog;
	delete cat;
	
	return 0;
}
