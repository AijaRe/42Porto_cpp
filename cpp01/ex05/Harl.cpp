/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:39:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/16 19:23:17 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {
    std::cout << "Harl enters the tourist bus." << std::endl;
}

Harl::~Harl( void ) {
    std::cout << "Harl leaves the tourist bus." << std::endl;
}

void    Harl::debug ( void ){
    std::cout << GREEN << "I love trips across the country where I can see all the museums, churches and vineyards in one day!" << RESET << std::endl;
}

void    Harl::info ( void ){
    std::cout << BLUE << "I can't believe paragliding is not included in my trip cost. I mean, what's a holiday without a bit of adrenaline and a whole lot of screaming?" << RESET << std::endl;
}

void    Harl::warning ( void ){
    std::cout << YELLOW << "I am quite certain I should be receiving a free massage, I am the most open-minded client you have, you cannot afford losing me!" << RESET << std::endl;
}

void    Harl::error ( void ){
    std::cout << RED << "Oh no, somebody stole my wallet! This is catastrophic, we need to contact the FBI, CIA, and Interpol to track it down immediately!" << RESET << std::endl;
}

/* 
** array of function pointers for Harl level private functions
** define an array of levels and compare them to input level
** call member function through a pointer to a function
** return_type (*FuncPtr) (parameter type, ....);  
*/
void Harl::complain ( std::string level ) {
	void    (Harl::*harlFunc[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (size_t i = 0; i < 4; i++){
        if (level == levels[i]) {
            (this->*harlFunc[i])();
            return ;
        }
    }
    std::cout << RED << "You are beautiful and you are doing an amazing job. Thank you!" << RESET << std::endl; //no matching level found
}
