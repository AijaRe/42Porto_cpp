/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:26:38 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/30 16:26:38 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main ( void ) {
    std::cout << "---ASSIGNMENT CONSTRUCTOR CHECK---" << std::endl;
    ScavTrap z("Zaz");
    std::cout << z << std::endl;

    std::cout << "-------COPY CONSTRUCTOR CHECK-------" << std::endl;
    ScavTrap x(z);
    std::cout << x << std::endl;

    std::cout << "------DEFAULT CONSTRUCTOR CHECK------" << std::endl;
    ScavTrap y;
    std::cout << y << std::endl;
    std::cout << "---ASSIGNMENT OPERATOR OVERLOAD CHECK---" << std::endl;
    y = z;
    std::cout << y << std::endl;

    std::cout << "---------BASIC METHOD CHECK---------" << std::endl;
    ScavTrap w("Wow");
    w.attack(z.getName());
    z.takeDamage(w.getAttackDamage());
    std::cout << "AFTER ATTACK" << std::endl;
    std::cout << w << std::endl;
    std::cout << z << std::endl;

    z.beRepaired(5);
    std::cout << "z AFTER REPAIR" << std::endl;
    std::cout << z << std::endl;

    z.guardGate();

    std::cout << std::endl;
    std::cout << "-----HEAP ALLOC AND DELETE TEST-----" << std::endl;
    ClapTrap* trapp = new ScavTrap("Heap");
    std::cout << *trapp << std::endl;
    delete trapp;

    return 0;
}