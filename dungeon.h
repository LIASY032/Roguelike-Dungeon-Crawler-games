#ifndef DUNGEON_H
#define DUNGEON_H
#include "item.h"
#include "creature.h"
#include <iostream>
#include <vector>
#include "basic.h"
#include "common.h"
#include "magical.h"
#include<stdio.h>
#include<ctype.h>
#include <random>
#include <ctime>




namespace core { namespace dungeon {
namespace items{

/**
 * @brief The Item class is a super class. It uses prototype pattern.
 */
class Item
{
protected:
    //store a name
    std::string _name = " ";
public:
    Item() = default;
    /**
     * @brief Item gets a name
     * @param name
     */
    Item(std::string name);
    virtual ~Item() = default;

    /**
     * @brief clone the weapen or consumable
     * @return an Item
     */
    virtual Item* clone() = 0;

    /**
     * @brief name
     * @return its name
     */
    std::string name();

    /**
     * @brief displayCharacter
     * @return a char 'L'
     */
    char displayCharacter();
protected:
    char _character = ' ';

};

class Weapon : public Item{
public:
    Weapon() = default;
    Weapon(std::string name);

    /**
     * @brief clone copy this class data and return it
     * @return weapen
     */
    Item* clone() override;

};


class Consumable: public Item{
public:
    Consumable() = default;
    Consumable(std::string name);
    /**
     * @brief clone copy this class data and return it
     * @return consumable
     */
    Item* clone() override;

};
}
namespace creatures{
class AbstractCreature{
public:
    AbstractCreature() = default;
    AbstractCreature(std::string name);
    AbstractCreature(std::string name, bool boss);
    virtual ~AbstractCreature() = default;
    virtual AbstractCreature* clone() = 0;
    virtual AbstractCreature* clone(bool boss) = 0;
    virtual std::string name() = 0;
    char displayCharacter();
    bool getBoss();
    void setBoss(bool _boss);
protected:
    std::string _name;
    bool boss = false;
    char _character ='M';
};

class Monster : public AbstractCreature{
public:
    Monster() = default;
    Monster(std::string name);
    Monster(std::string name, bool boss);
    AbstractCreature* clone() override;
    AbstractCreature* clone(bool boss) override;
    std::string name() override;

};


}
enum class Direction: unsigned{
    North,
    South,
    East,
    West
};

/**
 * @brief The RoomEdge class is a super class
 */
class RoomEdge{
public:
    RoomEdge() = default;
    virtual ~RoomEdge() = default;

    /**
     * @brief description
     * @return a string that describe the direction of the doorway or the wall
     */
    std::string description();

    /**
     * @brief displayCharacter
     * @return a char that represents the wall or a doorway
     */
    char displayCharacter();

    /**
     * @brief isPassage: the wall is not passage, the doorway is passage
     * @return a boolean that check this is a wall or a doorway
     */
    bool isPassage();

    /**
     * @brief setDirection set a direction of this roomedge
     * @param _direction
     */
    virtual void setDirection(Direction _direction) = 0;

    /**
     * @brief getDirection
     * @return the direction of this roomedge
     */
    Direction getDirection();
protected:
    //set the char of the roomEdge is ' '
    char character = ' ';

    //store the condition of isPassage, set it false
    bool pass = false;

    //set direction of the roomedge
    Direction direction = Direction::North;

    //store the description of the roomedge
    std::string _description;
};

/**
 * @brief The Doorway class is a super class
 */
class Doorway : public RoomEdge{
public:
    Doorway() = default;

    /**
     * @brief connect the opposite doorway and according the type of doorway to modify self character
     * @param opposite doorway
     */
    virtual void connect(Doorway &opposite) = 0;

    /**
     * @brief isEntrance
     * @return the boolean that the doorway can be entered
     */
    bool isEntrance();

    /**
     * @brief isExit
     * @return the boolean that the doorway can be exited
     */
    bool isExit();

    /**
     * @brief type
     * @return type of the doorway
     */
    int type();

