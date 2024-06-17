/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:59 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/17 18:01:36 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter {
    private:
        std::string _name;
    public:
        Character( void );
        Character( std::string name );
        Character( const Character &src );
        ~Character( void );
        Character & operator=( const Character &src );

        std::string const & getName( void ) const;
};

#endif // CHARACTER_HPP
