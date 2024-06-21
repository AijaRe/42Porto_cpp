/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:59 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/21 16:38:13 by arepsa           ###   ########.fr       */
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
        AMateria** _droppedItems;
        int _dropCount;
        int _dropCapacity;
        void    resizeDropArray( void );
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
        AMateria* const * getInventory() const;
};

std::ostream	&operator<<( std::ostream &out, const Character &rhs);

#endif // CHARACTER_HPP
