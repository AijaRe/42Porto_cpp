/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:02:30 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/15 21:10:54 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) : _name("nameless"), _signed(false), _signGrade(150), _execGrade(150) {
    std::cout << "AForm default constructor called." << std::endl;
}

AForm::AForm ( const std::string name, int signGrade, int execGrade ) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    //std::cout << "Form assignment constructor called." << std::endl;
    if (signGrade < Bureaucrat::HIGHEST_GRADE || execGrade < Bureaucrat::HIGHEST_GRADE)
        throw AForm::GradeTooHighException();
    else if (signGrade > Bureaucrat::LOWEST_GRADE || execGrade > Bureaucrat::LOWEST_GRADE)
        throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm &copy ) : _name(copy.getName()), _signed(copy.getSigned()), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade()) {
    std::cout << "Form copy constructor called." << std::endl;
}

AForm::~AForm( void ) {
    //std::cout << "Form destructor called." << std::endl;
}

AForm & AForm::operator=( const AForm &src ) {
    std::cout << "Form assignment operator called." << std::endl;
    if (this->_signed != src.getSigned())
        this->_signed = src.getSigned();
    return *this;
}

const char *AForm::GradeTooHighException::what( void ) const throw() {
    return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what( void ) const throw() {
    return "Form grade is too low!";
}

const std::string AForm::getName( void ) const {
    return this->_name;
}

bool AForm::getSigned( void ) const {
    return this->_signed;
}

int AForm::getSignGrade( void ) const {
    return this->_signGrade;
}

int AForm::getExecGrade( void ) const {
    return this->_execGrade;
}

/* 
** Throws error and exceptionto Bureaucrat signForm method 
** that prints the e.what() content in both cases
*/
void AForm::beSigned( const Bureaucrat &bureaucrat ) {
    if (this->_signed)
        throw std::logic_error ("Form " + this->_name + " is already signed.");
    else if (bureaucrat.getGrade() > this->_signGrade)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_signed = true;
}

std::ostream & operator<<( std::ostream &out, const AForm &rhs ) {
    out << "Form name: " << rhs.getName() << std::endl;
    out << "Form sign grade: " << rhs.getSignGrade() << std::endl;
    out << "Form exec grade: " << rhs.getExecGrade() << std::endl;
    out << "Form signed: " << rhs.getSigned() << std::endl;
    return out;
}