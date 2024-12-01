/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:51:02 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/01 20:40:33 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
    public:
        RPN(void);
        RPN(const RPN& copy);
        ~RPN(void);
        RPN & operator=(const RPN& src);

        void processInput(std::string& input);
    private:
        std::stack<int> _stack;
        void    validateInput(std::string& input);
};

#endif // RPN_HPP
