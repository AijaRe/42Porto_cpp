/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:16:32 by arepsa            #+#    #+#             */
/*   Updated: 2024/04/24 19:24:48 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
    _index = 0;
    _nbContacts = 0;
    return ;
}

PhoneBook::~PhoneBook(void){
    return ;
}

void PhoneBook::addContact(){
    int i;
    std::string firstName, lastName, nickname, phoneNb, secret;

    std::cout << "Your name: ";
    std::cin >> firstName;
    std::cout << "Your last name: ";
    std::cin >> lastName;
    std::cout << "Your nickname: ";
    std::cin >> nickname;
    std::cout << "Your phone number: ";
    std::cin >> phoneNb;
    std::cout << "Tell me your darkest secret: ";
    std::cin >> secret;

    i = this->_index;
    this->_contacts[i].setFirstName(firstName);
    this->_contacts[i].setLastName(lastName);
    this->_contacts[i].setNickname(nickname);
    this->_contacts[i].setPhoneNb(phoneNb);
    this->_contacts[i].setSecret(secret);
    this->_index = (i + 1) % 8;

    if (this->_nbContacts < 8)
        this->_nbContacts++;
}

static void displayPhoneBook(){
    std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void PhoneBook::displayContact(){
    std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|   Contact information for selected index  |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}
void PhoneBook::search(){ 
    displayPhoneBook();
    std::cout << "Search" << std::endl;
    int i;
    do {
        std::cout << "Insert index: ";
        std::cin >> i;
        if (i < 1 || i > this->_nbContacts){
            std::cout << "Invalid index" << std::endl;
            std::cin.clear();
        }
    } while (i < 1 || i > this->_nbContacts);
    
}
