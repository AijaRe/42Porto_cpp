/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:37:39 by arepsa            #+#    #+#             */
/*   Updated: 2024/04/24 19:27:45 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


int main(){
    
    PhoneBook       phb;
    std::string    input;

    std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Welcome to My Awesome PhoneBook...    |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
    
    do {
        std::cout << "Choose an option > ADD - SEARCH - EXIT " << std::endl;
        std::cin >> input;
        if (input == "ADD")
            phb.addContact();
        else if (input == "SEARCH")
            phb.search();
        else if (input == "EXIT")
            break;
        if (std::cin.eof()) // ctrl + D
            return 0;
    } while (input != "EXIT");
    std::cout << "Closing PhoneBook..." << std::endl;
    return 0;
}
