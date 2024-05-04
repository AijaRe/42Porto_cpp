/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:40:30 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/04 15:36:16 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int     main(void){
    Zombie *heapZombie = newZombie("Test");
    
    heapZombie->announce();

    randomChump("Zeka");
    delete heapZombie;
    return 0;
}
