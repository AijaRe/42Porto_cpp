
// C++ program to illustrate std::istringstream
#include <iostream>
#include <sstream>
#include <string>
 
// Driver Code
int main()
{
    // Input string
    std::string a("1 2 3");
 
    // Object class of istringstream
    std::istringstream my_stream(a);
 
    // Variable to store number n
    int n;
 
    // Stream a number till white space
    // is encountered
    my_stream >> n;
 
    // Print the number
    std::cout << n << "\n";
}
// output "1"