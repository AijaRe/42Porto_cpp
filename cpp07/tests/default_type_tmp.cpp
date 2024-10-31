#include <iostream>
#include <iomanip>

template< typename T = float > // Default type is float

class Vertex {
	public:
		Vertex(T const& x, T const& y, T const& z) : _x(x), _y(y), _z(z) {}
		~Vertex() {}
		Vertex(Vertex const& src) : _x(src._x), _y(src._y), _z(src._z) {}
		
		T const& getX() const { return this->_x; }
		T const& getY() const { return this->_y; }
		T const& getZ() const { return this->_z; }

	private:
		T const _x;
		T const _y;
		T const _z;

		Vertex( void );
};

template< typename T >
std::ostream& operator<<(std::ostream& o, Vertex<T> const& src) {
	o << std::fixed << std::setprecision(2);
	o << "Vertex(" << src.getX() << ", " << src.getY() << ", " << src.getZ() << ")";
	return o;
}

int main(void) {
	Vertex<int>		vertex1(42, 42, 42);
	Vertex<float>	vertex2(42.4222f, 42.4222f, 42.4222f);
	Vertex<>		vertex3(24.24, 24.24, 24.24); // Default type is float
	Vertex<>		vertex4(24, 24, 24); // Default type is float

	std::cout << vertex1 << std::endl;
	std::cout << vertex2 << std::endl;
	std::cout << vertex3 << std::endl;
	std::cout << vertex4 << std::endl;
	return 0;
}
