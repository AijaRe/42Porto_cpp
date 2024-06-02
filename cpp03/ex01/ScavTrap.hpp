#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
    // Private members
public:
    ScavTrap( void );
    ScavTrap( std::string name );
    ScavTrap( const ScavTrap &src );
    ~ScavTrap( void );
    ScavTrap & operator=( const ScavTrap &src );

    void    guardGate( void );
};

std::ostream	&operator<<( std::ostream &out, const ScavTrap &rhs);

#endif // SCAVTRAP_HPP
