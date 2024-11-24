/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:46:37 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/24 20:03:50 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>

class BitcoinExchange {
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(const BitcoinExchange &src);

		BitcoinExchange(std::ifstream& inputFile, std::ifstream& dataFile);
	private:
		// Private members
};

#endif // BITCOINEXCHANGE_HPP
