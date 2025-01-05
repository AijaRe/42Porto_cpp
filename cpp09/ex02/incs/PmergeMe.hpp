#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <cstdlib> //strtol
#include <climits>
#include <algorithm>

class PmergeMe {
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &copy);
        ~PmergeMe(void);
        PmergeMe & operator=(const PmergeMe &src);

        void    inputToVector(int argc, char** argv);
        template <typename T>
        void    display(const T& container) const;
        void    sortVector();
        std::vector<int>    getVector() const;

    private:
        std::vector<int> _velements;
        
};

template <typename T>
void PmergeMe::display(const T& container) const {
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif // PMERGEME_HPP
