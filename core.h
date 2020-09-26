#ifndef CORE_H
#define CORE_H
#include <ios>

#include<stdio.h>
#include<ctype.h>
#include <random>
#include <ctime>
#include "dungeon.h"
#include <iostream>



using namespace core::dungeon::items;
using namespace core::dungeon;
using namespace core::dungeon::basic;
using namespace core::dungeon::common;
using namespace core::dungeon::magical;


namespace core {
/**
 * @brief The Game class use singleton design pattern
 * it can randomly generate magical or basic level
 */
class Game{
private:
    Game() = default;
    static Game* the_Instance;

    //becasue the relationship of the game and dungeonlevelBuilder is association, use share pointer
    std::shared_ptr<DungeonLevelBuilder> levelBuilder = 0;
    DungeonLevel* level = 0;
public:
    ~Game() = default;
    static Game* instance();

    /**
     * @brief setDungeonType set the level of the builder
     * @param _levelBuilder
     */
    void setDungeonType(DungeonLevelBuilder &_levelBuilder);

    /**
     * @brief createExampleLevel create a example level
     */
    void createExampleLevel();

    /**
     * @brief createRandomLevel generate a random level
     * @param name
     * @param witch
     * @param height
     */
    void createRandomLevel(std::string name, int witch, int height);

    /**
     * @brief displayLevel display the level
     * @param display
     */
    void displayLevel(std::ostream &display);

    /**
     * @brief randomDouble generate a double number between 0 - 5
     * @return
     */
    double randomDouble();

    /**
     * @brief constraintHelper help the createRandomLevel to create the doorway
     * @param origin
     * @param destination
     * @param direction
     * @param number
     */
    void constraintHelper(Room &origin, Room &destination, Direction direction, int number);

    /**
     * @brief descriptionLevel describes the level
     * @param display
     */
    void descriptionLevel(std::ostream &display);

    /**
     * @brief getLevel
     * @return the level
     */
    DungeonLevel* getLevel();

};

class MenuInterface{
public:
    MenuInterface() = default;
    ~MenuInterface() = default;
    MenuInterface(std::ostream &display, std::istream &input);

    /**
     * @brief displayWelcome displays welcome messages
     * @param author = liasy032
     * @param title = Dungeon Builder
     */
    void displayWelcome(std::string author = "liasy032", std::string title = "Dungeon Builder");

    /**
     * @brief run the game
     */
    void run();
private:
    /**
     * @brief isNumber checks the string is a number
     * @param input
     * @return true if this string is a number
     */
    bool isNumber(std::string &input);

    /**
     * @brief viewMenu help run() function to display view menu
     * @param display
     * @param input
     */
    void viewMenu(std::ostream &display, std::istream &input);

};

}
#endif // CORE_H
