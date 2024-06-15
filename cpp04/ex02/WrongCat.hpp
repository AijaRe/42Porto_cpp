/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:58:21 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/12 21:27:11 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
    private:
        // Private members
    public:
        WrongCat( void );
        WrongCat( const WrongCat &src );
        ~WrongCat( void );
        WrongCat & operator=( const WrongCat &src );

        void        makeSound( void ) const;
};

#endif // WRONGCAT_HPP
