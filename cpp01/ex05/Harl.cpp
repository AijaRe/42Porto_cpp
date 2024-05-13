/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:39:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/13 22:27:00 by arepsa           ###   ########.fr       */
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
    std::cout << "I love trips across the country where I can see all the museums, churches and vineyards in one day!" << std::endl;
}

void    Harl::info ( void ){
    std::cout << "I can't believe paragliding is not included in my trip cost. I mean, what's a holiday without a bit of adrenaline and a whole lot of screaming?" << std::endl;
}

void    Harl::warning ( void ){
    std::cout << "I am quite certain I should be receiving a free massage, I am the most open-minded client you have, you cannot afford losing me!" << std::endl;
}

void    Harl::error ( void ){
    std::cout << "Oh no, I think I left my wallet in the winery! This is catastrophic, we need to contact the FBI, CIA, and Interpol to track it down immediately!" << std::endl;
}

/* 
** array of function pointers for Harl level private functions
** define an array of levels and compar them to input level
*/
void Harl::complain ( std::string level ) {
	void(Harl::*harlFunc[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (size_t i = 0; i < 4; i++){
        if (level == levels[i]) {
            (this->*harlFunc[i])();
            return ;
        }
    }
    std::cout << "You are doing an amazing job. Thank you!" << std::endl; //no matching level found
}
