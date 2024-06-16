/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:44:06 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/16 17:02:10 by arepsa           ###   ########.fr       */
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
};

#endif // CURE_HPP
