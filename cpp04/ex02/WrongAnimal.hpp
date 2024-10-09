/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:58:14 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/09 21:45:47 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    private:
        std::string _type;
    public:
        WrongAnimal( void );
        WrongAnimal( std::string type );
        WrongAnimal( const WrongAnimal &src );
        virtual ~WrongAnimal( void );
        WrongAnimal & operator=( const WrongAnimal &src );

        std::string     getType( void ) const;
        void    makeSound( void ) const;
};

#endif // WRONGANIMAL_HPP
