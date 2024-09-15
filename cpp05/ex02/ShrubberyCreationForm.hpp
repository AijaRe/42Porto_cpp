/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:28:05 by arepsa            #+#    #+#             */
/*   Updated: 2024/09/15 21:28:06 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>

class ShrubberyCreationForm {
    private:
        // Private members
    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( const ShrubberyCreationForm &copy );
        ~ShrubberyCreationForm( void );
        ShrubberyCreationForm & operator=( const ShrubberyCreationForm &src );
};

#endif // SHRUBBERYCREATIONFORM_HPP
