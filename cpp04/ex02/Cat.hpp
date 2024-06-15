/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:32 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/15 21:27:00 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal{
    private:
        Brain* _brain;
    public:
        Cat( void );
        Cat( const Cat &src );
        ~Cat( void );
        Cat & operator=( const Cat &src );

        void    makeSound( void ) const;
        Brain* getBrain( void ) const;
};

#endif // CAT_HPP
