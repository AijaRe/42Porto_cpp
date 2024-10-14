/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:27:53 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/14 20:06:21 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string	_target;
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm &copy );
		~PresidentialPardonForm( void );
		PresidentialPardonForm & operator=( const PresidentialPardonForm &src );
		
		std::string	getTarget( void ) const;
		void		execute( Bureaucrat const &executor ) const;
		
};

// Stream operators
std::ostream & operator<<( std::ostream &out, const PresidentialPardonForm &rhs );

#endif // PRESIDENTIALPARDONFORM_HPP
