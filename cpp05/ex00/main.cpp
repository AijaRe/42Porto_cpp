/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:51:01 by arepsa            #+#    #+#             */
/*   Updated: 2024/08/16 09:47:15 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"

// Test separation lines with symbols
#define LINE "|---------------------------------------------|"
#define ARROW "=> "

void	printTitle(std::string title) {
	std::cout << BOLD << CYAN;
    std::cout << LINE << std::endl;
    std::cout << "| " << title << std::endl;
    std::cout << LINE << std::endl;
    std::cout << RESET << std::endl;
}

int	main( void ) {
	
	printTitle("TEST VALID BUREAUCRAT CONSTRUCTION");
	try {
		Bureaucrat b1("Ana The Best", 1);
		std::cout << GREEN << ARROW << b1 << RESET << std::endl;
	}
	catch (std::exception & e) {
		 std::cout << RED << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}
	try {
		Bureaucrat b2("Bob The Worst", 150);
		std::cout << GREEN << ARROW << b2 << RESET << std::endl;
	}
	catch (std::exception & e) {
		std::cout << RED << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}
	try {
		Bureaucrat b3("Zaz Sweet Middle", 100);
		std::cout << GREEN << ARROW << b3 << RESET << std::endl;
	}
	catch (std::exception & e) {
		std::cout << RED << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}
	
	printTitle("TEST GRADE TOO LOW BUREAUCRAT CONSTRUCTION");
	try {
		Bureaucrat b4("Faf Too Low", 151);
		std::cout << GREEN << ARROW << b4 << RESET << std::endl;
	}
	catch (std::exception & e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}
	
	printTitle("TEST GRADE TOO HIGH BUREAUCRAT CONSTRUCTION");
	try {
		Bureaucrat b5("Lol Too High", 0);
		std::cout << GREEN << ARROW << b5 << RESET << std::endl;
	}
	catch (std::exception & e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}
	
	printTitle("TEST BUREAUCRAT COPY CONSTRUCTOR");
	try {
		Bureaucrat b6("Copycat", 50);
		std::cout << GREEN << ARROW << b6 << RESET;
		Bureaucrat b7(b6);
		std::cout << GREEN << ARROW << b7 << RESET << std::endl;
	}
	catch (std::exception & e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}
	
	printTitle("TEST VALID INCREMENT GRADE");
	try {
		Bureaucrat b8("Incrementer", 50);
		std::cout << "Before incrementing: " << std::endl;
		std::cout << GREEN << ARROW << b8 << RESET << std::endl;
		b8.incrementGrade();
		std::cout << "After incrementing: " << std::endl;
		std::cout << GREEN << ARROW << b8 << RESET << std::endl;
	}
	catch (std::exception & e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}

	printTitle("TEST VALID DECREMENT GRADE");
	try {
		Bureaucrat b9("Decrementer", 50);
		std::cout << "Before decrementing: " << std::endl;
		std::cout << GREEN << ARROW << b9 << RESET << std::endl;
		b9.decrementGrade();
		std::cout << "After decrementing: " << std::endl;
		std::cout << GREEN << ARROW << b9 << RESET << std::endl;
	}
	catch (std::exception & e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}
	
	printTitle("TEST GRADE TOO HIGH INCREMENT GRADE");
	try {
		Bureaucrat b10("Incrementer", 1);
		std::cout << "Before incrementing: " << std::endl;
		std::cout << GREEN << ARROW << b10 << RESET << std::endl;
		b10.incrementGrade();
		std::cout << "After incrementing: " << std::endl;
		std::cout << GREEN << ARROW << b10 << RESET << std::endl;
	}
	catch (std::exception & e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}
	
	printTitle("TEST GRADE TOO LOW DECREMENT GRADE");
	try {
		Bureaucrat b11("Decrementer", 150);
		std::cout << "Before decrementing: " << std::endl;
		std::cout << GREEN << ARROW << b11 << RESET << std::endl;
		b11.decrementGrade();
		std::cout << "After decrementing: " << std::endl;
		std::cout << GREEN << ARROW << b11 << RESET << std::endl;
	}
	catch (std::exception & e) {
		std::cout << YELLOW << ARROW << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << CYAN << LINE << RESET << std::endl;
	std::cout << BOLD << CYAN << "| END OF TESTS" << RESET << std::endl;
	std::cout << BOLD << UNDERLINE << CYAN << LINE << RESET << std::endl;
	return 0;
}
