/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:08:01 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/11 19:16:21 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int	main(void){
	int numArr[] = {1, 2, 3, 4, 5};

	std::vector<int> numCont(numArr, numArr + 5);
	try {
		std::vector<int>::iterator it = easyfind(numCont, 3);
		std::cout << "Found value: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
