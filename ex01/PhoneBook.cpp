/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:16:32 by arepsa            #+#    #+#             */
/*   Updated: 2024/04/25 12:37:57 by arepsa           ###   ########.fr       */
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

static bool  is_valid_number(std::string& number){
    for (size_t i = 0; i < number.length(); ++i) {
        if (number[i] == ' ') {
            continue;
        }
        if (!isdigit(number[i])) {
            return false; 
        }
    }
    return true; 
}

void PhoneBook::addContact(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& phoneNb, const std::string& secret){
    int i = this->_index;
    
    this->_contacts[i].setFirstName(firstName);
    this->_contacts[i].setLastName(lastName);
    this->_contacts[i].setNickname(nickname);
    this->_contacts[i].setPhoneNb(phoneNb);
    this->_contacts[i].setSecret(secret);
    
    this->_index = (i + 1) % 8;

    if (this->_nbContacts < 8)
        this->_nbContacts++;
}

void PhoneBook::readContact() const{
    std::string firstName, lastName, nickname, phoneNb, secret;

    do {
        std::cout << "Your name: ";
        if (!(std::cin >> firstName)) break;
        std::cout << "Your last name: ";
        if (!(std::cin >> lastName)) break;
        std::cout << "Your nickname: ";
        if (!(std::cin >> nickname)) break;
        do {
            std::cout << "Your phone number: ";
            if (!(std::cin >> phoneNb)) break;
            if (is_valid_number(phoneNb))
                break;
            std::cout << "Phone number must conatin only digits. Try again!" << std::endl;
        } while (!is_valid_number(phoneNb));
        std::cout << "Tell me your darkest secret: ";
        if (!(std::cin >> secret)) break;
    } while (firstName.empty() || lastName.empty() || nickname.empty() || phoneNb.empty() || secret.empty());

    if (std::cin.eof()){
        exit(130);
    }
    addContact(firstName, lastName, nickname, phoneNb, secret);
}

std::string truncate_data(std::string data){
    if (data.length() > 10)
    {
        data[9] = '.';
        return data.substr(0, 10);
    }
    return data;
}

void    PhoneBook::displayPhoneBook() const{
    std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
    if (this->_nbContacts == 0)
	{
		std::cout << "No contacts saved yet." << std::endl;
		return;
	}
    for (int i = 0; i < this->_nbContacts; i++)
    {
        std::cout << '|' << std::right << std::setw(10) << i + 1 << '|' \
        << std::right << std::setw(10) << truncate_data(this->_contacts[i].getFirstName()) << '|' \
        << std::right << std::setw(10) << truncate_data(this->_contacts[i].getLastName()) << '|' \
        << std::right << std::setw(10) << truncate_data(this->_contacts[i].getNickname()) << '|' << std::endl;
    }
}

void PhoneBook::displayContact(int i) const{
    std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|   Contact information for selected index  |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
    
    std::cout << "First Name: " << this->_contacts[i].getFirstName() << std::endl;
    std::cout << "Last Name: " << this->_contacts[i].getLastName() << std::endl;
    std::cout << "Nickame: " << this->_contacts[i].getNickname() << std::endl;
    std::cout << "Phone nb.: " << this->_contacts[i].getPhoneNb() << std::endl;
    std::cout << "Darkest Secret: " << this->_contacts[i].getSecret() << std::endl;
}

void PhoneBook::search(){ 
    displayPhoneBook();
    int i;
    do {
        std::cout << "Insert index: ";
        std::cin >> i;
        if (std::cin.eof())
            exit(130);
        if (std::cin.fail() || i < 1 || i > this->_nbContacts){
            std::cout << "Invalid index" << std::endl;
            //std::cin.clear();
        }
        displayContact(i - 1);
    } while (i < 1 || i > this->_nbContacts);
    
}
