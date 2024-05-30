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

int	main ( void ) {
	ClapTrap a("Asa");
    ClapTrap b("Bob");
    ClapTrap c = b;

    std::cout << "AFTER INITIALIZING" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    a.attack("Bob");
    b.takeDamage(5);
    std::cout << "AFTER 1st ATTACK" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    b.beRepaired(1);
    std::cout << "b AFTER REPAIR" << std::endl;
    std::cout << b << std::endl;

    a.attack("Bob");
    b.takeDamage(6);
    std::cout << "AFTER 2ND ATTACK (Bob should have 0 hit points)" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    a.attack("Bob");
    b.takeDamage(2);
    std::cout << "AFTER 3rd ATTACK (attacking a dead man)" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}