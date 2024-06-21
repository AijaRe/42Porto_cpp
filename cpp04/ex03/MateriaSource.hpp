#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

#define LEARN_SLOTS 4

class MateriaSource: public IMateriaSource {
    private:
        AMateria* _slots[LEARN_SLOTS];
    public:
        MateriaSource( void );
        MateriaSource( const MateriaSource &src );
        ~MateriaSource( void );
        MateriaSource & operator=( const MateriaSource &src );

        void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURCE_HPP
