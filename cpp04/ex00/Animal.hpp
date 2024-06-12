/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:38 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/12 19:56:40 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

/* 
** for polymorphism to work correctly the base class 
** needs to have virtual destructor 
** to override a function in child class, you need to mark
** the same base class function as virtual
*/
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
