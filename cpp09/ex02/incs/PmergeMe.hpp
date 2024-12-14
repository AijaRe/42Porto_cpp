#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

class PmergeMe {
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &copy);
        ~PmergeMe(void);
        PmergeMe & operator=(const PmergeMe &src);
    private:
        // Private members
};

#endif // PMERGEME_HPP
