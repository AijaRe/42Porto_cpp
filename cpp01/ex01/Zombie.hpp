/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:39:08 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/05 18:28:51 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;
        int index;

    public:
        Zombie(void);
        ~Zombie(void);
        void    setName(std::string name);
        void    setIndex(int index);
        void    announce(void);
};
Zombie* zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP
