/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:13:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/02 16:13:57 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
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

std::ostream	&operator<<( std::ostream &out, const FragTrap &rhs);

#endif // FRAGTRAP_HPP
