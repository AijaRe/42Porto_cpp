/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:14:29 by arepsa            #+#    #+#             */
/*   Updated: 2024/08/03 16:24:50 by arepsa           ###   ########.fr       */
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

	public:
		// Constructors
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &copy );
		Bureaucrat( const std::string _name, int _grade );
		
		// Destructor
		~Bureaucrat( void );
		
		// Operators
		Bureaucrat & operator=( const Bureaucrat &assign );
		
		// Getters / Setters
		const std::string getName( void ) const;
		int getGrade( void ) const;
		
		
};

// Stream operators
std::ostream & operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif