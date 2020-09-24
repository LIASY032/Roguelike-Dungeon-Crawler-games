#ifndef CORE_H
#define CORE_H
#include <ios>
#include "dungeonlevelbuilder.h"
#include<stdio.h>
#include<ctype.h>
class Game{
private:
    Game() = default;
    static Game* the_Instance;
    std::shared_ptr<DungeonLevelBuilder> levelBuilder = 0;
    DungeonLevel* level = 0;
public:
    ~Game() = default;
    static Game* instance();
    void setDungeonType(DungeonLevelBuilder &_levelBuilder);
    void createExampleLevel();
    void createRandomLevel(std::string name, int witch, int height);
    void displayLevel(std::ostream &display);
    double randomDouble();
    void constraintHelper(Room &origin, Room &destination, Direction direction, int number);

};

class MenuInterface{
public:
    MenuInterface() = default;
    ~MenuInterface() = default;
    MenuInterface(std::ostream &display, std::istream &input);
    void displayWelcome(std::string author = "liasy032", std::string title = "Dungeon Builder");
    void run();
private:

    DungeonLevelBuilder* builder = 0;
};

#endif // CORE_H
