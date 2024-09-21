/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:01:00 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/05 18:01:00 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* 
** allocate an array of class instances (method zombieHorde)
** destroy and array of class instances
** pass the same parameter (name) to all instances
** use index to verify that all instances created/destroyed accordingly
*/
int	main(void){
	int	N = 5;

	std::cout << "TEST: Creating zombie horde wiht 5 zombies..." << std::endl;
	Zombie*	zombies = zombieHorde(N, "Bunny");
	if (!zombies)
		std::cerr << "Error: Failed to create horde zombies." << std::endl;
	else {
		for (int i = 0; i < N; i++){
			zombies[i].announce();
		}
		delete [] zombies;
	}

	N = 0;
	std::cout << "TEST: Creating zombie horde with 0 zombies" << std::endl;
	Zombie*	zombies2 = zombieHorde(N, "Sunny");
	if (!zombies2)
		std::cerr << "Error: Failed to create horde zombies2." << std::endl;
	else {
		for (int i = 0; i < N; i++){
			zombies[i].announce();
		}
		delete [] zombies;
	}

	N = 3;
	std::cout << "TEST: Creating zombie horde wiht 3 zombies and empty name" << std::endl;
	Zombie*	zombies3 = zombieHorde(N, "");
	if (!zombies3)
		std::cerr << "Error: Failed to create horde zombies3." << std::endl;
	else {
		for (int i = 0; i < N; i++){
			zombies[i].announce();
		}
		delete [] zombies;
	}

	return 0;
}
