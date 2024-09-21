/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:27:53 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/15 22:11:45 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm( std::string target );
        PresidentialPardonForm( const PresidentialPardonForm &copy );
        ~PresidentialPardonForm( void );
        PresidentialPardonForm & operator=( const PresidentialPardonForm &src );
        
        std::string getTarget( void ) const;
        void        execute( Bureaucrat const &executor ) const;
        std::ostream & operator<<( std::ostream &out, const PresidentialPardonForm &rhs);
};

#endif // PRESIDENTIALPARDONFORM_HPP
