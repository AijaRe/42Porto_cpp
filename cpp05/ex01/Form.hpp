/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:02:27 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/12 14:57:02 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	public:
		// Constructors
		Form( void );
		Form( const std::string name, int signGrade, int execGrade );
		Form( const Form &copy );
		
		// Destructor
		~Form( void );

		// Operators
		Form & operator=( const Form &src );
		
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
		
};

std::ostream & operator<<( std::ostream &out, const Form &rhs );

#endif // FORM_HPP
