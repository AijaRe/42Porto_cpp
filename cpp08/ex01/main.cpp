/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:11:03 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/12 21:11:03 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	printTitle(std::string title) {
	std::cout << std::endl;
	std::cout << BOLD << CYAN << LINE << std::endl;
    std::cout << "| " << title << std::endl;
    std::cout << LINE << RESET << std::endl;
}

void printSpan(const Span& span) {
    try {
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

int	main(void) {
	{
		printTitle("SUBJECT TEST");
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Expected output:\n2\n14" << std::endl;
		std::cout << "Program output" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	try {
		printTitle("TEST COPY CONSTRUCTOR & ASSIGNMENT OPERATOR");
		Span span1(5);
		span1.addNumber(5);
		span1.addNumber(3);
		span1.addNumber(17);
		span1.addNumber(9);

		std::cout << "Original Span" << ARROW << std::endl;
		printSpan(span1);

		// Test copy constructor
		Span span2(span1);
		std::cout << "Copied Span" << ARROW << std::endl;
		printSpan(span2);

		// Test assignment operator
		Span span3(5);
		span3 = span1;
		std::cout << "Assigned Span" << ARROW << std::endl;
		printSpan(span3);

		std::cout << "Changing output for copied spans..." << std::endl;
		span2.addNumber(-2);
		span3.addNumber(-3);
		std::cout << "Copied Span" << ARROW << std::endl;
		printSpan(span2);
		std::cout << "Assigned Span" << ARROW << std::endl;
		printSpan(span3);

		std::cout << "Original Span"<< ARROW << std::endl;
		printSpan(span1);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		printTitle("TEST SPAN WITH NEGATIVE NUMBERS");
		Span sp = Span(5);
		sp.addNumber(-6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(-9);
		sp.addNumber(11);
		std::cout << "Expected output:\n3\n26" << std::endl;
		std::cout << "Program output" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		printTitle("TEST ADDING OUT OF BOUNDS");
		sp.addNumber(100);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		printTitle("TEST SHORTEST SPAN WITH ONE NUMBER");
		Span sp = Span(1);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		printTitle("TEST SHORTEST SPAN WITH NO NUMBER");
		Span sp;
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		printTitle("TEST LONGEST SPAN WITH ONE NUMBER");
		Span sp = Span(1);
		sp.addNumber(42);
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	printTitle("END OF TESTS");

	return 0;
}