/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:16:46 by arepsa            #+#    #+#             */
/*   Updated: 2024/04/28 18:50:07 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <cctype> //std::isdigit
#include <limits> //std::numeric_limits
#include <sstream> //std::stoi

class PhoneBook{
    private:
        Contact _contacts[8];
        int     _index;
        int     _nbContacts;
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void addContact(void);
        void setContactData(const std::string& firstName, const std::string& lastName, \
            const std::string& nickname, const std::string& phoneNb, const std::string& secret);
        void search(void) const;
        void displayContact(int i) const;
        void displayPhoneBook(void) const;
};

#endif
