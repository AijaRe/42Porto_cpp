/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:27:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/14 20:07:03 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
	: AForm("RobotomyRequest", 72, 45), _target("notarget") {
	//std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm("RobotomyRequest", 72, 45), _target(target) {
	//std::cout << "RobotomyRequestForm assignment constructor called." << std::endl; 
}
	
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &copy ) 
	: AForm(copy), _target(copy._target) {
	//std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	//std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm &src ) {
	//std::cout << "RobotomyRequestForm assignment operator called." << std::endl;
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

std::string	RobotomyRequestForm::getTarget( void ) const {
	return this->_target;
}

/* 
** The srand function is used to set the seed for the random number generator. 
** The seed determines the sequence of random numbers that will be produced by rand.
** Changing the seed results in different sequences.
** time(0) function returns the current time in seconds since the epoch (usually January 1, 1970)
*/
void	RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
	AForm::execute(executor);
	std::cout << GREEN "Bzzzzzzzzzzz....." << RESET << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2) {
		std::cout << GREEN << this->_target << "has been robotomized successfully!" << RESET << std::endl;
	} else {
		std::cout << RED << "Robotomy for " << this->_target << " failed. Better luck next time!" << RESET << std::endl;
	}
}

std::ostream & operator<<( std::ostream &out, const RobotomyRequestForm &rhs ) {
	out << static_cast<const AForm&>(rhs);
	out << "Target: " << rhs.getTarget() << std::endl;
	return out;
}
