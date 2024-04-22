/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:16:32 by arepsa            #+#    #+#             */
/*   Updated: 2024/04/22 20:10:16 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
    _index = 0;
    return ;
}

PhoneBook::~PhoneBook(void){
    return ;
}

void PhoneBook::addContact(){
    std::string firstName, lastName, nickname, phoneNb, secret;
    std::cout << "Your name:" << std::endl;
    std::cin >> firstName;
    std::cout << "Your last name:" << std::endl;
    std::cin >> lastName;
    std::cout << "Your nickname:" << std::endl;
    std::cin >> nickname;
    std::cout << "Your phone number:" << std::endl;
    std::cin >> phoneNb;
    std::cout << "Tell me your darkest secret:" << std::endl;
    std::cin >> secret;

    while (_index < 8) {
        if (_contacts[_index].isEmpty()) {
            _contacts[_index].setContactInfo(firstName, lastName, nickname, phoneNb, secret);
            _index++;
            std::cout << "Contact added successfully." << std::endl;
            return;
        }
    }
}

static void displayHeader(){
    std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void PhoneBook::search(){ 
    displayHeader();
}
