//#ifndef BASIC_H
//#define BASIC_H
//#include <iostream>
//#include "dungeon.h"
//#include "common.h"

//using namespace core;
//using namespace core::dungeon;
//using namespace core::dungeon::common;

//namespace core { namespace dungeon { namespace basic {
///**
// * @brief The RockWall class is inherited from Wall class.
// */
//class RockWall: public Wall{
//public:
//    RockWall();
//};
///**
// * @brief The RockChamber class is inherited from Room class.
// */
//class RockChamber: public Room{
//public:
//    RockChamber() = default;
//    RockChamber(int id);

//};

///**
// * @brief The QuartzChamber class is inherited from Room class.
// */
//class QuartzChamber:public Room{
//public:
//    QuartzChamber() = default;
//    QuartzChamber(int id);
//};

///**
// * @brief The BasicDungeonLevel class is inherited from DungeonLevel class.
// */
//class BasicDungeonLevel: public DungeonLevel{
//public:
//    BasicDungeonLevel() = default;
//    BasicDungeonLevel(std::string name, int width, int height);

//    /**
//     * @brief description
//     * @return a string that depicts the level size and the name
//     */
//    std::string description() override;
//};

//class BasicDungeonLevelBuilder: public DungeonLevelBuilder{
//public:
//    BasicDungeonLevelBuilder() = default;

//    /**
//     * @brief buildDungeonLevel: enter the name, width, and height to create a dungeon level
//     * @param name
//     * @param width
//     * @param height
//     */
//    void buildDungeonLevel(std::string name, int width, int height) override;

//    /**
//     * @brief buildRoom allows user to enter the id to create a new room
//     * @param id
//     * @return
//     */
//    Room* buildRoom(int id) override;

//    /**
//     * @brief buildEntrance builds a room for players to enter according to the direction
//     * @param room
//     * @param direction
//     */
//    void buildEntrance(Room &room, Direction direction) override;

//    /**
//     * @brief buildExit builds a room for exit according to the direction. It add a basic item and a basic monster to the room
//     * @param room
//     * @param direction
//     */
//    void buildExit(Room &room, Direction direction) override;

//    /**
//     * @brief buildItem adds a basic item to the room
//     * @param room
//     */
//    void buildItem(Room &room) override;

//    /**
//     * @brief buildCreature adds a basic monster to the room
//     * @param room
//     */
//    void buildCreature(Room &room) override;

//};

//} } }
//#endif // BASIC_H
