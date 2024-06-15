/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:49:40 by arepsa            #+#    #+#             */
/*   Updated: 2024/06/15 10:50:42 by arepsa           ###   ########.fr       */
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

void    Brain::setIdea( std::string idea ) {
    int i = this->_busy;
    this->_ideas[i] = idea;
    this->_busy = (i + 1) % 100;
    this->_idea_count++;
}

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