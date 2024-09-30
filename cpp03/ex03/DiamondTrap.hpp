/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:14:04 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/30 22:01:41 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;
    public:
        DiamondTrap( void );
        DiamondTrap( std::string name );
        DiamondTrap( const DiamondTrap &src );
        ~DiamondTrap( void );
        DiamondTrap & operator=( const DiamondTrap &src );

        void        whoAmI( void );
        std::string getDiamondName( void ) const;

        using   ScavTrap::attack;
};

std::ostream	&operator<<(std::ostream & out, const DiamondTrap &rhs );

#endif // DIAMONDTRAP_HPP
