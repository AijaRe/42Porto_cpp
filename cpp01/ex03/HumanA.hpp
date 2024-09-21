/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:34:25 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/21 16:36:25 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

/* 
** weapon is a reference, because it will always be present
** since weapon comes always with constructor
** never NULL -> use reference
*/
class	HumanA {
private:
	std::string	_name;
	Weapon&		_weapon;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);
	void	attack(void);
};

#endif // HUMANA_HPP
