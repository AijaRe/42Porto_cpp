/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:28:02 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/15 21:10:32 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

static const char *ASCII_TREE = 
"\n"
"         ,ccee88oo.      \n"
"     ,C8O8O8Q8PoOb o8oo  \n"
"  dOB69\\8PdUOpugaO/bD@. \n"
"  CgggbU8OU qOp qO/oUOdcb\n"
"      6OuU  /p u gcoUodpP\n"
"         \\\\//  /douUP  \n"
"          |||||          \n"
"          |||||          \n"
"          |||||          \n"
"        ,\\\\\\/_//.      \n";

ShrubberyCreationForm::ShrubberyCreationForm( void ) 
    : AForm("ShrubberyCreation", 145, 137), _target("notarget") {
    //std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) 
    : AForm("ShrubberyCreation", 145, 137), _target(target) {
    //std::cout << "ShrubberyCreationForm assignment constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &copy ) 
    : AForm(copy), _target(copy._target) {
    //std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
    //std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src ) {
    //std::cout << "ShrubberyCreationForm assignment operator called." << std::endl;
    if (this != &src) {
        AForm::operator=(src);
        this->_target = src._target;
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget( void ) const {
    return this->_target;
}

void    ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
    AForm::execute(executor);
    
    std::string filename = this->getTarget() + "_shrubbery";
    std::ofstream	outfile(filename.c_str());
    if (!outfile)
			throw std::runtime_error("Error: Could not create output file.");
	outfile << ASCII_TREE << std::endl;
	outfile.close();
}

std::ostream & operator<<( std::ostream &out, const ShrubberyCreationForm &rhs ) {
    out << static_cast<const AForm&>(rhs);
    out << "Target: " << rhs.getTarget() << std::endl;
    return out;
}
