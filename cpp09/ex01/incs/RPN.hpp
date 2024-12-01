/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:51:02 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/01 21:36:45 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <climits>
#include <cstdlib>

class RPN {
    public:
        RPN(void);
        RPN(const RPN& copy);
        ~RPN(void);
        RPN & operator=(const RPN& src);

        void processInput(std::string& input);
        long calculate(long num1, long num2, char op);
    private:
        std::stack<long> _stack;
        void    validateInput(std::string& input);
        bool    isTokenNumber(const std::string& token);
};

#endif // RPN_HPP
