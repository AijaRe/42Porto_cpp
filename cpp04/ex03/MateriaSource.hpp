#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>

class MateriaSource {
    private:
        // Private members
    public:
        MateriaSource( void );
        MateriaSource( const MateriaSource &src );
        ~MateriaSource( void );
        MateriaSource & operator=( const MateriaSource &src );
};

#endif // MATERIASOURCE_HPP