    /**
     * @brief setDirection set the direction of the doorway
     * @param _direction
     */
    virtual void setDirection(Direction _direction) override = 0;

protected:
    //store the connected doorway
    Doorway* _doorway = 0;

    //the default of the doorway is not connected, entrance, and exit.
    bool isConnected = false;
    bool entrance = false;
    bool exit = false;

    //distinguish the type of doorway
    int doorwayType = 0;



};

/**
 * @brief The Wall class is a super class
 */
class Wall: public RoomEdge{
public:
    Wall() = default;
    virtual ~Wall() = default;
    void setDirection(Direction _direction) override;


};
using namespace items;
using namespace creatures;
/**
 * @brief The Room class is super class
 */
class Room
{
public:
    Room() = default;
    virtual ~Room() = default;

    /**
     * @brief Room create a new room
     * @param id
     */
    Room(int id);

    /**
     * @brief description
     * @return a string the describe the conditions of this room
     */
    std::string description();

    /**
     * @brief display the room that consists the character from other classes
     * @return vector that the length is 6
     */
    std::vector<std::string>* display();

    /**
     * @brief id
     * @return the id of this room
     */
    int id();

    /**
     * @brief item
     * @return the item of this room
     */
    Item* item();

    /**
     * @brief setItem set the item to this room
     * @param newItem
     */
    void setItem(Item &newItem);

    /**
     * @brief creature
     * @return abstract creature of this room
     */
    AbstractCreature* creature();

    /**
     * @brief setCreature set the creature to this room
     * @param newCreature
     */
    void setCreature(AbstractCreature &newCreature);

    /**
     * @brief setNorthEdge set the north edge
     * @param edge
     */
    void setNorthEdge(RoomEdge &edge);

    /**
     * @brief setSouthEdge set the South edge
     * @param edge
     */
    void setSouthEdge(RoomEdge &edge);

    /**
     * @brief setEastEdge set the East edge
     * @param edge
     */
    void setEastEdge(RoomEdge &edge);

    /**
     * @brief setWestEdge set the West edge
     * @param edge
     */
    void setWestEdge(RoomEdge &edge);

    /**
     * @brief getEdge
     * @return room edge according to the direction
     */
    RoomEdge* getNorthEdge();
    RoomEdge* getSouthEdge();
    RoomEdge* getEastEdge();
    RoomEdge* getWestEdge();


protected:
    //store the room id
    int _id;

    Item* _item = 0;
    AbstractCreature* _creature = 0;
    std::string _description = "";
    RoomEdge* northEdge = 0;
    RoomEdge* southEdge = 0;
    RoomEdge* eastEdge = 0;
    RoomEdge* westEdge = 0;

    //store the display
    std::vector<std::string> _output;

};



class DungeonLevel{
public:
    DungeonLevel() = default;
    virtual ~DungeonLevel() = default;

    DungeonLevel(std::string name, int width, int height);

    /**
     * @brief addRoom add a room to the level
     * @param room
     * @return true when the level is added a room
     */
    bool addRoom(Room &room);

    /**
     * @brief retrieveRoom retrieve a room in level
     * @param number represents the id
     * @return a room that is according to the id
     */
    Room* retrieveRoom(int number);


    int width();
    int height();
    int numberOfRooms = _width * _height;
    std::string name();

    /**
     * @brief description
     * @return the decription of the level
     */
    virtual std::string description() = 0;

    /**
     * @brief display the level consists the chars that represent roomedge, creaturem and items
     * @return vector consist 6 string
     */
    std::vector<std::string>* display();
    int number();

    /**
     * @brief initializeRoom create a level, each room's edges are wall
     * @param room
     */
    void initializeRoom(Room &room);
protected:
    std::string _name;
    int _width = 0;
    int _height = 0;
    int _number = 0;

    //for display function to return it
    std::vector<std::string> _display{};

    //for addRoom function
    int index = 0;

