#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
    std::cout << "PmergeMe default constructor called." << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
    std::cout << "PmergeMe copy constructor called." << std::endl;
    *this = copy;
}

PmergeMe::~PmergeMe(void) {
    std::cout << "PmergeMe destructor called." << std::endl;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &src) {
    std::cout << "PmergeMe assignment operator called." << std::endl;
    if (this != &src) {
        _elements = src._elements;
    }
    return *this;
}

void PmergeMe::inputToVector(int argc, char** argv) {
     for (int i = 1; i < argc; i++) {
        char *end;
        long value = std::strtol(argv[i], &end, 10);
        if (*end != '\0' || value > INT_MAX || value < INT_MIN) {
            throw std::invalid_argument("Invalid number: " + std::string(argv[i]));
        }
        _elements.push_back(static_cast<int>(value));
    }
}

void PmergeMe::display() const {
    std::vector<int>::const_iterator it;
    for (it = _elements.begin(); it != _elements.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
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

//insert element into a vector using binary search
void    binarySearchInsert(std::vector<int>& vect, int element) {
    size_t left = 0;
    size_t right = vect.size();
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (element < vect[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    vect.insert(vect.begin() + left, element);
}


/* void recursiveMergeInsertionSort(std::vector<std::pair<int, int> >& pairs) {
    // Base case: A single pair or no pairs is already sorted.
    if (pairs.size() <= 1) {
        return; 
    }

    // Split pairs into two halves for sorting
    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + pairs.size() / 2);
    std::vector<std::pair<int, int> > right(pairs.begin() + pairs.size() / 2, pairs.end());

    // Recursive calls
    recursiveMergeInsertionSort(left);
    recursiveMergeInsertionSort(right);

    // Merge the two halves, sorted by the larger element in each pair
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].second < right[j].second) {
            pairs[k++] = left[i++];
        } else {
            pairs[k++] = right[j++];
        }
    }

    // Copy remaining elements
    while (i < left.size()) {
        pairs[k++] = left[i++];
    }
    while (j < right.size()) {
        pairs[k++] = right[j++];
    }
} */

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
        } else {
            // Handle unpaired element - same number for both elements
            pairs.push_back(std::make_pair(vect[i], vect[i]));
        }
    }
    return pairs;
}

std::vector<int>    mergeInsertSort(std::vector<int>& vect) {
    if (vect.size() <= 1) {
        return vect; 
    }
   
    std::vector<std::pair<int, int> > pairs = generatePairs(vect);

    // Create main chain and populate with sorted large pair numbers
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first != pairs[i].second) {
            mainChain.push_back(pairs[i].second);  // Larger element
        }  
    }
   
    // Sort the pairs by recursively sorting the larger elements
    mainChain = mergeInsertSort(mainChain);

    // Create small number chain and populate with smaller pair numbers
    std::vector<int> smallChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first != pairs[i].second) {
            smallChain.push_back(pairs[i].first);  // Smaller element
        }
    }

      // Insert the elements of smallChain into mainChain by simple binary search insert
    for (size_t i = 0; i < smallChain.size(); ++i) {
        binarySearchInsert(mainChain, smallChain[i]);
    }

    long unpairedElement = LONG_MAX;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first == pairs[i].second) {
            unpairedElement = pairs[i].first;
            break;
        }
    }
    
/*     // Generate the Jacobsthal sequence for insertion 
    // (based on the number of even-position (smallest) elements)
    std::vector<long> jacobsthal = generateJacobsthalSequence(smallChain.size());

    // Insert the elements of smallChain into mainChain
    // using Jacobsthal sequence binary search
    size_t lastInserted = 0;
    for (size_t i = 0; i < jacobsthal.size(); ++i) {
        size_t index = jacobsthal[i] - 1;
        if (index < smallChain.size()) {
            int element = smallChain[index];
            binarySearchInsert(mainChain, element);
            lastInserted = index;
        }
    } 

    // Insert the remaining elements of smallChain into mainChain
    for (size_t i = lastInserted + 1; i < smallChain.size(); ++i) {
        binarySearchInsert(mainChain, smallChain[i]);
    }*/
    
    // Insert the unpaired element if it exists
    if (unpairedElement != LONG_MAX) {
        binarySearchInsert(mainChain, static_cast<int>(unpairedElement));
    }
    
    return mainChain;
} 

void PmergeMe::sortVector() {
    _elements = mergeInsertSort(_elements);
}


