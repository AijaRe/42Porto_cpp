/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:32:34 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/02 15:32:35 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
    // Private members
public:
    ScavTrap( void );
    ScavTrap( std::string name );
    ScavTrap( const ScavTrap &src );
    ~ScavTrap( void );
    ScavTrap & operator=( const ScavTrap &src );

    void    guardGate( void );
};

std::ostream	&operator<<( std::ostream &out, const ScavTrap &rhs);

#endif // SCAVTRAP_HPP
