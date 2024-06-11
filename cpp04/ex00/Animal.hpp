/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:38 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/11 21:58:24 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string _type;
    public:
        Animal( void );
        Animal( std::string type );
        Animal( const Animal &src );
        virtual ~Animal( void );
        Animal & operator=( const Animal &src );

        std::string    getType( void ) const;
        virtual void    makeSound( void ) const;
};

#endif // ANIMAL_HPP
