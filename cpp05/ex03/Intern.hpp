/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:11:32 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/16 11:15:43 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define FORM_COUNT 3

class Intern {
    private:
        // Private members
    public:
        Intern( void );
        Intern( const Intern &copy );
        ~Intern( void );
        Intern & operator=( const Intern &src );
        
        AForm * makeForm( const std::string formName, const std::string target );
};

#endif // INTERN_HPP
