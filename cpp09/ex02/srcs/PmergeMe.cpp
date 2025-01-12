#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
    //std::cout << "PmergeMe default constructor called." << std::endl;
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

void PmergeMe::parseInputVec(int argc, char** argv) {
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
    }
}

void PmergeMe::parseInputDeq(int argc, char** argv) {
     for (int i = 1; i < argc; i++) {
        char *end;
        long value = std::strtol(argv[i], &end, 10);
        if (*end != '\0' || value > INT_MAX || value < 0) {
            throw std::invalid_argument("Invalid number: " + std::string(argv[i]));
        }
        //reject duplicates
        if (std::find(_delements.begin(), _delements.end(), static_cast<int>(value)) != _delements.end()) {
            throw std::invalid_argument("Duplicate number: " + std::string(argv[i]));
        }
        _delements.push_back(static_cast<int>(value));
    }
}

// Generate Jacobsthal's sequence starting from 3 up to a given size
std::vector<long> PmergeMe::generateJacobsthalSequence(int n) {
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
void    PmergeMe::binarySearchInsert(T& cont, int element, size_t maxI) {
    size_t min = 0;
    size_t max = std::min(maxI, cont.size());
    size_t mid = 0;
    while (min < max) {
        mid = min + (max - min) / 2;
        if (element < cont[mid]) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }
    cont.insert(cont.begin() + min, element);
}

template <typename T>
void    PmergeMe::insertByJacobsthal(T& mainChain, T& smallChain) {

    // Generate the Jacobsthal sequence for insertion 
    // (based on the number of even-position (smallest) elements)
    std::vector<long> jacobsthal = generateJacobsthalSequence(smallChain.size());

    // Insert the first element of smallChain directly at the beginning of mainChain
    binarySearchInsert(mainChain, smallChain[0], 0);
    size_t insertedElements = 1;
    int prevJacobsthal = 1;

    // Insert the elements of smallChain into mainChain
    // using Jacobsthal sequence binary search
    for (size_t i = 0; i < jacobsthal.size(); i++) {
        size_t currJacobsthal = jacobsthal[i];
        if (currJacobsthal <= smallChain.size()) {
            for (int j = currJacobsthal - 1; j >= prevJacobsthal; j--) {
                binarySearchInsert(mainChain, smallChain[j], insertedElements + currJacobsthal);
                insertedElements++;
            }
            prevJacobsthal = currJacobsthal;
        }
    }

    // Insert the remaining elements of smallChain into mainChain
    for (size_t i = prevJacobsthal; i < smallChain.size(); i++) {
        binarySearchInsert(mainChain, smallChain[i], insertedElements + i);
        insertedElements++;
    } 

}

// Sort a chain of integers by pairs, odd element smaller, even element larger
// e.g., 2 23 11 4 -> 2 23 4 11
template <typename T>
void    PmergeMe::swapPairs(T& cont) {
    for (size_t i = 0; i < cont.size() - 1; i+=2) {
        if (cont[i] > cont[i + 1]) {
            std::swap(cont[i], cont[i + 1]);
        }
    }
}

template <typename T>
T    PmergeMe::mergeInsertionSort(T& cont) {
    if (cont.size() <= 1) {
        return cont; 
    }
   
    swapPairs(cont);

    // Create main chain and populate with sorted large pair numbers (even)
    // Create small chain and populate with smaller pair numbers (odd)
    T mainChain, smallChain;
    T smallIdx;
    for (size_t i = 0; i < cont.size() - 1; i += 2) {
        mainChain.push_back(cont[i + 1]);  // Larger element
        smallChain.push_back(cont[i]);  // Smaller element
        smallIdx.push_back(smallChain.size() - 1);
    }

    // Handle unpaired element (if it exists)
    int unpairedElement = 0;
    bool unpaired = cont.size() % 2 != 0 ;
    if (unpaired) {
        unpairedElement = cont.back();
    }

    // Sort the pairs by recursively sorting the larger elements
    mainChain = mergeInsertionSort(mainChain);

    // Reorder the small chain based on the sorted main chain
    T reorderedSmallIdx;
    for (size_t i = 0; i < mainChain.size(); i++) {
        for (size_t j = 0; j < mainChain.size(); j++) {
            if (mainChain[i] == cont[j * 2 + 1]) {
                reorderedSmallIdx.push_back(smallIdx[j]);
                break;
            }
        }
    }

    // Reorder the small chain based on the new small index
    T reorderedSmallChain(reorderedSmallIdx.size());
    for (size_t i = 0; i < reorderedSmallIdx.size(); i++) {
        reorderedSmallChain[i] = smallChain[reorderedSmallIdx[i]];
    }
    smallChain = reorderedSmallChain;

    insertByJacobsthal(mainChain, smallChain);

    // Insert the unpaired element if it exists
    if (unpaired) {
        binarySearchInsert(mainChain, unpairedElement, mainChain.size());
    }

    /*  // print final main chain
    std::cout << "Final main chain: ";
    for (size_t i = 0; i < mainChain.size(); i++) {  
        std::cout << mainChain[i] << " ";
    }
    std::cout << std::endl;
    // print final small chain
    std::cout << "Final small chain: ";
    for (size_t i = 0; i < smallChain.size(); i++) {  
        std::cout << smallChain[i] << " ";
    }
    std::cout << std::endl; */
    
    return mainChain;
} 

void PmergeMe::sortVector() {
    _velements = mergeInsertionSort(_velements);
}

 void PmergeMe::sortDeque() {
    _delements = mergeInsertionSort(_delements);
}
