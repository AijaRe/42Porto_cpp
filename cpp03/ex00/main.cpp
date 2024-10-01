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
	ClapTrap a("Ana");
    ClapTrap b("Bob");
    ClapTrap c = b;

    std::cout << "ASSIGNMENT CONSTRUCTOR AND ASSIGNMENT OPERATOR" << std::endl;
    std::cout << "a named Ana, b named Bob, c = b: " << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    std::cout << "set Ana's attack damage to 5" << std::endl;
    a.setAttackDamage(5);
    std::cout << "Ana attacks Bob" << std::endl;
    a.attack(b.getName());
    std::cout << "Bob takes damage" << std::endl;
    b.takeDamage(a.getAttackDamage());
    std::cout << "AFTER 1st ATTACK: " << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << "Bob gets repaired by 1" << std::endl;
    b.beRepaired(1);
    std::cout << "b AFTER REPAIR:" << std::endl;
    std::cout << b << std::endl;

    std::cout << "set Ana's attack damage to 6" << std::endl;
    a.setAttackDamage(6);
    std::cout << "Ana attacks Bob" << std::endl;
    a.attack(b.getName());
    std::cout << "Bob takes damage" << std::endl;
    b.takeDamage(a.getAttackDamage());
    std::cout << "AFTER 2ND ATTACK (Bob should have 0 hit points):" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << "set Ana's attack damage to 2" << std::endl;
    a.setAttackDamage(2);
    std::cout << "Ana attacks Bob" << std::endl;
    a.attack(b.getName());
    std::cout << "Bob takes damage" << std::endl;
    b.takeDamage(a.getAttackDamage());
    std::cout << "AFTER 3rd ATTACK (attacking a dead man):" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << std::endl;
    std::cout << "TEST SILLY NUMBERS" << std::endl;
    std::cout << "Set megalomaniac attack: " << std::endl;
    a.setAttackDamage(2147483648);
    std::cout << "Set negative attack: " << std::endl;
    a.setAttackDamage(-200);
    std::cout << "Set megalomaniac repair: " << std::endl;
    a.beRepaired(2147483648);
    std::cout << "Set negative repair: " << std::endl;
    a.beRepaired(-2);
    std::cout << std::endl;

    return 0;
}
