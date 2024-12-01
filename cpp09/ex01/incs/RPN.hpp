/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:51:02 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/01 12:51:03 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>

class RPN {
    public:
        RPN(void);
        RPN(const RPN &copy);
        ~RPN(void);
        RPN & operator=(const RPN &src);
    private:
        // Private members
};

#endif // RPN_HPP
