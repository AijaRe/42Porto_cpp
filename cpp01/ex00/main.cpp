/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:40:30 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/21 14:41:35 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* 
** stack memory - faster, simple, gets freed automatically 
** after exiting the scope, limited amount of memory.
** heap memory (new - delete) - when you need the lifetime 
** be longer that the scope of your function or when a lot of data 
*/
int	main(void){
	Zombie	*heapZombie = newZombie("HeapZombie");
	
	heapZombie->announce();

	randomChump("StackZombie");
	
	delete heapZombie;
	
	return 0;
}
