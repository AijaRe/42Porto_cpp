/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:25 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/15 21:27:24 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal{
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
