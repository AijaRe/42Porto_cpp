#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
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

        void    parseInputVec(int argc, char** argv);
        void    parseInputDeq(int argc, char** argv);

        void    sortVector();
        void    sortDeque();

        std::vector<int>    getVector() const;
        std::deque<int>    getDeque() const;

        template <typename T>
        void    display(const T& container) const;

    private:
        std::vector<int> _velements;
        std::deque<int> _delements;

        std::vector<long> generateJacobsthalSequence(int n);
        template <typename T>
        void binarySearchInsert(T& cont, int element, size_t maxI);
        template <typename T>
        void insertByJacobsthal(T& mainChain, T& smallChain);
        template <typename T>
        void swapPairs(T& cont);
        template <typename T>
        T mergeInsertionSort(T& cont);
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
