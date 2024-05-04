/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:38:42 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/01 13:28:25 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//constructor
Contact::Contact(){
    return ;
}

//destructor
Contact::~Contact(){
    return ;
}

void    Contact::setFirstName(std::string firstName){
    this->_firstName = firstName;
}

void    Contact::setLastName(std::string lastName){
    this->_lastName = lastName;
}

void    Contact::setNickname(std::string nickname){
    this->_nickname = nickname;
}

void    Contact::setPhoneNb(std::string phoneNb){
    this->_phoneNb = phoneNb;
}

void    Contact::setSecret(std::string secret){
    this->_secret = secret;
}

const std::string   Contact::getFirstName(void) const{
    return this->_firstName;
}

const std::string   Contact::getLastName(void) const{
    return this->_lastName;
}

const std::string   Contact::getNickname(void) const{
    return this->_nickname;
}

const std::string   Contact::getPhoneNb(void) const{
    return this->_phoneNb;
}

const std::string   Contact::getSecret(void) const{
    return this->_secret;
}


