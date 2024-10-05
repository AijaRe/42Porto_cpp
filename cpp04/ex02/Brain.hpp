/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:49:44 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/05 17:40:05 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <climits>

class Brain {
    private:
        std::string _ideas[100];
        int         _busy;
        int         _idea_count;
    public:
        Brain( void );
        Brain( const Brain &src );
        ~Brain( void );
        Brain & operator=( const Brain &src );

        void    setIdea( std::string idea );
        void    printIdeas( void );
        int     getBusyCount( void );
        int     getIdeaCount( void );
};

#endif // BRAIN_HPP
