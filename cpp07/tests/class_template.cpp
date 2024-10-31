#include <iostream>

template<typename T>
class List {
	public:
		List<T>( T const& content) {}
		~List<T>() {}
		List<T>(List<T> const& src) {}
	private:
		T* _content;
		List<T>* _next;
};

//--------------------------------------------
int main(void) {
	List<int> 			list(42);
	List< List<int> >	list2(list); // List of lists
	return 0;
};
