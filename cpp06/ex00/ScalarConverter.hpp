/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:16:01 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/21 20:23:31 by arepsa           ###   ########.fr       */
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
		
		enum	Type { CHAR, INT, FLOAT, DOUBLE,/*  PSEUDO, */ INVALID };

		// Helper functions
		static Type	getType(const std::string& str);
		static void		printConverter(Type type, int precision, char c, int n, float f, double d);
};

#endif // SCALARCONVERTER_HPP