    //for initializeRoom function
    int initializedIndex = 0;
    std::vector<std::unique_ptr<Room>> rooms;
    std::string _description = "";

};

/**
 * @brief The DungeonLevelBuilder class builds a level
 */

class DungeonLevelBuilder{
public:
    enum class MoveConstraints: unsigned{
        None = 0,
        OriginImpassable = 1,
        DestinationImpassable = 2,
        OriginLocked = 4,
        Destinationlocked = 8
    };
    DungeonLevelBuilder() = default;
    virtual ~DungeonLevelBuilder() = default;

    /**
     * @brief buildDungeonLevel create a new level accoding to the subclass
     * @param name
     * @param width
     * @param height
     */
    virtual void buildDungeonLevel(std::string name, int width, int height) = 0;
    virtual Room* buildRoom(int id) = 0;
    void buildDoorway(Room &origin, Room &destination, Direction direction, DungeonLevelBuilder::MoveConstraints constraints);
    virtual void buildEntrance(Room &room, Direction direction) = 0;
    virtual void buildExit(Room &room, Direction direction) = 0;
    virtual void buildItem(Room &room) = 0;
    virtual void buildCreature(Room &room) = 0;
    void buildDoorwayHelper(Room &origin, Room &destination, Doorway &originEdge, Doorway &destinationEdge, Direction direction);

    DungeonLevel* getDungeonLevel();
    int generateRandomNumber(int number);
protected:

    Direction reverseDirection(Direction direction);

    DungeonLevel* level = 0;

    //initialzies creatures and items
    Consumable hpotion{"Health Potion"};
    Consumable cocktail{"Molotov Cocktail"};
    Consumable rpotion{"Resistance potion"};
    Weapon boomerang{"Boomerang"};
    Weapon staff{"Wizard's Staff"};
    Weapon wand{"Magic Wand"};
    Consumable bomb{"Smoke Bomb"};
    Weapon sword{"Short Sword"};
    Weapon axe{"Battle Axe"};
    Monster goblin{"Goblin"};
    Monster werewolf{"Werewolf"};
    Monster wizard{"Evil Wizard"};
    Monster dragon{"Dragon"};

};


namespace common {
/**
 * @brief The OneWayDoor class is a concrete doorway implementation that cannot be entered from the room that contains it,
but allows movement from the 'opposite' side which MUST be an OpenDoorway or LockedDoor
 */
class OneWayDoor:public core::dungeon::Doorway{
public:
    OneWayDoor();
    /**
     * @brief connect to open doorway or loecked doorway
     * @param opposite
     */
    void connect(Doorway &opposite) override;
    void setDirection(Direction _direction) override;
};

/**
 * @brief The OpenDoorway class is the standard concrete doorway implementation that
allows unrestricted movement between rooms
 */
class OpenDoorway: public Doorway{
public:
    OpenDoorway();
    /**
     * @brief connect to oneway doorway or locked doorway
     * @param opposite
     */
    void connect(Doorway &opposite) override;
    void setDirection(Direction _direction) override;
};

/**
 * @brief The BlockedDoorway class is a type of doorway that does not allow movement between rooms;
the 'opposite' end of a BlockedDoorway MUST be another BlockedDoorway
 */
class BlockedDoorway: public Doorway{
public:
    BlockedDoorway();
    void connect(Doorway &opposite) override;
    void setDirection(Direction _direction) override;
};

/**
 * @brief The LockedDoor class is a concrete doorway implementation that does not allow movement
between rooms and can be 'unlocked' (if the gameplay were to be implemented)
 */
class LockedDoor: public Doorway{
public:
    LockedDoor();

    /**
     * @brief connect to open doorway or oneway doorway
     * @param opposite
     */
    void connect(Doorway &opposite) override;

    /**
     * @brief setlocked set the condition of the lockedDoor
     * @param locked
     */
    void setlocked(bool locked);

