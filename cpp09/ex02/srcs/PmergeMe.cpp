#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
    //std::cout << "PmergeMe default constructor called." << std::endl;
}

PmergeMe::PmergeMe(int argc, char** argv) {
    //std::cout << "PmergeMe constructor called." << std::endl;
    parseInput(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _velements(copy._velements), _delements(copy._delements) {
    //std::cout << "PmergeMe copy constructor called." << std::endl;
}

PmergeMe::~PmergeMe(void) {
    //std::cout << "PmergeMe destructor called." << std::endl;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &src) {
    //std::cout << "PmergeMe assignment operator called." << std::endl;
    if (this != &src) {
        _velements = src._velements;
        _delements = src._delements;
    }
    return *this;
}

std::vector<int> PmergeMe::getVector() const {
    return _velements;
}

std::deque<int> PmergeMe::getDeque() const {
    return _delements;
}

void PmergeMe::parseInput(int argc, char** argv) {
     for (int i = 1; i < argc; i++) {
        char *end;
        long value = std::strtol(argv[i], &end, 10);
        if (*end != '\0' || value > INT_MAX || value < 0) {
            throw std::invalid_argument("Invalid number: " + std::string(argv[i]));
        }
        //reject duplicates
        if (std::find(_velements.begin(), _velements.end(), static_cast<int>(value)) != _velements.end()) {
            throw std::invalid_argument("Duplicate number: " + std::string(argv[i]));
        }
        _velements.push_back(static_cast<int>(value));
        _delements.push_back(static_cast<int>(value));
    }
}

// Generate Jacobsthal's sequence starting from 3 up to a given size
std::vector<long> generateJacobsthalSequence(int n) {
    std::vector<long> jacobsthal;
    
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    long nextNumber = 5;
    for (size_t i = 3; nextNumber < n; i++) {
        jacobsthal.push_back(nextNumber);
        nextNumber = 2 * jacobsthal[i - 2] + jacobsthal[i - 1];
    }
    jacobsthal.erase(jacobsthal.begin());
    return jacobsthal;
}

//insert element into a vector/deque using binary search
template <typename T>
void    binarySearchInsert(T& cont, int element) {
    size_t left = 0;
    size_t right = cont.size();
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (element < cont[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cont.insert(cont.begin() + left, element);
}

// Generate pairs from a vector of integers
// where the first element is always smaller than the second
std::vector<std::pair<int, int> > generatePairs(std::vector<int>& vect) {
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vect.size(); i += 2) {
        if (i + 1 < vect.size()) {
            if (vect[i] < vect[i + 1]) {
                pairs.push_back(std::make_pair(vect[i], vect[i + 1]));
            } else {
                pairs.push_back(std::make_pair(vect[i + 1], vect[i]));
            }
        } 
    }
    return pairs;
}

// Generate pairs from a deque of integers
// where the first element is always smaller than the second
std::deque<std::pair<int, int> > generatePairsDeq(std::deque<int>& deq) {
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < deq.size(); i += 2) {
        if (i + 1 < deq.size()) {
            if (deq[i] < deq[i + 1]) {
                pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
            } else {
                pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
            }
        } 
    }
    return pairs;
}

template <typename T>
void    insertByJacobsthal(T& mainChain, T& smallChain) {
    // Generate the Jacobsthal sequence for insertion 
    // (based on the number of even-position (smallest) elements)
    std::vector<long> jacobsthal = generateJacobsthalSequence(smallChain.size());

    // Insert the elements of smallChain into mainChain
    // using Jacobsthal sequence binary search
    size_t lastInserted = 0;
    int prevJacobsthal = 0;
    for (size_t i = 0; i < jacobsthal.size(); i++) {
        size_t currJacobsthal = jacobsthal[i] - 1;
        if (currJacobsthal < smallChain.size()) {
            for (int j = currJacobsthal; j >= prevJacobsthal; j--) {
                binarySearchInsert(mainChain, smallChain[j]);
            }
            prevJacobsthal = currJacobsthal + 1;
        }
        lastInserted = currJacobsthal;
    }

    // Insert the remaining elements of smallChain into mainChain
    for (size_t i = smallChain.size() - 1; i > lastInserted; i--) {
        binarySearchInsert(mainChain, smallChain[i]);
    } 
}

std::vector<int>    mergeInsertSortV(std::vector<int>& vect) {
    if (vect.size() <= 1) {
        return vect; 
    }
   
    std::vector<std::pair<int, int> > pairs = generatePairs(vect);

    // Handle unpaired element (if it exists)
    int unpairedElement = 0;
    bool unpaired = vect.size() % 2 != 0 ;
    if (unpaired) {
        unpairedElement = vect.back();
    }
    // Create main chain and populate with sorted large pair numbers
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
            mainChain.push_back(pairs[i].second);  // Larger element
    }
   
    // Sort the pairs by recursively sorting the larger elements
    mainChain = mergeInsertSortV(mainChain);

    // Create small number chain and populate with smaller pair numbers
    std::vector<int> smallChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
            smallChain.push_back(pairs[i].first);  // Smaller element
    }

    if (smallChain.size() >= 3) {
        insertByJacobsthal(mainChain, smallChain);
    } else {
        for (size_t i = smallChain.size(); i > 0; i--) {
            binarySearchInsert(mainChain, smallChain[i - 1]);
        }
    }
    
    // Insert the unpaired element if it exists
    if (unpaired) {
        binarySearchInsert(mainChain, unpairedElement);
    }
    
    return mainChain;
} 

std::deque<int>    mergeInsertSortD(std::deque<int>& deq) {
    if (deq.size() <= 1) {
        return deq; 
    }
   
    std::deque<std::pair<int, int> > pairs = generatePairsDeq(deq);

    // Handle unpaired element (if it exists)
    int unpairedElement = 0;
    bool unpaired = deq.size() % 2 != 0 ;
    if (unpaired) {
        unpairedElement = deq.back();
    }
    // Create main chain and populate with sorted large pair numbers
    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
            mainChain.push_back(pairs[i].second);  // Larger element
    }
   
    // Sort the pairs by recursively sorting the larger elements
    mainChain = mergeInsertSortD(mainChain);

    // Create small number chain and populate with smaller pair numbers
    std::deque<int> smallChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
            smallChain.push_back(pairs[i].first);  // Smaller element
    }

    if (smallChain.size() >= 3) {
        insertByJacobsthal(mainChain, smallChain);
    } else {
        for (size_t i = smallChain.size(); i > 0; i--) {
            binarySearchInsert(mainChain, smallChain[i - 1]);
        }
    }
    
    // Insert the unpaired element if it exists
    if (unpaired) {
        binarySearchInsert(mainChain, unpairedElement);
    }
    
    return mainChain;
}

void PmergeMe::sortVector() {
    _velements = mergeInsertSortV(_velements);
}

void PmergeMe::sortDeque() {
    _delements = mergeInsertSortD(_delements);
}
