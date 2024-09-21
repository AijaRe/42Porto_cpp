/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:39:08 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/21 14:51:47 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );
		void    announce( void );
};
Zombie*	newZombie( std:: string name );
void	randomChump( std::string name );

#endif // ZOMBIE_HPP
