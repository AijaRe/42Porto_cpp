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
    std::cout << "-----FRAGTRAP CONSTRUCTOR AND SPECIAL CAPACITY-----" << std::endl;
    FragTrap f("Fif");
    std::cout << f << std::endl;
    f.highFivesGuys();

    ScavTrap s("Sas");

    s.attack(f.getName());
    f.takeDamage(s.getAttackDamage());
    std::cout << "----------AFTER 1ST ATTACK----------" << std::endl;
    std::cout << f << std::endl;
    std::cout << s << std::endl;

    f.beRepaired(10);
    f.attack(s.getName());
    s.takeDamage(f.getAttackDamage());
    std::cout << "----------AFTER 2ND ATTACK----------" << std::endl;
    std::cout << f << std::endl;
    std::cout << s << std::endl;


    return 0;
}