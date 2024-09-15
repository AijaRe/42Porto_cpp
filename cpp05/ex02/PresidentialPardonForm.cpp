/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:27:50 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/15 22:12:45 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
	: AForm ("PresidentialPardon", 25, 5), _target("notarget") {
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: AForm ("PresidentialPardon", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &copy )
	: AForm(copy), _target(copy._target) {
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm &src ) {
	std::cout << "PresidentialPardonForm assignment operator called." << std::endl;
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget( void ) const {
	return this->_target;
}

std::ostream & operator<<( std::ostream &out, const PresidentialPardonForm &rhs ) {
	out << static_cast<const AForm&>(rhs);
    out << "Target: " << rhs.getTarget() << std::endl;
    return out;
}
