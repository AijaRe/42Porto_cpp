
//partial specialization - some of the types are defined/specialized
//full specialization - all types are defined/specialized

#include <iostream>

// General template definition
template<typename T1, typename T2>
class Pair {
public:
    Pair(T1 const& lhs, T2 const& rhs) : _lhs(lhs), _rhs(rhs) {
        std::cout << "General template" << std::endl;
    }
    ~Pair< T1, T2 >() {}

    T1 const& getLhs() const { return this->_lhs; }
    T2 const& getRhs() const { return this->_rhs; }

private:
    T1 _lhs;
    T2 const& _rhs;

	// Prevent default construction
	Pair< T1, T2 >();
};

// Partial specialization for int and T
template<typename T>
class Pair< int, T > {
	public:
		Pair< int, T >(int lhs, T const& rhs) : _lhs(lhs), _rhs(rhs) {
			std::cout << "Partial specialization" << std::endl;
			return ;
		}
		~Pair< int, T >() {}

		int getLhs() const { return this->_lhs; }
		T const& getRhs() const { return this->_rhs; }
	
	private:
		int _lhs;
		T const& _rhs;
		
		// Prevent default construction
		Pair< int, T >();
};


int main (void) {
	int lhs = 42;
    double rhs = 3.14;
    Pair<int, double> p(lhs, rhs);

    std::cout << "LHS: " << p.getLhs() << std::endl;
    std::cout << "RHS: " << p.getRhs() << std::endl;

	return 0;
}