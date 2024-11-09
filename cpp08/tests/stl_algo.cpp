#include <iostream>
#include <list>
#include <algorithm>


void	printInt(int item) {
	std::cout << item << std::endl;
}

int main(void) {
	std::list<int>	lst;

	lst.push_back(10);
	lst.push_back(1);
	lst.push_back(21);
	lst.push_back(84);
	lst.push_back(42);
	
	for_each(lst.begin(), lst.end(), printInt);
	std::cout << std::endl;

	lst.sort();

	for_each(lst.begin(), lst.end(), printInt);
	std::cout << std::endl;

	return 0;
}

// c++ -Wall -Werror -Wextra -std=c++98 -fsanitize=address stl_algo.cpp
