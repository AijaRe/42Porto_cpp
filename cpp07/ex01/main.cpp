/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:20:29 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/31 19:20:29 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main (void) {
	int intArr[] = {1, 42, -100, 14, 21};
	double dbArr[] = {1.11, 42.42, -1.12345};
	std::string strArr[] = {"Smile", "while", "you", "still", "have", "teeth"};

	std::cout << "Let's iter int array =>" << std::endl;
	iter(intArr, 5, printItem);

	std::cout << "\n\nLet's iter double array =>" << std::endl;
	iter(dbArr, 3, printItem);

	std::cout << "\n\nLet's iter string array =>" << std::endl;
	iter(strArr, 6, printItem);
	
	return 0;
}
