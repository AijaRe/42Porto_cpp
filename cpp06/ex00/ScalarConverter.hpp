/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:16:01 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/25 21:33:11 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>  //std::setprecision std::fixed
#include <string>
#include <cctype>   //isprint
#include <cstdlib>  //strtol strtof strtod
#include <sstream>  //stringstream
#include <climits>
#include <cerrno>

class ScalarConverter {
	public:
		static void convert(const std::string& str);
		
	private:
		// Private constructors and destructor to prevent instantiation
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter(void);
		ScalarConverter & operator=(const ScalarConverter &src);
		
		enum	Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

		// Helper functions
		static Type	getType(const std::string& str);
};

#endif // SCALARCONVERTER_HPP
