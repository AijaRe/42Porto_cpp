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

/* // Generate pairs from a vector of integers
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
} */

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
void    binarySearchInsert(T& cont, int element, size_t maxI) {
    size_t min = 0;
    size_t max = std::min(maxI, cont.size());
    while (min < max) {
        size_t mid = min + (max - min) / 2;
        if (element < cont[mid]) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }
    //cont.insert(cont.begin() + min, element);
}

template <typename T>
void    insertByJacobsthal(T& mainChain, T& smallChain) {
    // Generate the Jacobsthal sequence for insertion 
    // (based on the number of even-position (smallest) elements)
    std::vector<long> jacobsthal = generateJacobsthalSequence(smallChain.size());

    // Insert the elements of smallChain into mainChain
    // using Jacobsthal sequence binary search
    size_t lastInsert = 0;
    size_t insertedElements = 0;
    int prevJacobsthal = 0;
    for (size_t i = 0; i < jacobsthal.size(); i++) {
        size_t currJacobsthal = jacobsthal[i];
        if (currJacobsthal <= smallChain.size()) {
            for (int j = currJacobsthal - 1; j >= prevJacobsthal; j--) {
                binarySearchInsert(mainChain, smallChain[j], insertedElements + currJacobsthal);
                insertedElements++;
            }
            prevJacobsthal = currJacobsthal;
        }
        lastInsert = currJacobsthal + insertedElements;
    }

    std::cout << "Last insert: " << lastInsert << std::endl;
    // Insert the remaining elements of smallChain into mainChain
    for (size_t i = prevJacobsthal; i < smallChain.size(); i++) {
        binarySearchInsert(mainChain, smallChain[i], lastInsert + 1);
        lastInsert++;
    } 

    // Print the main chain after jacobsathal insertion
    std::cout << "Main chain after Jacobsthal insertion: ";
    for (size_t i = 0; i < mainChain.size(); i++) {  
        std::cout << mainChain[i] << " ";
    }
    

}

// Sort a vector of integers by pairs, odd element smaller, even element larger
// e.g., 2 23 11 4 -> 2 23 4 11
void    swapVecPairs(std::vector<int>& vect) {
    for (size_t i = 0; i < vect.size() - 1; i+=2) {
        if (vect[i] > vect[i + 1]) {
            std::swap(vect[i], vect[i + 1]);
        }
    }
}

std::vector<int>    mergeInsertSortV(std::vector<int>& vect) {
    if (vect.size() <= 1) {
        return vect; 
    }
   
    swapVecPairs(vect);

    // Print sorted vector
    std::cout << "Sorted vector: ";
    for (size_t i = 0; i < vect.size(); i++) {  
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;

    // Create main chain and populate with sorted large pair numbers (even)
    // Create small chain and populate with smaller pair numbers (odd)
    std::vector<int> mainChain, smallChain;
    std::vector<size_t> smallIdx;
    for (size_t i = 0; i < vect.size() - 1; i += 2) {
        mainChain.push_back(vect[i + 1]);  // Larger element
        smallChain.push_back(vect[i]);  // Smaller element
        smallIdx.push_back(smallChain.size() - 1);
    }

    // Print main chain
    std::cout << "Main chain: ";
    for (size_t i = 0; i < mainChain.size(); i++) {  
        std::cout << mainChain[i] << " ";
    }
    std::cout << std::endl;

    // Handle unpaired element (if it exists)
    int unpairedElement = 0;
    bool unpaired = vect.size() % 2 != 0 ;
    if (unpaired) {
        std::cout << "Unpaired element: " << vect.back() << std::endl;
        unpairedElement = vect.back();
    }

    // Sort the pairs by recursively sorting the larger elements
    mainChain = mergeInsertSortV(mainChain);

    // Reorder the small chain based on the sorted main chain
    // mainChain[i] corresponds to vect[j * 2 + 1]
    std::vector<size_t> reorderedSmallIdx;
    for (size_t i = 0; i < mainChain.size(); i++) {
        for (size_t j = 0; j < mainChain.size(); j++) {
            if (mainChain[i] == vect[j * 2 + 1]) {
                reorderedSmallIdx.push_back(smallIdx[j]);
                break;
            }
        }
    }

    // Reorder the small chain based on the new small index
    std::vector<int> reorderedSmallChain(reorderedSmallIdx.size());
    for (size_t i = 0; i < reorderedSmallIdx.size(); i++) {
        reorderedSmallChain[i] = smallChain[reorderedSmallIdx[i]];
    }
    smallChain = reorderedSmallChain;

    if (smallChain.size() >= 3) {
        insertByJacobsthal(mainChain, smallChain);
        std::cout << std::endl;
    } else {
        for (size_t i = smallChain.size(); i > 0; i--) {
            binarySearchInsert(mainChain, smallChain[i - 1], mainChain.size());
        }
    }

    // Insert the unpaired element if it exists
    if (unpaired) {
        binarySearchInsert(mainChain, unpairedElement, mainChain.size());
    }

    // print final main chain
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
    std::cout << std::endl;
    
    return mainChain;
} 
/* 
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
            binarySearchInsert(mainChain, smallChain[i - 1], mainChain.size());
        }
    }
    
    // Insert the unpaired element if it exists
    if (unpaired) {
        binarySearchInsert(mainChain, unpairedElement, mainChain.size());
    }
    
    return mainChain;
}
 */
void PmergeMe::sortVector() {
    _velements = mergeInsertSortV(_velements);
}

/* void PmergeMe::sortDeque() {
    _delements = mergeInsertSortD(_delements);
} */
