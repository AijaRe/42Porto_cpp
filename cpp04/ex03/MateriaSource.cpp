#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
    std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &src ) {
    std::cout << "MateriaSource copy constructor called." << std::endl;
    *this = src;
}

MateriaSource::~MateriaSource( void ) {
    std::cout << "MateriaSource destructor called." << std::endl;
}

MateriaSource & MateriaSource::operator=( const MateriaSource &src ) {
    std::cout << "MateriaSource assignment operator called." << std::endl;
    if (this != &src) {
        // Implement assignment
    }
    return *this;
}

void    MateriaSource::learnMateria(AMateria* m) {
    (void) m;
    return ;
}
AMateria*   MateriaSource::createMateria(std::string const & type){
    (void) type;
    return ;
}
