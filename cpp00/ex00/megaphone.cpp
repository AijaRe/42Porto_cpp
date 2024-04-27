/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:37:40 by arepsa            #+#    #+#             */
/*   Updated: 2024/04/19 20:06:24 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/* 
** $>./megaphone "shhhhh... I think the students are asleep..."
** SHHHHH... I THINK THE STUDENTS ARE ASLEEP...	->	expected output 
** $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
** DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.	->	expected output
** $>./megaphone
** * LOUD AND UNBEARABLE FEEDBACK NOISE *	->	expected output
*/
int main(int argc, char **argv) {

	if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

	for (int i = 1; i < argc; ++i) {
        std::string input = argv[i];

        for (size_t j = 0; j < input.length(); ++j) {
            input[j] = std::toupper(input[j]);
        }
        std::cout << input;
    }

    std::cout << std::endl;

    return 0;
} 
