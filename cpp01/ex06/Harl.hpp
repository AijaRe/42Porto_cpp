/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:39:51 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/23 20:23:42 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#include <iostream>

class Harl {
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    Harl( void );
    ~Harl( void );
    void complain( std::string level );
    void filter( std::string level );
};

#endif

