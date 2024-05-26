#include <iostream>

class Number {
	private:
		int _n;
	public:
		//Number( void );
		//~Number( void );
		Number( int num );
		void	setNum( int num );
		int		getNum( void ) const;
		Number 	operator+( const Number &numB ) const;
		Number 	&operator=( const Number &numB);
		bool	operator==( const Number &numB ) const;
};

std::ostream	&operator<<( std::ostream &o, const Number &num);

/* output class contents as string */
std::ostream	&operator<<( std::ostream &out, const Number &num){
	out << num.getNum();
	return out;
}

Number::Number(int num){
	this->_n = num;
}

void	Number::setNum(int num){
	this->_n = num;
	return ;
}

int		Number::getNum( void ) const{
	return this->_n;
}

/* 
** this -> on the left side of operator
** parameter (numB) -> on the right side of operator
*/
Number 	Number::operator+(const Number &numB) const{
	std::cout << "this->_n: " << this->_n << std::endl;
	std::cout << "numB._n: " << numB.getNum() << std::endl; 
	return Number( this->_n + numB.getNum() );
}

Number	&Number::operator=(const Number &numB){
	this->_n = numB.getNum();
	return *this;
}

bool	Number::operator==( const Number &numB ) const {
	if (this->_n == numB.getNum())
		return true;
	else
		return false;
}

int		main(){
	Number a(5);
	Number b(10);

	Number c = a + b;
	std::cout << "c._n: " << c << std::endl;

	a = c;

	if (a == c)
		std::cout << "a == c: " << a << std::endl;
	else	
		std::cout << "a != c" << std::endl;

	return 0;
}