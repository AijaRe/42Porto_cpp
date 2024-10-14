/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:51:01 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/14 20:08:18 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "main.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

void	printTitle(std::string title) {
	std::cout << BOLD << CYAN;
    std::cout << LINE << std::endl;
    std::cout << "| " << title << std::endl;
    std::cout << LINE << std::endl;
    std::cout << RESET << std::endl;
}

int	main( void ) {
	Bureaucrat ana("Ana The Best", 1);
	Bureaucrat bob("Bob The Worst", 150);
	Bureaucrat zaz("Zaz Sweet Middle", 75);
	Bureaucrat ror("Ror A Bit Above Average", 60);
	
	printTitle("TEST GRADE TOO LOW FORM SIGN/EXECUTION");
	PresidentialPardonForm pform("Arthur");
	std::cout << pform << std::endl;
	zaz.signForm(pform);
	ana.signForm(pform);
	std::cout << pform << std::endl;
	zaz.executeForm(pform);
	
	
	printTitle("TEST UNSIGNED PRESIDENTIAL FORM EXECUTION");
	PresidentialPardonForm pform2("Ford");
	std::cout << pform2 << std::endl;
	ana.executeForm(pform2);
	
	printTitle("TEST PRESIDENTIAL FORM EXECUTION");
	std::cout << pform << std::endl;
	ana.executeForm(pform);
	
	printTitle("TEST PRESIDENTIAL FORM COPY OPERATOR");
	PresidentialPardonForm pformCopy(pform);
	std::cout << pformCopy << std::endl;

	printTitle("TEST PRESIDENTIAL FORM ASSIGNMENT OPERATOR");
	PresidentialPardonForm pformAssign = pform;
	std::cout << pformAssign << std::endl;


	printTitle("END OF TESTS");
	
	return 0;
}
