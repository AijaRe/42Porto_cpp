/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:40:55 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/04 17:00:58 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std:: string name){
    Zombie *newZombie = NULL;
    
    newZombie = new Zombie();
    if (!newZombie)
        std::cout << "Zombie memory allocation failed." << std::endl;
    newZombie->setName(name);
    return newZombie;
}
