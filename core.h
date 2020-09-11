#ifndef CORE_H
#define CORE_H
#include <ios>

class Game{

};

class MenuInterface{
public:
    MenuInterface() = default;
    ~MenuInterface() = default;
    MenuInterface(std::ostream display, std::istream input);
    void displayWelcome(std::string author, std::string title);
    void run();
};

#endif // CORE_H
