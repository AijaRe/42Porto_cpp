/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:54:15 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/19 20:49:10 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	printTitle(std::string title) {
	std::cout << std::endl;
	std::cout << BOLD << CYAN << LINE << std::endl;
    std::cout << "| " << title << std::endl;
    std::cout << LINE << RESET << std::endl;
}

template <typename T>
void	printMutantStack(MutantStack<T>& mstack, const std::string stackName){
	std::cout << "Print " + stackName + " stack :" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	subjectTest(void){
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
}

void	listTest(void){
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
}

void	copyConstructorTest(void){
	printTitle("TEST COPY CONSTRUCTOR");
	std::cout << "Creating stack that contains 21 and 42..." << std::endl;
	MutantStack<int> originalStack;
	originalStack.push(21);
	originalStack.push(42);

	std::cout << "Copying original stack..." << std::endl;
	MutantStack<int> copyStack(originalStack);
	
	std::cout << "Adding 84 to the original stack..." << std::endl;
	originalStack.push(84);

	printMutantStack(originalStack, "original");
	printMutantStack(copyStack, "copied");
}

void	assignmentOperatorTest(void){
	printTitle("TEST ASSIGNMENT OPERATOR");
	std::cout << "Creating stack that contains 21 and 42..." << std::endl;
	MutantStack<int> originalStack;
	originalStack.push(21);
	originalStack.push(42);

	std::cout << "Assigning original stack..." << std::endl;
	MutantStack<int> assignedStack;
	assignedStack = originalStack;
	
	std::cout << "Adding 84 to the original stack..." << std::endl;
	originalStack.push(84);

	printMutantStack(originalStack, "original");
	printMutantStack(assignedStack, "assigned");
}

int	main(void) {
	subjectTest();
	listTest();
	copyConstructorTest();
	assignmentOperatorTest();
	
	return 0;
}
