/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:11:35 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/16 19:26:03 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {
	//std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern( const Intern &copy ) {
	//std::cout << "Intern copy constructor called." << std::endl;
	*this = copy;
}

Intern::~Intern( void ) {
	//std::cout << "Intern destructor called." << std::endl;
}

Intern & Intern::operator=( const Intern &src ) {
	//std::cout << "Intern assignment operator called." << std::endl;
	(void)src;
	return *this;
}

AForm*	createPresidentialPardonForm( const std::string& target ) {
	return new PresidentialPardonForm(target);
}

AForm*	createRobotomyRequestForm( const std::string& target ) {
	return new RobotomyRequestForm(target);
}

AForm*	createShrubberyCreationForm( const std::string& target ) {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makeForm( const std::string formName, const std::string target ) {

	if (formName.empty() || target.empty()) {
		std::cout << RED << "Intern cannot create form. Form or target empty." << RESET << std::endl;
		return NULL;
	}
	
	std::string	formList[FORM_COUNT] = {
		"Presidential Pardon",
		"Robotomy Request",
		"Shrubbery Creation"
	};

	//return_type (*FuncPtr) (parameter type, ....);  
	AForm* (*formCreators[FORM_COUNT])(const std::string&) = {
		createPresidentialPardonForm,
		createRobotomyRequestForm,
		createShrubberyCreationForm
	};
	
	for (int i = 0; i < FORM_COUNT; i++) {
		if (formName == formList[i]) {
			std::cout << GREEN << "Intern creates " << formName << " form." << RESET << std::endl;
			return formCreators[i](target);
		}
	}
	
	std::cout << YELLOW << "Intern cannot create " << formName << " form." << std::endl;
	std::cout << "Available forms: ";
	for (int i = 0; i < FORM_COUNT; i++) {
		std::cout << formList[i];
		if (i < FORM_COUNT - 1) {
			std::cout << ", ";
		}
	}
	std::cout << RESET << std::endl;
	return NULL;
}
