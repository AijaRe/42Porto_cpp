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

#include "DiamondTrap.hpp"

int	main ( void ) {
	std::cout << "-----DIAMONDTRAP DEFAULT CONSTRUCTOR-----" << std::endl;
	DiamondTrap d;
	std::cout << d << std::endl;
	std::cout << "-----DIAMONDTRAP ASSIGNMENT CONSTRUCTOR-----" << std::endl;
	DiamondTrap s("Shine");
	std::cout << s << std::endl;
	std::cout << "-----DIAMONDTRAP COPY CONSTRUCTOR-----" << std::endl;
	DiamondTrap c(s);
	std::cout << c << std::endl;
	std::cout << "-----------VERIFY DEEP COPY-----------" << std::endl;
	std::cout << "Change s attack damage to 44:" << std::endl;
	s.setAttackDamage(44);
	 std::cout << "s attack damage: " << s.getAttackDamage() << std::endl;
	std::cout << "c attack damage: " << c.getAttackDamage() << std::endl;
	std::cout << "-----DIAMONDTRAP ASSIGNMENT CONSTRUCTOR-----" << std::endl;
	DiamondTrap assigned_s("Shine2");
	assigned_s = s;
	std::cout << "-----------VERIFY DEEP COPY-----------" << std::endl;
	std::cout << "This is copied assigned_s:" << std::endl;
	std::cout << assigned_s << std::endl;
	std::cout << "Change s attack damage to 85:" << std::endl;
	s.setAttackDamage(85);
	std::cout << "s attack damage: " << s.getAttackDamage() << std::endl;
	std::cout << "assigned_s attack damage: " << assigned_s.getAttackDamage() << std::endl;
	 std::cout << std::endl;
	std::cout << "----------DIAMONDTRAP ATTACK----------" << std::endl;
	s.attack("DiamondTarget");
	std::cout << std::endl;
	std::cout << "-------DIAMONDTRAP FRAG SPECIAL-------" << std::endl;
	s.highFivesGuys();
	std::cout << std::endl;
	std::cout << "-------DIAMONDTRAP SCAV SPECIAL-------" << std::endl;
	s.guardGate();
	std::cout << std::endl;
	std::cout << "-----DIAMONDTRAP SPECIAL CAPACITY-----" << std::endl;
	s.whoAmI();
	std::cout << std::endl;
 
	std::cout << "-----LET'S ROLL THE DESTRUCTORS-----" << std::endl;
	std::cout << "(3 named Diamonds and one default Diamond)" << std::endl;

	return 0;
}
