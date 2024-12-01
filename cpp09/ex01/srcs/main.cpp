/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:44:29 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/01 12:44:29 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int argc, char** argv) {

	if (argc != 2)
	{
		std::cerr << "Incorrect input." << std::endl;
		std::cerr << "Usage example: ./RPN \"1 2 3 + -\"" << std::endl;
		return 1;
	}
	try {
		std::string input = argv[1];

		RPN rpn;
		rpn.processInput(input);
		
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}