/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:25 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/15 11:12:21 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal{
    private:
        Brain* _brain;
    public:
        Dog( void );
        Dog( const Dog &src );
        ~Dog( void );
        Dog & operator=( const Dog &src );

        void    makeSound( void ) const;
        Brain*  getBrain( void ) const;
};

#endif // DOG_HPP
