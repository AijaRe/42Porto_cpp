/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:02:30 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/12 14:59:52 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("nameless"), _signed(false), _signGrade(150), _execGrade(150) {
	//std::cout << "Form default constructor called." << std::endl;
}

Form::Form ( const std::string name, int signGrade, int execGrade ) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	//std::cout << "Form assignment constructor called." << std::endl;
	if (signGrade < Bureaucrat::HIGHEST_GRADE || execGrade < Bureaucrat::HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	else if (signGrade > Bureaucrat::LOWEST_GRADE || execGrade > Bureaucrat::LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form( const Form &copy ) : _name(copy.getName()), _signed(copy.getSigned()), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade()) {
	//std::cout << "Form copy constructor called." << std::endl;
}

Form::~Form( void ) {
	//std::cout << "Form destructor called." << std::endl;
}

/* 
** only attribute that is not const is _signed
*/
Form & Form::operator=( const Form &src ) {
	//std::cout << "Form assignment operator called." << std::endl;
	if (this->_signed != src.getSigned())
		this->_signed = src.getSigned();
	return *this;
}

const char*	Form::GradeTooHighException::what( void ) const throw() {
	return "Form grade is too high!";
}

const char*	Form::GradeTooLowException::what( void ) const throw() {
	return "Form grade is too low!";
}

const std::string	Form::getName( void ) const {
	return this->_name;
}

bool	Form::getSigned( void ) const {
	return this->_signed;
}

int	Form::getSignGrade( void ) const {
	return this->_signGrade;
}

int	Form::getExecGrade( void ) const {
	return this->_execGrade;
}

/* 
** Throws error and exception to Bureaucrat signForm method 
** that prints the e.what() content in both cases
*/
void	Form::beSigned( const Bureaucrat &bureaucrat ) {
	if (this->_signed)
		throw std::logic_error ("Form " + this->_name + " is already signed.");
	else if (bureaucrat.getGrade() > this->_signGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_signed = true;
}

std::ostream & operator<<( std::ostream &out, const Form &rhs ) {
	out << "Form name: " << rhs.getName() << std::endl;
	out << "Form sign grade: " << rhs.getSignGrade() << std::endl;
	out << "Form exec grade: " << rhs.getExecGrade() << std::endl;
	out << "Form signed: " << rhs.getSigned() << std::endl;
	return out;
}
