/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:44:06 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/05 18:19:22 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria  {
	private:
		// Private members
	public:
		Cure( void );
		Cure( const Cure &src );
		~Cure( void );
		Cure & operator=( const Cure &src );
		
		AMateria*   clone( void ) const;
		void use( ICharacter& target );
};

#endif // CURE_HPP
