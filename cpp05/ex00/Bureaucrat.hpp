/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:14:29 by arepsa            #+#    #+#             */
/*   Updated: 2024/08/19 15:56:44 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		static const int LOWEST_GRADE = 150;
		static const int HIGHEST_GRADE = 1;

	public:
		// Constructors
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &copy );
		Bureaucrat( const std::string _name, int _grade );
		
		// Destructor
		~Bureaucrat( void );
		
		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};
		
		// Operators
		Bureaucrat & operator=( const Bureaucrat &assign );
		
		// Getters / Setters
		const std::string getName( void ) const;
		int getGrade( void ) const;
		void incrementGrade( void );
		void decrementGrade( void );
		
		
};

// Stream operators
std::ostream & operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif