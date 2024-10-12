/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:28:05 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/12 15:48:55 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm {
	private:
		// Private members
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm &copy );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm & operator=( const ShrubberyCreationForm &src );
		
		//void	execute( Bureaucrat const &executor ) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP
