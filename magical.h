//#ifndef MAGICAL_H
//#define MAGICAL_H
//#include <iostream>
//#include "dungeon.h"
//#include "core.h"
//#include "item.h"
//#include "common.h"

//using namespace core;
//using namespace core::dungeon;
//using namespace core::dungeon::items;
//using namespace core::dungeon::common;

//namespace core { namespace dungeon { namespace magical {

///**
// * @brief The MagicWall class is inherited from Wall class.
// */
//class MagicWall: public Wall{
//public:
//    MagicWall();
//};

///**
// * @brief The AlchemistsLaboratory class is inherited from Room class.
// */

//class AlchemistsLaboratory: public Room{
//public:
//    AlchemistsLaboratory() = default;
//    AlchemistsLaboratory(int id);

//};

///**
// * @brief The EnchantedLiboratory class is inherited from Room class.
// */
//class EnchantedLiboratory: public Room{
//public:
//    EnchantedLiboratory() = default;
//    EnchantedLiboratory(int id);
//};

///**
// * @brief The MagicalDungeonLevel class is inherited from DungeonLevel class.
// */
//class MagicalDungeonLevel: public DungeonLevel{
//public:
//    MagicalDungeonLevel() = default;
//    MagicalDungeonLevel(std::string name, int width, int height);

//    /**
//     * @brief description
//     * @return a string that depicts the level size and the name
//     */
//    std::string description() override;
//};

///**
// * @brief The MagicalDungeonLevelBuilder class is inherited from DungeonLevelBuilder class.
// */
//class MagicalDungeonLevelBuilder: public DungeonLevelBuilder{
//public:
//    MagicalDungeonLevelBuilder() = default;
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
//     * @return a room address
//     */
//    Room* buildRoom(int id) override;

//    /**
//     * @brief buildEntrance builds a room for players to enter according to the direction
//     * @param room
//     * @param direction
//     */
//    void buildEntrance(Room &room, Direction direction) override;

//    /**
//     * @brief buildExit builds a room for exit according to the direction. It add a magical item and a magical monster to the room
//     * @param room
//     * @param direction
//     */
//    void buildExit(Room &room, Direction direction) override;

//    /**
//     * @brief buildItem adds a magical item to the room
//     * @param room
//     */
//    void buildItem(Room &room) override;

//    /**
//     * @brief buildCreature adds a magical monster to the room
//     * @param room
//     */
//    void buildCreature(Room &room) override;

//};
//} } }
//#endif // MAGICAL_H
