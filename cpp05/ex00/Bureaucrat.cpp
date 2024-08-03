/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:14:37 by arepsa            #+#    #+#             */
/*   Updated: 2024/08/03 16:28:32 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat( void ) : _name("nameless"), _grade(150) {
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ) : _name(src._name), _grade(src._grade) {
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat assignment constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << "Bureaucrat destructor called." << std::endl;
}

/* 
** Name is const therefore cannot be changed
** ssign only the grade
*/
Bureaucrat & Bureaucrat::operator=( const Bureaucrat &src ) {
	if (this != &src) {
		if (this->_grade != src._grade)
			this->_grade = src._grade;
	}
	return *this;
}

const std::string Bureaucrat::getName( void ) const {
	return this->_name;
}

int Bureaucrat::getGrade( void ) const {
	return this->_grade;
}

std::ostream & operator<<( std::ostream &out, const Bureaucrat &rhs ) {
	out << "" << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "" << std::endl;
	return out;
}
