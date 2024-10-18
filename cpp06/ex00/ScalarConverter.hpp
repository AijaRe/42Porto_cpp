/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:16:01 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/18 19:58:20 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>

class ScalarConverter {
    private:
        // Private members
    public:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &copy);
        ~ScalarConverter(void);
        ScalarConverter & operator=(const ScalarConverter &src);

        static void convert(const std::string& str);
};

#endif // SCALARCONVERTER_HPP