    void setDirection(Direction _direction) override;

private:
    bool _locked;
};




}

namespace basic {
/**
 * @brief The RockWall class is inherited from Wall class.
 */
class RockWall: public Wall{
public:
    RockWall();
};
/**
 * @brief The RockChamber class is inherited from Room class.
 */
class RockChamber: public Room{
public:
    RockChamber() = default;
    RockChamber(int id);

};

/**
 * @brief The QuartzChamber class is inherited from Room class.
 */
class QuartzChamber:public Room{
public:
    QuartzChamber() = default;
    QuartzChamber(int id);
};

/**
 * @brief The BasicDungeonLevel class is inherited from DungeonLevel class.
 */
class BasicDungeonLevel: public DungeonLevel{
public:
    BasicDungeonLevel() = default;
    BasicDungeonLevel(std::string name, int width, int height);

    /**
     * @brief description
     * @return a string that depicts the level size and the name
     */
    std::string description() override;
};

class BasicDungeonLevelBuilder: public DungeonLevelBuilder{
public:
    BasicDungeonLevelBuilder() = default;

    /**
     * @brief buildDungeonLevel: enter the name, width, and height to create a dungeon level
     * @param name
     * @param width
     * @param height
     */
    void buildDungeonLevel(std::string name, int width, int height) override;

    /**
     * @brief buildRoom allows user to enter the id to create a new room
     * @param id
     * @return
     */
    Room* buildRoom(int id) override;

    /**
     * @brief buildEntrance builds a room for players to enter according to the direction
     * @param room
     * @param direction
     */
    void buildEntrance(Room &room, Direction direction) override;

    /**
     * @brief buildExit builds a room for exit according to the direction. It add a basic item and a basic monster to the room
     * @param room
     * @param direction
     */
    void buildExit(Room &room, Direction direction) override;

    /**
     * @brief buildItem adds a basic item to the room
     * @param room
     */
    void buildItem(Room &room) override;

    /**
     * @brief buildCreature adds a basic monster to the room
     * @param room
     */
    void buildCreature(Room &room) override;

};

}
namespace magical {

/**
 * @brief The MagicWall class is inherited from Wall class.
 */
class MagicWall: public Wall{
public:
    MagicWall();
};

/**
 * @brief The AlchemistsLaboratory class is inherited from Room class.
 */

class AlchemistsLaboratory: public Room{
public:
    AlchemistsLaboratory() = default;
    AlchemistsLaboratory(int id);

};

/**
 * @brief The EnchantedLiboratory class is inherited from Room class.
 */
class EnchantedLiboratory: public Room{
public:
    EnchantedLiboratory() = default;
    EnchantedLiboratory(int id);
};

/**
 * @brief The MagicalDungeonLevel class is inherited from DungeonLevel class.
 */
class MagicalDungeonLevel: public DungeonLevel{
public:
    MagicalDungeonLevel() = default;
    MagicalDungeonLevel(std::string name, int width, int height);

    /**
     * @brief description
     * @return a string that depicts the level size and the name
     */
    std::string description() override;
};

/**
 * @brief The MagicalDungeonLevelBuilder class is inherited from DungeonLevelBuilder class.
 */
class MagicalDungeonLevelBuilder: public DungeonLevelBuilder{
public:
    MagicalDungeonLevelBuilder() = default;
    /**
     * @brief buildDungeonLevel: enter the name, width, and height to create a dungeon level
     * @param name
     * @param width
     * @param height
     */
    void buildDungeonLevel(std::string name, int width, int height) override;

    /**
     * @brief buildRoom allows user to enter the id to create a new room
     * @param id
     * @return a room address
     */
    Room* buildRoom(int id) override;

    /**
     * @brief buildEntrance builds a room for players to enter according to the direction
     * @param room
     * @param direction
     */
    void buildEntrance(Room &room, Direction direction) override;

    /**
     * @brief buildExit builds a room for exit according to the direction. It add a magical item and a magical monster to the room
     * @param room
     * @param direction
     */
    void buildExit(Room &room, Direction direction) override;

    /**
     * @brief buildItem adds a magical item to the room
     * @param room
     */
    void buildItem(Room &room) override;

    /**
     * @brief buildCreature adds a magical monster to the room
     * @param room
     */
    void buildCreature(Room &room) override;

};
}
}

}


#endif // DUNGEON_H
