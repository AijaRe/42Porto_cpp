/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:27:59 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/15 21:28:00 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>

class RobotomyRequestForm {
    private:
        // Private members
    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm( const RobotomyRequestForm &copy );
        ~RobotomyRequestForm( void );
        RobotomyRequestForm & operator=( const RobotomyRequestForm &src );
};

#endif // ROBOTOMYREQUESTFORM_HPP
