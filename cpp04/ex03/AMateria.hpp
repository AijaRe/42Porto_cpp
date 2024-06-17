/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:43:53 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/17 17:51:49 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

/* 
** Forward declaration of ICharacter
** there is a class named ICharacter that will be defined later. 
** use when two classes are referencing each other
** faster than including a headerfile
*/
class ICharacter;

class AMateria {
    protected:
        std::string _type;
    public:
        AMateria( void );
        AMateria( std::string const & type );
        AMateria( const AMateria &src );
        virtual ~AMateria( void );
        AMateria & operator=( const AMateria &src );

        std::string const & getType( void ) const; //Returns the materia type
        virtual AMateria* clone( void ) const = 0;
        virtual void use( ICharacter& target );
};

#endif // AMATERIA_HPP
