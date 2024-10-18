/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:17:39 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/18 20:00:22 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
    if (argc != 2)
    {
        std::cout << "Program usage: ./convert <arg>" << std::endl;
        return 1;
    }
    
    std::string arg = argv[1];
    
    if (arg.empty())
    {
        std::cout << "Error: empty argument" << std::endl;
        return 2;
    }
    
    ScalarConverter::convert(arg);

    return 0;
}
