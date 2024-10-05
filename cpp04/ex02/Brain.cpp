/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:49:40 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/05 17:42:54 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) : _busy(0), _idea_count(0) {
    std::cout << "Brain default constructor called." << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "Free space for idea";
}

Brain::Brain( const Brain &src ) : _busy(src._busy), _idea_count(src._idea_count) {
    std::cout << "Brain copy constructor called." << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = src._ideas[i];
}

Brain::~Brain( void ) {
    std::cout << "Brain destructor called." << std::endl;
}

Brain & Brain::operator=( const Brain &src ) {
    std::cout << "Brain assignment operator called." << std::endl;
    if (this != &src) {
        this->_busy = src._busy;
        this->_idea_count = src._idea_count;
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = src._ideas[i];
    }
    return *this;
}

/* 
** this->_busy is always within the range of 0 to 99 (inclusive).
** _busy wraps around after reaching 100
** -> overwrite older ideas after reaching 100
*/
void    Brain::setIdea( std::string idea ) {
	if (this->_idea_count == INT_MAX) {
		std::cout << "Reached idea limit. Resetting to 0." << std::endl;
		this->_idea_count = 0;
    }
    int i = this->_busy;
    this->_ideas[i] = idea;
    this->_busy = (i + 1) % 100;
    this->_idea_count++;
}

/* 
** if idea cound hasn't reached 100, print only busy slots,
** otherwise print all
*/
void    Brain::printIdeas( void ) {
    if (this->_idea_count != 0) {
        if (this->_idea_count < 100) {
            for (int i = 0; i < this->_busy; i++)
                std::cout << "Idea " << i + 1 << ": " << this->_ideas[i] << std::endl;
        } else {
            for (int i = 0; i < 100; i++)
                std::cout << "Idea " << i + 1 << ": " << this->_ideas[i] << std::endl;
        }
    } else {
        std::cout << "This brain has no ideas!" << std::endl;
    }
}

int	Brain::getBusyCount( void ) {
    return this->_busy;
}

int	Brain::getIdeaCount( void ) {
    return this->_idea_count;
}
