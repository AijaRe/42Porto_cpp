/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:14:37 by arepsa            #+#    #+#             */
/*   Updated: 2024/08/19 17:05:21 by arepsa           ###   ########.fr       */
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
	//std::cout << "Bureaucrat assignment constructor called." << std::endl;
	if (grade < Bureaucrat::HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat( void ) {
	//std::cout << "Bureaucrat destructor called." << std::endl;
}
/* 
** Name is const therefore cannot be changed
** assign only the grade
*/
Bureaucrat & Bureaucrat::operator=( const Bureaucrat &src ) {
	if (this != &src) {
		if (this->_grade != src._grade)
			this->_grade = src._grade;
	}
	return *this;
}

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return "Bureaucrat grade is too high!";
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return "Bureaucrat grade is too low!";
}


const std::string Bureaucrat::getName( void ) const {
	return this->_name;
}

int Bureaucrat::getGrade( void ) const {
	return this->_grade;
}

void Bureaucrat::incrementGrade( void ) {
	if (this->_grade - 1 < Bureaucrat::HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade( void ) {
	if (this->_grade + 1 > Bureaucrat::LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm( Form &form ) {
	try {
		form.beSigned(*this);
		std::cout << GREEN << this->_name << " signed " << form.getName() << "." << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << ARROW << "Exception: " << this->_name << " cannot sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

std::ostream & operator<<( std::ostream &out, const Bureaucrat &rhs ) {
	out << "" << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return out;
}
