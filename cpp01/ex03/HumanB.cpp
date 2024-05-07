#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
    std::cout << "HumanB default constructor called." << std::endl;
}

HumanB::~HumanB(void) {
    std::cout << "HumanB destructor called." << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon){
    this->_weapon = &weapon;
}

/* protect attack in case of NULL pointer for weapon */
void    HumanB::attack(void){
    if (this->_weapon) {
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    }
    else
        std::cout << this->_name << " can only attack with personal charm. No weapon detected." << std::endl;
}
