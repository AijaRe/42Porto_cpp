/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:51:01 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/14 19:23:05 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "main.hpp"

void	printTitle(std::string title) {
	std::cout << BOLD << CYAN;
    std::cout << LINE << std::endl;
    std::cout << "| " << title << std::endl;
    std::cout << LINE << std::endl;
    std::cout << RESET << std::endl;
}

/* 
** signForm() can be called without the try-catch block, since
** it uses the block inside the method when calling beSigned()
** form creation has to be inside the try-catch block since it is called from main
** caller is responsible for exception treatment
*/
int	main( void ) {
	Bureaucrat ana("Ana The Best", 1);
	Bureaucrat bob("Bob The Worst", 150);
	Bureaucrat zaz("Zaz Sweet Middle", 75);
	
	printTitle("TEST VALID FORM CREATION");
	try {
		Form validForm_100_5("validForm_100_5", 50, 5);
		std::cout << GREEN << validForm_100_5 << RESET << std::endl;
	}
	catch (std::exception &e) {
		 std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}

	printTitle("TEST FORM COPY CONSTRUCTOR");
	try {
		Form validForm_50_5("validForm_50_5", 50, 5);
		std::cout << "Form used for copy: " << std::endl;
		std::cout << GREEN << validForm_50_5 << RESET << std::endl;
		Form validForm_50_5_copy(validForm_50_5);
		std::cout << "Form created using copy constructor: " << std::endl;
		std::cout << GREEN << validForm_50_5_copy << RESET << std::endl;
	} catch (std::exception &e) {
		 std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}
	
	printTitle("TEST FORM ASSIGNMENT OPERATOR");
	try {
		Form validForm_50_5("validForm_50_5", 50, 5);
		ana.signForm(validForm_50_5);
		std::cout << "Form used for assignment: " << std::endl;
		std::cout << GREEN << validForm_50_5 << RESET << std::endl;
		Form validForm_100_10_assign("validForm_100_10_assign", 100, 10);
		std::cout << "Form before assignment: " << std::endl;
		std::cout << GREEN << validForm_100_10_assign << RESET << std::endl;
		validForm_100_10_assign = validForm_50_5;
		std::cout << "Form after assignment: " << std::endl;
		std::cout << GREEN << validForm_100_10_assign << RESET << std::endl;
	} catch (std::exception &e){
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}
	
	printTitle("TEST FORM GRADE TOO LOW CREATION");
	try {
		Form lowForm_151_5("lowForm_151_5", 151, 5);
		std::cout << GREEN << ARROW << lowForm_151_5 << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}

	printTitle("TEST FORM GRADE TOO HIGH CREATION");
	try {
		Form highForm_100_0("highForm_100_0", 100, 0);
		std::cout << GREEN << highForm_100_0 << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}

	printTitle("TEST NEGATIVE FORM GRADE CREATION");
	try {
		Form negativeForm("negativeForm", 100, -15);
		std::cout << GREEN << negativeForm << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}

	printTitle("TEST VALID FORM SIGNING");
	Form validForm_100_5("validForm_100_5", 100, 5);
	std::cout << GREEN << zaz << RESET << std::endl;
	zaz.signForm(validForm_100_5);
	std::cout << std::endl;
	std::cout << GREEN << validForm_100_5 << RESET << std::endl;


	printTitle("TEST FORM SIGNING WITH EQUEAL GRADE");
	Form validForm_75_5("validForm_75_5", 75, 5);
	std::cout << GREEN << zaz << RESET << std::endl;
	zaz.signForm(validForm_75_5);
	std::cout << std::endl;
	std::cout << GREEN << validForm_75_5 << RESET << std::endl;

	printTitle("TEST FORM SIGNING ALREADY SIGNED");
	std::cout << GREEN << validForm_100_5 << RESET << std::endl;
	ana.signForm(validForm_100_5);

	printTitle("TEST FORM SIGNING GRADE TOO LOW");
	Form validForm_70_5("validForm_70_5", 70, 5);
	std::cout << GREEN << bob << RESET << std::endl;
	bob.signForm(validForm_70_5);
	std::cout << std::endl;
	std::cout << GREEN << validForm_70_5 << RESET << std::endl;
	
	printTitle("END OF TESTS");
	
	return 0;
}
