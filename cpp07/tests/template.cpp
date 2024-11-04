#include <iostream>

/* 
** T - global type (could be anything)
** pass references as parameters to save memory in case sending big class objects
** same for return type
** const because function is not supposed to change parameters
** since we return the same reference that entered as parameter, 
** return also has to be const
** possible to have several types of parameters: template<typename T, typename U>
*/
template<typename T>
T const& max(T const& x, T const& y){
	return (x >= y ? x : y);
}

int	foo(int x){
	std::cout << "Long compilation time" << std::endl;
	return x;
}

int main(void) {
	int a = 7;
	int b = 14;

	std::cout << "Max of " << a << " and " << b << " is: ";
	std::cout << max(a, b) << std::endl; // Implicit instantiation
	std::cout << "Max of " << a << " and " << b << " is: ";
	std::cout << max<int>(a, b) << std::endl; // Explicit instantiation

	int ret1 = max<int>(foo(a), foo(b)); // Explicit instantiation
	std::cout << "Max of " << a << " and " << b << " using functions is: ";
	std::cout << ret1 << std::endl;

	int ret2 = foo(max(a, b)); // Implicit instantiation
	return 0;
}