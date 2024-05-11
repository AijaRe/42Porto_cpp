/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:45:15 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/09 18:45:15 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(void) {
	// read and save numbers from existing file
	std::ifstream infile("input");

	unsigned int	num1;
	unsigned int	num2;

	infile >> num1 >> num2;

	std::cout << num1 << " " << num2 << std::endl;
	infile.close();

	// create a new file and write text into it
	std::ofstream	outfile("test.txt");

	outfile << "I am writing into test.txt..." << std::endl;
	outfile.close();

}