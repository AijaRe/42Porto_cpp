/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:44:06 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/17 17:21:29 by arepsa           ###   ########.fr       */
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
