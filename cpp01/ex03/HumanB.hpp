/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:37:12 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/21 16:37:17 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

/* 
** weapon has to be pointer,
** because it can be null
*/
class HumanB {
private:
	std::string _name;
	Weapon* _weapon;
public:
	HumanB(std::string name);
	~HumanB(void);
	void    setWeapon(Weapon& weapon);
	void    attack(void);
	
};

#endif // HUMANB_HPP
