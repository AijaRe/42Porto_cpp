/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:25 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/11 21:42:27 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal{
    private:
        // Private members
    public:
        Dog( void );
        Dog( const Dog &src );
        ~Dog( void );
        Dog & operator=( const Dog &src );

        void    makeSound( void ) const;
};

#endif // DOG_HPP
