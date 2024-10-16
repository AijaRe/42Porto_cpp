/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:27:59 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/14 20:06:29 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib> //srand()
#include <ctime>   //time()
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
    private:
        std::string	_target;
    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm( std::string target );
        RobotomyRequestForm( const RobotomyRequestForm &copy );
        ~RobotomyRequestForm( void );
        RobotomyRequestForm & operator=( const RobotomyRequestForm &src );

        std::string	getTarget( void ) const;
		void		execute( Bureaucrat const &executor ) const;
};

// Stream operators
std::ostream & operator<<( std::ostream &out, const RobotomyRequestForm &rhs );

#endif // ROBOTOMYREQUESTFORM_HPP
