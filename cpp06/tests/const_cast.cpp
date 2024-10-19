#include <iostream>

//necessity of using const_cast usually indicates a wrong design..
//avoid, better rewrite prog, unless calling someone elses code you cannot change

void print (char* str)
{
  std::cout << str << std::endl;
}

int main (void) {
	{
		const char* str = "Apples or oranges?";
		print ( const_cast<char *> (str) );
	}
	{
		int a = 42;

		const int ca = a;				//Implicit promotion - Ok
		const int* b = &a;				//Implicit promotion - Ok
		//int* c = b;					//Implicit demotion - No!!!
		int* d = const_cast<int*>(b);	//Explicit demotion - Ok, I obey
	}

  return 0;
}

//c++ -Wall -Wextra -Werror -Wno-unused -Wconversion -Werror const_cast.cpp