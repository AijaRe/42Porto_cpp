/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:02:27 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/12 15:07:42 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	public:
		// Constructors
		AForm( void );
		AForm( const std::string name, int signGrade, int execGrade );
		AForm( const AForm &copy );
		
		// Destructor
		~AForm( void );

		// Operators
		AForm & operator=( const AForm &src );
		
		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

		// Getters / Setters
		const std::string	getName( void ) const;
		bool				getSigned( void ) const;
		int					getSignGrade( void ) const;
		int					getExecGrade( void ) const;

		// Member functions
		void				beSigned( const Bureaucrat &bureaucrat );
		
		//pure virtual function, implemented differently in each concrete class
		virtual void		execute( Bureaucrat const &executor ) const = 0;	
};

std::ostream & operator<<( std::ostream &out, const AForm &rhs );

#endif // AFORM_HPP
