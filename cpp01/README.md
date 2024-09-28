# C++ - Module 01
## Memory allocation, pointers to members, references, switch statement

## General rules

- use C++98 standard
- headerfile for each class, no function implementation in headerfile
- using namespace <ns_name> and friend keywords is forbidden
- using the STL is forbidden (no Containers and no Algorithms)


### ex00 - BraiiiiiiinnnzzzZ

Implement a Zombie class. It has a string private attribute name.
Add a member function ```void announce( void );``` to the Zombie class. Zombies
announce themselves as follows:
<name>: BraiiiiiiinnnzzzZ.

Implement the two following functions:
-  ```Zombie* newZombie( std::string name );```
    
    It creates a zombie, name it, and return it so you can use it outside of the function
scope.

- ```void randomChump( std::string name );```
    
    It creates a zombie, name it, and the zombie announces itself.

Skills: differentiate between heap and stack allocation, memory management.


### ex01 - Moar brainz!

Create a horde of Zombies!
Implement the following function in the appropriate file:
```Zombie* zombieHorde( int N, std::string name );```

It must allocate N Zombie objects in a single allocation. Then, it has to initialize the
zombies, giving each one of them the name passed as parameter. The function returns a
pointer to the first zombie.

Skills: create an array of objects, memory management.


### ex02 - HI THIS IS BRAIN

Write a program that contains:
- A string variable initialized to "HI THIS IS BRAIN".
- stringPTR: A pointer to the string.
- stringREF: A reference to the string.
Your program has to print:
- The memory address of the string variable, stringPTR and stringREF.
And then:
- The value of the string variable, stringPTR, stringREF.

Skills: pointer and reference syntax.


### ex03 - Unnecessary violence

Implement a Weapon class that has:
- A private attribute type, which is a string.
- A ```getType()``` member function that returns a const reference to type.
- A ```setType()``` member function that sets type using the new one passed as parameter.

Create two classes: HumanA and HumanB. They both have a Weapon and a
name. They also have a member function ```attack()``` that displays:
<name> attacks with their <weapon type>.

HumanA and HumanB are almost the same except for these two tiny details:
- While HumanA takes the Weapon in its constructor, HumanB doesn’t.
- HumanB may not always have a Weapon, whereas HumanA will always be armed.

Skills: apply pointer and reference usage, memory management.


### ex04 - Sed is for losers

Create a program that takes three parameters in the following order: a filename and two strings, s1 and s2.

It will open the file <filename> and copies its content into a new file <filename>.replace, replacing every occurrence of s1 with s2.

All the member functions of the class std::string are allowed, except replace.

Skills: filestream usage, error management.


### ex05 - Harl 2.0

Harl is a very particular individual and has different messages for DEBUG, INFO, WARNING and ERROR.

Create a Harl class with the following private member functions:

```void debug( void );```

```void info( void );```

```void warning( void );```

```void error( void );```

Harl also has a public member function that calls the four member functions above depending on the level passed as parameter:
```void complain( std::string level );```

Skills: pointers to member functions.


### ex06 - Harl filter


Implement a system to filter what Harl says depending on the log levels you want to listen to.

Create a program that takes as parameter one of the four levels. It will display all messages from this level and above. For example "Warning" has to display "Warning" and "Error" messages.

Skills: switch statement (with intentional fallthrough).

