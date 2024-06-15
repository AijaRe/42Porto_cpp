/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:49:44 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/15 10:46:58 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

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
};

#endif // BRAIN_HPP
