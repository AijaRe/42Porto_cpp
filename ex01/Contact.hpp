/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:38:58 by arepsa            #+#    #+#             */
/*   Updated: 2024/04/22 19:59:21 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

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
        bool isEmpty() const;
        void setContactInfo(const std::string& firstName, const std::string& lastName, const std::string& nickname, const std::string& phoneNb, const std::string& secret);
        
        
};

#endif
