#!/bin/bash

read -p "Enter the class name: " className

hppFileName="$className.hpp"
cppFileName="$className.cpp"

# Check if header and source files already exist
if [ -f "$hppFileName" ] || [ -f "$cppFileName" ]; then
    echo "Files already exist: $hppFileName, $cppFileName"
    exit 1
fi

cat > "$hppFileName" <<EOF
#ifndef ${className^^}_HPP
#define ${className^^}_HPP

#include <iostream>

class $className {
    public:
        $className(void);
        $className(const $className &copy);
        ~$className(void);
        $className & operator=(const $className &src);
    private:
        // Private members
};

#endif // ${className^^}_HPP
EOF

cat > "$cppFileName" <<EOF
#include "$className.hpp"

$className::$className(void) {
    std::cout << "$className default constructor called." << std::endl;
}

$className::$className(const $className &copy) {
    std::cout << "$className copy constructor called." << std::endl;
    *this = copy;
}

$className::~$className(void) {
    std::cout << "$className destructor called." << std::endl;
}

$className & $className::operator=(const $className &src) {
    std::cout << "$className assignment operator called." << std::endl;
    if (this != &src) {
        // Implement assignment
    }
    return *this;
}
EOF

echo "Created files: $hppFileName, $cppFileName"
