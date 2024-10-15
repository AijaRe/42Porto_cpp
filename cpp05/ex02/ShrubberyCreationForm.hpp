/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:28:05 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/15 20:28:51 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream> //ifstream/ofstream
#include <string> //c_str
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm &copy );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm & operator=( const ShrubberyCreationForm &src );
		
		std::string	getTarget( void ) const;
		void		execute( Bureaucrat const &executor ) const;
};

std::ostream & operator<<( std::ostream &out, const ShrubberyCreationForm &rhs );

#endif // SHRUBBERYCREATIONFORM_HPP
