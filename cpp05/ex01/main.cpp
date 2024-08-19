/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:51:01 by arepsa            #+#    #+#             */
/*   Updated: 2024/08/19 16:51:13 by arepsa           ###   ########.fr       */
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
		Form validForm_50_5_copy(validForm_50_5);
		std::cout << GREEN << validForm_50_5_copy << RESET << std::endl;
	} catch (std::exception &e) {
		 std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}
	
	printTitle("TEST FORM ASSIGNMENT OPERATOR");
	try {
		Form validForm_50_5("validForm_50_5", 50, 5);
		validForm_50_5.beSigned(ana);
		std::cout << GREEN << validForm_50_5 << RESET << std::endl;
		Form validForm_100_10_assign("validForm_100_10_assign", 100, 10);
		validForm_100_10_assign = validForm_50_5;
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
	try {
		Form validForm_100_5("validForm_100_5", 100, 5);
		std::cout << GREEN << zaz << RESET << std::endl;
		zaz.signForm(validForm_100_5);
		std::cout << std::endl;
		std::cout << GREEN << validForm_100_5 << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}

	printTitle("TEST FORM SIGNING WITH EQUEAL GRADE");
	try {
		Form validForm_75_5("validForm_75_5", 75, 5);
		std::cout << GREEN << zaz << RESET << std::endl;
		zaz.signForm(validForm_75_5);
		std::cout << std::endl;
		std::cout << GREEN << validForm_75_5 << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}

	printTitle("TEST FORM SIGNING ALREADY SIGNED");
	try {
		Form validForm_100_5("validForm_100_5", 100, 5);
		zaz.signForm(validForm_100_5);
		std::cout << std::endl;
		std::cout << GREEN << validForm_100_5 << RESET << std::endl;
		ana.signForm(validForm_100_5);
	} catch (std::exception &e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}

	printTitle("TEST FORM SIGNING GRADE TOO LOW");
	try {
		Form validForm_100_5("validForm_100_5", 100, 5);
		std::cout << GREEN << bob << RESET << std::endl;
		bob.signForm(validForm_100_5);
		std::cout << std::endl;
		std::cout << GREEN << validForm_100_5 << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << CYAN << LINE << RESET << std::endl;
	std::cout << BOLD << CYAN << "| END OF TESTS" << RESET << std::endl;
	std::cout << BOLD << UNDERLINE << CYAN << LINE << RESET << std::endl;
	return 0;
}
