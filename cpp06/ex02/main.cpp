/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:22:52 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/27 19:22:52 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/*
** Dynamic cast happens at runtime, not compilation
** Only works with polymorphism -> at least one virtual function
*/

Base*	generate(void){
	std::srand(std::time(0));
	int choice = std::rand() % 3;

	switch(choice) {
		case 0:
			std::cout << YELLOW << "Generating A..." << RESET << std::endl;
			return new A();
		case 1:
			std::cout << YELLOW << "Generating B..." << RESET << std::endl;
			return new B();
		case 2:
			std::cout << YELLOW << "Generating C..." << RESET << std::endl;
			return new C();
	}
	return NULL;
}

/*
** if using dynamic_cast with pointers,
** if the cast is not valid, the result is a nullptr.
*/
void	identify(Base* base){
	if (dynamic_cast<A*>(base))
		std::cout << GREEN << ARROW << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << GREEN << ARROW << "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(base))
		std::cout << GREEN << ARROW << "C" << RESET << std::endl;
	else
		std::cout << RED << "Error: unknown type" << RESET << std::endl;
}

/*
** when using dynamic_cast with references,
** if the cast is not valid, an exception (std::bad_cast) is thrown.
*/

int	main(void){

	Base* randomBase = generate();
	std::cout << YELLOW << "Identifying pointer..." << RESET << std::endl;
	identify(randomBase);
	std::cout << YELLOW << "Identifying reference..." << RESET << std::endl;
	
	return 0;
}