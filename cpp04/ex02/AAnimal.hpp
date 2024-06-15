/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:38 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/15 21:32:05 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

/* 
** class that contains a method that cannot be implemented ( equals 0 )
** means this class cannot be instantiated because it is missing a behaviour
** but that makes child classes to have this mandatory method
*/
class AAnimal {
    protected:
        std::string _type;
    public:
        AAnimal( void );
        AAnimal( std::string type );
        AAnimal( const AAnimal &src );
        virtual ~AAnimal( void );
        AAnimal & operator=( const AAnimal &src );

        std::string    getType( void ) const;
        virtual void    makeSound( void ) const = 0;
};

#endif // AANIMAL_HPP
