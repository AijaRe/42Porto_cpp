/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:37:39 by arepsa            #+#    #+#             */
/*   Updated: 2024/04/20 14:08:31 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(){
    
    PhoneBook       phb;
    std::string    input;

    std::cout << "Welcome to My Awesome PhoneBook.." << std::endl;
    while (1)
    {
        std::cout << "PhoneBook > ADD - SEARCH - EXIT " << std::endl;
        std::cin >> input;
        if (input == "ADD")
            phb.addContact();
        else if (input == "SEARCH")
            phb.search();
        else if (input == "EXIT")
            break;
    }

    return 0;
}
