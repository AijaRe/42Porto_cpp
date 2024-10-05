/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:59 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/05 18:19:11 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

#define INVENTORY_SLOTS 4

class AMateria;

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria* _inventory[INVENTORY_SLOTS];
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
		void equip( AMateria* m );
		void unequip( int idx );
		void use( int idx, ICharacter& target );
		AMateria* const * getInventory( void ) const;
};

std::ostream	&operator<<( std::ostream &out, const Character &rhs);

#endif // CHARACTER_HPP
