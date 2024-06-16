/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:59 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/16 16:00:49 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

class Character {
    private:
        // Private members
    public:
        Character( void );
        Character( std::string name );
        Character( const Character &src );
        ~Character( void );
        Character & operator=( const Character &src );
};

#endif // CHARACTER_HPP
