/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:40:55 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/05 17:48:12 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std:: string name){
    Zombie *newZombie = NULL;
    
    newZombie = new Zombie(name);
    if (!newZombie)
        std::cout << "Zombie memory allocation failed." << std::endl;
    return newZombie;
}
