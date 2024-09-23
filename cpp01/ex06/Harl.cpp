/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:39:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/23 20:28:10 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {
    return ;
}

Harl::~Harl( void ) {
    return ;
}

void    Harl::debug ( void ){
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << GREEN << "I love trips across the country where I can see all the museums, churches and vineyards in one day!" << RESET << std::endl;
}

void    Harl::info ( void ){
    std::cout << "[ INFO ]" << std::endl;
    std::cout << BLUE << "I can't believe paragliding is not included in my trip cost. I mean, what's a holiday without a bit of adrenaline and a whole lot of screaming?" << RESET << std::endl;
}

void    Harl::warning ( void ){
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << YELLOW << "I am quite certain I should be receiving a free massage, I am the most open-minded client you have, you cannot afford losing me!" << RESET << std::endl;
}

void    Harl::error ( void ){
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << RED << "Oh no, somebody stole my wallet! This is catastrophic, we need to contact the FBI, CIA, and Interpol to track it down immediately!" << RESET << std::endl;
}

/* 
** array of function pointers for Harl level private functions
** define an array of levels and compare them to input level
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
}

/* 
** switch needs an int for cases
** initialize to invalid value that will fall into default if not changed
*/
void    Harl::filter ( std::string level ) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int levelNb = -1;
    
    for (size_t i = 0; i < 4; i++){
        if (level == levels[i]){
            levelNb = i + 1;
            break  ;
        }
    }
    
    // ignore compiler fallthrough warning by adding the comments after each case
    switch (levelNb){
        case 1:
            this->complain("DEBUG");
            //Fallthrough
        case 2:
            this->complain("INFO");
            //Fallthrough
        case 3:
            this->complain("WARNING");
            //Fallthrough
        case 4:
            this->complain("ERROR");
            break;
        default:
            std::cout << GREEN << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
    }
}
