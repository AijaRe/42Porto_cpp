/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:58:03 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/21 16:30:08 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class	Weapon {
private:
	std::string	_type;
public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);
	void				setType(std::string type);
	const std::string&	getType(void) const;
};

#endif // WEAPON_HPP
