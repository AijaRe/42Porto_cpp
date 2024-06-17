/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:44:11 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/17 17:18:38 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria {
    private:
        // Private members
    public:
        Ice( void );
        Ice( const Ice &src );
        ~Ice( void );
        Ice & operator=( const Ice &src );

        AMateria*   clone( void ) const;
        void use( ICharacter& target );
};

#endif // ICE_HPP
