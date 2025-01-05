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
        void    display() const;
        void    sortVector();
        std::vector<int>    getElements() const;

    private:
        std::vector<int> _elements;
        
};

#endif // PMERGEME_HPP
