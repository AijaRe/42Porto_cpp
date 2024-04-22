/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:38:42 by arepsa            #+#    #+#             */
/*   Updated: 2024/04/22 20:00:21 by arepsa           ###   ########.fr       */
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

bool Contact::isEmpty() const {
    return _firstName.empty() && _lastName.empty() && _nickname.empty() && _phoneNb.empty() && _secret.empty();
}
void Contact::setContactInfo(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& phoneNb, const std::string& secret) {
    _firstName = firstName;
    _lastName = lastName;
    _nickname = nickname;
    _phoneNb = phoneNb;
    _secret = secret;
}
