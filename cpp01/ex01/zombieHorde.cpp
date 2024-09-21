/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:06:33 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/05 18:06:33 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ){
	if (N <= 0 || name.empty()){
		std::cerr << "Error: zombieHorde: Missing information for a zombie..." << std::endl;
		return NULL;
	}

	Zombie*	horde = new Zombie[N];

	if (N <= 0)
		return NULL;
	for (int i = 0; i < N; i++){
		horde[i].setName(name);
		horde[i].setIndex(i + 1);
	}
	return horde;
}
