/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:58:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/07 18:58:56 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/* 
** HumanA takes the Weapon in its constructor, HumanB doesn’t.
** HumanA will always be armed (can use reference to a weapon). 
** HumanB may not always have a Weapon (needs pointer to a weapon).
** {} block scope - visibility and lifetime of variables declared within.
*/
int	main(void){
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		HumanB ana("Ana");
		ana.attack();
	}
	return 0;
}
