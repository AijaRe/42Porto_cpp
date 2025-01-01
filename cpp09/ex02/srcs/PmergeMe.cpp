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

void recursiveMergeInsertionSort(std::vector<std::pair<int, int> >& pairs) {
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
}

void    PmergeMe::sortVector() {
    //arrange and sort pairs, e.g., 2 23 11 4 -> 2 23 4 11
   /*  for (size_t i = 0; i < _elements.size() - 1; i++) {
        if (_elements[i] > _elements[i + 1]) {
            std::swap(_elements[i], _elements[i + 1]);
        }
    } */
    //sort pairs by largest element, e.g., 2 23 4 11 -> 4 11 2 23
    // Group elements into pairs and sort them on the way (smaller, larger)
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _elements.size(); i += 2) {
        if (i + 1 < _elements.size()) {
            if (_elements[i] < _elements[i + 1]) {
                pairs.push_back(std::make_pair(_elements[i], _elements[i + 1]));
            } else {
                pairs.push_back(std::make_pair(_elements[i + 1], _elements[i]));
            }
        } else {
            // Handle unpaired element
            pairs.push_back(std::make_pair(_elements[i], _elements[i]));
        }
    }

    // Sort the pairs by recursively sorting the larger elements
    recursiveMergeInsertionSort(pairs);

     // Generate the Jacobsthal sequence for insertion 
     // (based on the number of even-position (smallest) elements)
    std::vector<long> jacobsthal = generateJacobsthalSequence(pairs.size());
    std::vector<long>::const_iterator it;
    std::cout << "Print jacobstahl: ";
    for (it = jacobsthal.begin(); it != jacobsthal.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Create main chain and populate with sorted large pair numbers
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].second);  // Larger element
    }

    // Create main chain and populate with sorted large pair numbers
    std::vector<int> smallChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);  // Smaller element
    }

    // Insert the elements of smallChain into mainChain
    // using Jacobsthal sequence binary search
       for (size_t i = 0; i < jacobsthal.size(); ++i) {
        size_t index = jacobsthal[i] - 1;
        if (index < smallChain.size()) {
            int element = smallChain[index];
            //insert element into mainChain using binary search
        }
    }

    _elements = mainChain;
    // Reconstruct the sorted vector
    /* _elements.clear();
    for (size_t i = 0; i < pairs.size(); ++i) {
        _elements.push_back(pairs[i].first);  // Smaller element
        _elements.push_back(pairs[i].second); // Larger element
    }
} */


