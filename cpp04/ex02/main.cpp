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
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	//not possible to instantiate AAnimal
	//AAnimal beastie;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
	
	return 0;
}