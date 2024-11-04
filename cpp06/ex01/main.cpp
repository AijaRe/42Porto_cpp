/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:51:00 by arepsa            #+#    #+#             */
/*   Updated: 2024/10/28 19:32:29 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

void    printData (Data* data) {
	std::cout << "Number: " << data->number << std::endl;
	std::cout << "Symbol: " << data->symbol << std::endl;
	std::cout << "Name: " << data->name << std::endl;
	
}

int	main(void) {

	Data object = { 42, '*', "Arthur" };

	std::cout << "--------Print original object--------" << std::endl;
	printData(&object);
	std::cout << "\n----Print original object pointer----" << std::endl;
	std::cout << "pointer: " << &object << std::endl;
	
	uintptr_t raw = Serializer::serialize(&object);
	std::cout << "\n----------Print raw pointer----------" << std::endl;
	std::cout << "----converted from hex to decimal----" << std::endl;
	std::cout << "uintptr_t: " << raw << std::endl;
	
	Data* deserializedObject = Serializer::deserialize(raw);
	std::cout << "\n------Print deserialized object-----" << std::endl;
	printData(deserializedObject);
	std::cout << "\n-----Print deserialized pointer-----" << std::endl;
	std::cout << "pointer: " << deserializedObject << std::endl;
	
	
	return 0;
}
