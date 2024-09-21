/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:14:29 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/15 21:26:39 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define BOLD    "\033[1m"
#define ARROW "=> "

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		static const int LOWEST_GRADE = 150;
		static const int HIGHEST_GRADE = 1;
		// Constructors
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &copy );
		Bureaucrat( const std::string _name, int _grade );
		
		// Destructor
		~Bureaucrat( void );
		
		// Operators
		Bureaucrat & operator=( const Bureaucrat &assign );
		
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
		const std::string getName( void ) const;
		int getGrade( void ) const;
		
		// Member functions
		void	incrementGrade( void );
		void	decrementGrade( void );
		void	signForm( AForm &form );
		void	executeForm( AForm const & form );
};

// Stream operators
std::ostream & operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif