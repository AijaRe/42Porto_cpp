/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:16:46 by arepsa            #+#    #+#             */
/*   Updated: 2024/04/24 19:24:49 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
    private:
        Contact _contacts[8];
        int     _index;
        int     _nbContacts;
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        //int  getNbContacts(void) const;
        void addContact(void);
        void search(void);
        void displayContact(void);
};

#endif
