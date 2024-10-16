/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:51:01 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/16 19:37:23 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "main.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	printTitle(std::string title) {
	std::cout << BOLD << CYAN;
    std::cout << LINE << std::endl;
    std::cout << "| " << title << std::endl;
    std::cout << LINE << std::endl;
    std::cout << RESET << std::endl;
}

int	main( void ) {
	{
		printTitle("SUBJECT TEST");
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");	
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	{
		printTitle("TEST ERROR FORM CREATION");
		Intern someIntern;
		AForm* someForm;
		someForm = someIntern.makeForm("", "Arthur");
		someForm = someIntern.makeForm("Presidential Pardon", "");
		someForm = someIntern.makeForm("Random Stuff", "Arthur");
		delete someForm;
	}
	{
		printTitle("TEST VALID FORM CREATION & EXECUTION");
		Intern someIntern;
		Bureaucrat ana("Ana The Best", 1);
		AForm* ppf;
		ppf = someIntern.makeForm("Presidential Pardon", "Ford");
		ana.signForm(*ppf);
		ana.executeForm(*ppf);
		
		delete ppf;
	}
	
	printTitle("END OF TESTS");
	
	return 0;
}
