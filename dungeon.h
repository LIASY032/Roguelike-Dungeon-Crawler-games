//#ifndef ROOM_H
//#define ROOM_H
//#include <iostream>
//#include <string>
//#include "item.h"
//#include "creature.h"

//using namespace creature;
//namespace dungeon {
//enum class Direction: unsigned{
//    North,
//    South,
//    East,
//    West
//};

//class Room
//{
//public:
//    Room() = default;
//    virtual ~Room() = default;
//    Room(int id);
//    std::string description();
//    virtual std::string* display() = 0; // need to be fixed return an Arrays
//    int id();
//    Item* item();
//    void setItem(Item &newItem);
//    AbstractCreature* creature();
//    void setCreature(AbstractCreature &newCreature);

//protected:
//    int _id;
//    Item* _item;
//    AbstractCreature* _creature;
//    std::string _description = "";

//};



////RoomEdge
//class RoomEdge{
//public:
//    RoomEdge() = default;
//    virtual ~RoomEdge() = default;
//    virtual std::string description() = 0;
//    virtual char displayCharacter() = 0;
//    bool isPassage();
//protected:
//    char character;

//    //store the condition of isPassage, set it fault
//    bool pass = false;

//    //set direction of the roomedge
//    Direction direction = Direction::North;
//};

////Doorway
//class Doorway : public RoomEdge{
//public:
//    Doorway() = default;
//    virtual void connect(Doorway &opposite);
//    std::string description() override;
//    bool isEntrance();
//    bool isExit();
//    int type();

//protected:
//    //store the connected doorway
//    Doorway* _doorway;

//    //the default of the doorway is not connected, entrance, and exit.
//    bool isConnected = false;
//    bool entrance = false;
//    bool exit = false;

//    //distinguish the type of doorway
//    int doorwayType = 0;

//    //description of the doorway
//    std::string _description;
//};


//namespace common {

////a concrete doorway implementation that cannot be entered from the room that contains it,
////but allows movement from the 'opposite' side which MUST be an OpenDoorway or LockedDoor
//class OneWayDoor: public Doorway{
//    OneWayDoor();
//    void connect(Doorway &opposite) override;
//};

////the standard concrete doorway implementation that
////allows unrestricted movement between rooms
//class OpenDoorway: public Doorway{
//    OpenDoorway();
//    void connect(Doorway &opposite) override;
//};

////a type of doorway that does not allow movement between rooms;
////the 'opposite' end of a BlockedDoorway MUST be another BlockedDoorway
//class BlockedDoorway: public Doorway{
//    BlockedDoorway();
//    void connect(Doorway &opposite) override;
//};

////a concrete doorway implementation that does not allow movement
////between rooms and can be 'unlocked' (if the gameplay were to be implemented)
//class LockedDoor: public Doorway{
//public:
//    LockedDoor();
//    void connect(Doorway &opposite) override;
//    void setlocked(bool locked);
//private:
//    bool _locked;
//};

//}
//class Wall: public RoomEdge{
//public:
//    Wall() = default;
//    virtual ~Wall() = default;
//    std::string description() override;
//    char displayCharacter() override;
//protected:
//    char _character = '|';
//    std::string _description;

//};


//class DungeonLevel{
//public:
//    DungeonLevel() = default;
//    virtual ~DungeonLevel() = default;
//    DungeonLevel(std::string name, int width, int height);
//    bool addRoom(Room room);
//    Room retrieveRoom(int number);
//    int width();
//    int height();
//    int numberOfRooms = 0;
//    std::string name();
//    virtual std::string description() = 0;
//    std::vector<std::string> display();

//};

//class DungeonLevelBuilder{
//public:
//    DungeonLevelBuilder() = default;
//    virtual ~DungeonLevelBuilder() = default;
//    void buildDungeonLevel(std::string name, int width, int height);
//    Room buildRoom(int id);
//    void buildDoorway(Room origin, Room destination);

//};

///**
// *core::dungeon::basic
// * the basic namespace contains BasicDungeonLevel, BasicDungeonLevelBuilder,
// * RockChamber, QuartzChamber, and RockWall
// */
//namespace basic {
//class BasicDungeonLevel: public DungeonLevel{

//    BasicDungeonLevel();
//    std::string description() override;
//};

//class BasicDungeonLevelBuilder: public DungeonLevelBuilder{
//    BasicDungeonLevelBuilder();

//};

//class RockChamber: public Room{
//    RockChamber();
//    RockChamber(int id);
//    std::string* display() override;

//};


//class QuartzChamber:public Room{

//    QuartzChamber();
//    QuartzChamber(int id);
//    std::string* display() override;
//};

//class RockWall: public Wall{
//    RockWall();
//};


//}

//namespace magical {

//class AlchemistsLaboratory: public Room{

//    AlchemistsLaboratory();
//    AlchemistsLaboratory(int id);
//    std::string * display() override;

//};

//class EnchantedLiboratory:public Room{

//    EnchantedLiboratory();
//    EnchantedLiboratory(int id);
//    std::string * display() override;
//};

//class MagicalDungeonLevel: public DungeonLevel{

//    MagicalDungeonLevel();
//    std::string description() override;
//};

//class MagicalDungeonLevelBuilder: public DungeonLevelBuilder{

//    MagicalDungeonLevelBuilder();

//};

//class MagicWall: public Wall{
//    MagicWall();
//};
//}

//}
//using namespace dungeon;

//class Game{
//private:
//    Game();
//    static Game* the_Instance;
//    std::shared_ptr<DungeonLevelBuilder> levelBuilder;
//public:
//    ~Game() = default;
//    static Game* instance();
//    void setDungeonType(DungeonLevelBuilder _levelBuilder);
//    void createExampleLevel();
//    void createRandomLevel(std::string name, int witch, int height);
//    void displayLevel();
//    double randomDouble();


//};

//class MenuInterface{
//public:
//    MenuInterface() = default;
//    ~MenuInterface() = default;
//    MenuInterface(std::ostream display, std::istream input);
//    void displayWelcome(std::string author, std::string title);
//    void run();
//};


//#endif // ROOM_H
