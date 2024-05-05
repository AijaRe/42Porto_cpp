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
	Zombie* zombies = zombieHorde(5, "Bunny");

	for (int i = 0; i < 5; i++){
		zombies[i].announce();
	}
	delete [] zombies;
	return 0;
}
