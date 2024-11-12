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

int	main(void) {

{
	printTitle("SUBJECT TEST");
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

	return 0;
}