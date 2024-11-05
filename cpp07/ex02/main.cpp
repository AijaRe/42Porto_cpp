/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:41:05 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/05 21:41:05 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
void	printTitle(std::string title) {
	std::cout << std::endl;
	std::cout << BOLD << CYAN;
    std::cout << LINE << std::endl;
    std::cout << "| " << title << std::endl;
    std::cout << LINE << std::endl;
    std::cout << RESET << std::endl;
}

int	main(void) {

	printTitle("TEST EMPTY ARRAY");
	Array<int> emptyArr;
	std::cout << "Empty array size: " << emptyArr.size() << std::endl;

	printTitle("TEST INT ARRAY AND OUT OF BOUNDS ACCESS");
	try {
		Array<int> intArr(5);
		for(int i = 0; i < 5; i++){
			intArr[i] = 10 + i;
		}
		std::cout << "Print created int array: " << std::endl;
		for(int i = 0; i < 5; i++){
			std::cout << intArr[i] << " ";
		}
		std::cout << std::endl;

		const Array<int> constArr = intArr;
    	std::cout << "Const array element access []: " << std::endl;
		for(int i = 0; i < 5; i++){
			std::cout << constArr[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Access out of bounds: " << std::endl;
		std::cout << intArr[8] << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	printTitle("TEST FLOAT ARRAY AND NEGATIVE ACCESS");
	try {
		Array<float> floatArr(3);
		floatArr[0] = 1.21f;
        floatArr[1] = 42.42f;
        floatArr[2] = -12.2f;
		std::cout << "Print created float array: " << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << floatArr[i] << " ";
        }
        std::cout << std::endl;

		std::cout << "Access out of bounds negative: " << std::endl;
		std::cout << floatArr[-8] << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	printTitle("END OF TESTS");

	return 0;
}