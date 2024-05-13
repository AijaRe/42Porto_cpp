/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:38:58 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/11 12:38:58 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	basic_tests ( void ) {
	Harl harl;
	std::cout << "DEBUG level: " << std::endl;
	harl.complain("DEBUG");
	std::cout << "INFO level: " << std::endl;
	harl.complain("INFO");
	std::cout << "WARNING level: " << std::endl;
	harl.complain("WARNING");
	std::cout << "ERROR level: " << std::endl;
	harl.complain("ERROR");
}

void	user_test ( char* argv){
	Harl harl;
	std::string level = argv;
	for (size_t i = 0; i < level.length(); i++)
		level[i] = toupper(level[i]);
	harl.complain(level);
}

int		main( int argc, char** argv ) {
	if (argc == 1){
		std::cout << "Basic tests.\nYou can try specific test with ./harl <complaint>" << std::endl;
		basic_tests();
	}
	else if (argc == 2)
		user_test (argv[1]);
	else
		std::cout << "Too many arguments." << std::endl;

	return 0;
}