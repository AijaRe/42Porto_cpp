/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:54:15 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/17 11:13:51 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	printTitle(std::string title) {
	std::cout << std::endl;
	std::cout << BOLD << CYAN << LINE << std::endl;
    std::cout << "| " << title << std::endl;
    std::cout << LINE << RESET << std::endl;
}

int	main(void) {

	printTitle("SUBJECT TEST");
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element (expected 17): " << std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	 std::cout << "Size after pop (expected 1): " << std::endl;
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Elements in stack:" << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack); //create new stack object and initialize with contents of mstack
	
	printTitle("TEST WITH std::list");
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Top element (expected 17): " << std::endl;
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size after pop (expected 1): " << std::endl;
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	std::cout << "Elements in list:" << std::endl;
	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}
	
	return 0;
}
