/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:00:32 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/11 21:41:47 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal{
    private:
        // Private members
    public:
        Cat( void );
        Cat( const Cat &src );
        ~Cat( void );
        Cat & operator=( const Cat &src );

        void    makeSound( void ) const;
};

#endif // CAT_HPP
