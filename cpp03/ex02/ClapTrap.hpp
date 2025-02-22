/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:23:01 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/03 21:27:12 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
    public:
        ClapTrap( void );
        ClapTrap( std::string name );
        ClapTrap( const ClapTrap &src );
        virtual ~ClapTrap( void );
        ClapTrap & operator=( const ClapTrap &src );
        //action
        virtual void    attack( const std::string& target );
        void    takeDamage( unsigned int amount );
        void    beRepaired( unsigned int amount );
        //auxiliary
        std::string     getName( void ) const;
        unsigned int    getHitPoints( void ) const;
        unsigned int    getEnergyPoints( void ) const;
        unsigned int    getAttackDamage( void ) const;
        void            setAttackDamage( unsigned int damage );
};

std::ostream	&operator<<( std::ostream &out, const ClapTrap &rhs);

#endif // CLAPTRAP_HPP
