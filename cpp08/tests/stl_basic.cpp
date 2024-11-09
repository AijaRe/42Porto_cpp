#include <iostream>
#include <map>
#include <vector>
#include <list>

int main(void){
	std::list<int>						lst1;
	std::map<int, std::string>	map1;
	std::vector<int>					vect1;
	// Initialize a vector with 12 elements, each initialized to 100
	std::vector<int>					vect2(12, 100);

	lst1.push_back(11);
	lst1.push_back(21);
	lst1.push_back(42);

	//map - key and value pairs
	map1[1] = "1st Value";
	map1[2] = "2nd value";

	// .begin() returns an iterator to the first element
    // Dereference the iterator to access the element
    std::cout << "list first element: " << *lst1.begin() << std::endl;
	
	//.end() is not the last element, but the position past the last element.
	std::list<int>::const_iterator		it;
	std::list<int>::const_iterator		itend = lst1.end();

	std::cout << "print list: " << *lst1.begin() << std::endl;
	for (it = lst1.begin(); it != itend; ++it) {
		std::cout << *it << std::endl;
	}

	std::vector<int>::const_iterator		itv;
	std::vector<int>::const_iterator		itvend = vect2.end();
	std::cout << "print vect2: " << *lst1.begin() << std::endl;
	for (itv = vect2.begin(); itv != itvend; ++itv) {
		std::cout << *itv << std::endl;
	}
	
    std::cout << "Print map:" << std::endl;
	std::map<int, std::string>::const_iterator		itmap;
	std::map<int, std::string>::const_iterator		itmapend = map1.end();
    for (itmap = map1.begin(); itmap != itmapend; ++itmap) {
        std::cout << itmap->first << ": " << itmap->second << std::endl;
    }

	return 0;
}

// c++ -Wall -Werror -Wextra -std=c++98 -fsanitize=address stl_basic.cpp