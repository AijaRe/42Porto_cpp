# C++ - Module 03
## Inheritance

## General rules

- use C++98 standard
- headerfile for each class, no function implementation in headerfile
- using namespace <ns_name> and friend keywords is forbidden
- using the STL is forbidden (no Containers and no Algorithms)
- all classes must be designed in the Orthodox Canonical Form (containting default constructor, copy constructor, copy assignment operator, destructor)

Skills: inheritance, virtual inheritance, DDD (Dreadful Diamond on Derivation)

## Resources

[Diamond problem (multiple/virtual inheritance)](https://www.learncpp.com/cpp-tutorial/virtual-base-classes/?utm_content=cmp-true)

### ex00 - Aaaaand... OPEN!

Implement a class called ClapTrap that will have the following private attributes initialized to the values specified in brackets:
- Name, which is passed as parameter to a constructor
- Hit points (10), represent the health of the ClapTrap
- Energy points (10)
- Attack damage (0)
Add the following public member functions so the ClapTrap looks more realistic:
- ```void attack(const std::string& target);```
- ```void takeDamage(unsigned int amount);```
- ```void beRepaired(unsigned int amount);```

When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing cost 1 energy point each. ClapTrap can’t do anything if it has no hit points or energy points left.

In all of these member functions, you have to print a message to describe what happens. For example, the ```attack()``` function may display something like: ```ClapTrap <name> attacks <target>, causing <damage> points of damage!``` The constructors and destructor must also display a message.


### ex01 - Serena, my love!

Create a derived robot.
It will be named ScavTrap and will inherit the constructors and destructor from Clap-Trap.
However, its constructors, destructor and attack() will print different messages. After all, ClapTraps are aware of their individuality.

Proper construction/destruction chaining must be shown in your tests.

When a ScavTrap is created, the program starts by building a ClapTrap. Destruction is in reverse order.

ScavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and must initialize them to:
- Name, which is passed as parameter to a constructor
- Hit points (100), represent the health of the ClapTrap
- Energy points (50)
- Attack damage (20)
ScavTrap will also have its own special capacity: ```void guardGate();``` This member function will display a message informing that ScavTrap is now in Gate keeper mode.


### ex02 - Repetitive work

Implement a FragTrap class that inherits from ClapTrap. It is very similar to ScavTrap. However, its construction and destruction messages must be different. 

Proper construction/destruction chaining must be shown in your tests. When a FragTrap is created, the program starts by building a ClapTrap. Destruction is in reverse order. Same things for the attributes, but with different values this time:
- Name, which is passed as parameter to a constructor
- Hit points (100), represent the health of the ClapTrap
- Energy points (100)
- Attack damage (30)
FragTrap has a special capacity too: ```void highFivesGuys(void);``` This member function displays a positive high fives request on the standard output.


### ex03 - Now it’s weird!

In this exercise, you will create a monster: a ClapTrap that’s half FragTrap, half ScavTrap.

It will be named DiamondTrap, and it will inherit from both the FragTrap AND the ScavTrap. This is so risky!

The DiamondTrap class will have a name private attribute. Give to this attribute exactly the same variable’s name (not talking about the robot’s name here) than the one in the ClapTrap base class.

To be more clear, here are two examples.
If ClapTrap’s variable is name, give the name name to the one of the DiamondTrap.
If ClapTrap’s variable is _name, give the name _name to the one of the DiamondTrap.

Its attributes and member functions will be picked from either one of its parent classes:
- Name, which is passed as parameter to a constructor
- ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
- Hit points (FragTrap)
- Energy points (ScavTrap)
- Attack damage (FragTrap)
- attack() (Scavtrap)

In addition to the special functions of both its parent classes, DiamondTrap will have its own special capacity:
```void whoAmI();``` This member function will display both its name and its ClapTrap name.

The ClapTrap subobject of the DiamondTrap will be created once, and only once. Yes, there’s a trick.

