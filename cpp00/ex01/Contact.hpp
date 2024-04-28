/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:38:58 by arepsa            #+#    #+#             */
/*   Updated: 2024/04/28 18:52:02 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <cstdlib> //exit
#include <csignal> //signal handling
#include <string> //find_first_not_of
#include <iomanip> //setw

class Contact{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNb;
        std::string _secret;
    public:
        Contact();
        ~Contact();
        void setFirstName(std::string firstName);
        void setLastName(std::string lastName);
        void setNickname(std::string nickname);
        void setPhoneNb(std::string phoneNb);
        void setSecret(std::string secret);
        const std::string getFirstName(void) const;
        const std::string getLastName(void) const;
        const std::string getNickname(void) const;
        const std::string getPhoneNb(void) const;
        const std::string getSecret(void) const;
};

#endif
