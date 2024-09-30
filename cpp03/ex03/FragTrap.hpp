/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:13:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/30 22:58:53 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

/* 
** "virtual" keyword solves the "diamond problem" for multimple inheritance
** third level class that inherits from two classes with the same parent
** ends up inheriting only one instance of first level class 
** unless explicitly stated otherwise 
** "diamond problem" - inherit from base class multiple times
*/
class FragTrap : virtual public ClapTrap {
    private:
        // Private members
    public:
        FragTrap( void );
        FragTrap( std::string name );
        FragTrap( const FragTrap &src );
        ~FragTrap( void );
        FragTrap & operator=( const FragTrap &src );

        void    highFivesGuys( void );
};

std::ostream	&operator<<( std::ostream &out, const FragTrap &rhs );

#endif // FRAGTRAP_HPP
