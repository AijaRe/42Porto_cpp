/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:46:37 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/25 21:22:29 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(const BitcoinExchange &src);

		BitcoinExchange(std::ifstream& dataFile);
	private:
		std::map<std::string, double> _exchangeRates;
};

#endif // BITCOINEXCHANGE_HPP
