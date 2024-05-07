/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:58:03 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/07 19:58:17 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
private:
    std::string _type;
public:
    Weapon(void);
    Weapon(std::string type);
    ~Weapon(void);
    void                setType(std::string type);
    const std::string&  getType(void) const;
};

#endif // WEAPON_HPP
