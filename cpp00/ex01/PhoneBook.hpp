/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:16:46 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/01 13:26:27 by arepsa           ###   ########.fr       */
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
        void    displayContact(int i) const;
        void    displayPhoneBook(void) const;
        void    setContactData(const std::string& firstName, const std::string& lastName, \
            const std::string& nickname, const std::string& phoneNb, const std::string& secret);
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    addContact(void);
        void    search(void) const;
};

#endif
