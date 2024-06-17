/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:59 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/17 19:07:50 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

#define SLOTS 4

class AMateria;

class Character : public ICharacter {
    private:
        std::string _name;
        AMateria* _inventory[SLOTS];
    public:
        Character( void );
        Character( std::string name );
        Character( const Character &src );
        virtual ~Character( void );
        Character & operator=( const Character &src );

        std::string const & getName( void ) const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif // CHARACTER_HPP
