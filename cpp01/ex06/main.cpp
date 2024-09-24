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

int		main( int argc, char** argv ) {
	if (argc == 2){
		Harl harl;

		std::string level = argv[1];
		for (size_t i = 0; i < level.length(); i++)
			level[i] = toupper(level[i]);
		harl.filter(level);
	}
	else
		std::cout << "Wrong number of arguments\nCorrect usage: ./harl <complaint_level>" << std::endl;

	return 0;
}

