#include <iostream>
#include <string>
#include <map>
#include "SSPlayer.hpp"



int main() {
    // Map from string (name) to Person struct
    std::map<std::string, command> command;

    // Insert values
    command["Alice"] = {25, "Engineer",10};
    command["Bob"]   = {30, "Designer",10.1};
    command["Charlie"] = {28, "Teacher",12};

    // Access and print values
    for (const auto& [name, command] : command) {
        std::cout << name << " is " << command.age << command.test
                  << " years old and works as a "
                  << command.occupation << "." << std::endl;
    }

    return 0;
}
