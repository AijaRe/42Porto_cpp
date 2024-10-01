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
#include "FragTrap.hpp"

int	main ( void ) {
    std::cout << "-----FRAGTRAP DEFAULT CONSTRUCTOR-----" << std::endl;
    FragTrap def;
    std::cout << def << std::endl;

    std::cout << "-----FRAGTRAP ASSIGNMENT CONSTRUCTOR-----" << std::endl;
    FragTrap frag("Fif");
    std::cout << frag << std::endl;

    std::cout << "-----FRAGTRAP COPY CONSTRUCTOR-----" << std::endl;
    FragTrap copy(frag);
    std::cout << copy << std::endl;

    std::cout << "-----FRAGTRAP ASSIGNMENT OPERATOR-----" << std::endl;
    def = frag;
    std::cout << def << std::endl;

    std::cout << "-----FRAGTRAP SPECIAL CAPACITY-----" << std::endl;
    frag.highFivesGuys();

    std::cout << "-----CREATING A SCAVTRAP-----" << std::endl;
    ScavTrap scav("Sas");
    std::cout << scav << std::endl;

    scav.attack(frag.getName());
    frag.takeDamage(scav.getAttackDamage());
    std::cout << "----------AFTER 1ST ATTACK----------" << std::endl;
    std::cout << frag << std::endl;
    std::cout << scav << std::endl;

    frag.beRepaired(10);
    frag.attack(scav.getName());
    scav.takeDamage(frag.getAttackDamage());
    std::cout << "----------AFTER 2ND ATTACK----------" << std::endl;
    std::cout << frag << std::endl;
    std::cout << scav << std::endl;


    return 0;
}