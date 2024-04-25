/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:16:46 by arepsa            #+#    #+#             */
/*   Updated: 2024/04/25 12:38:36 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cctype> //isdigit

class PhoneBook{
    private:
        Contact _contacts[8];
        int     _index;
        int     _nbContacts;
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        //int  getNbContacts(void) const;
        void readContact(void) const;
        void addContact(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& phoneNb, const std::string& secret);
        void search(void);
        void displayContact(int i) const;
        void displayPhoneBook(void) const;
};

#endif
