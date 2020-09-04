#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include "item.h"
#include "creature.h"
using namespace creature;
namespace dungeon {
enum class Direction: unsigned{
    North,
    South,
    East,
    West
};

class Room
{
public:
    Room() = default;
    virtual ~Room() = default;
    Room(int id);
    virtual std::string description() = 0;
    virtual std::string display() = 0; // need to be fixed return an Arrays
    int id();
    Item* item();
    void setItem(Item &newItem);
    AbstractCreature* creature();
    void setCreature(AbstractCreature &newCreature);

protected:
    int _id;
    Item* _item;
    AbstractCreature* _creature;

};

class RockChamber: public Room{
    RockChamber();
    RockChamber(int id);
    std::string description() override;
    std::string display() override;

};

//RoomEdge
class RoomEdge{
public:
    RoomEdge() = default;
    virtual ~RoomEdge() = 0;
    virtual std::string description() = 0;
    virtual char displayCharacter() = 0;
    bool isPassage();
protected:
    char character;

    //store the condition of isPassage, set it fault
    bool pass = false;
};

//Doorway
class Doorway : public RoomEdge{
public:
    Doorway() = default;
    virtual void connect(Doorway &opposite);
    std::string description() override;
    bool isEntrance();
    bool isExit();
    int type();

protected:
    //store the connected doorway
    Doorway* _doorway;

    //the default of the doorway is not connected, entrance, and exit.
    bool isConnected = false;
    bool entrance = false;
    bool exit = false;

    //distinguish the type of doorway
    int doorwayType = 0;

    //description of the doorway
    std::string _description;
};


//a concrete doorway implementation that cannot be entered from the room that contains it,
//but allows movement from the 'opposite' side which MUST be an OpenDoorway or LockedDoor
class OneWayDoor: public Doorway{
    OneWayDoor();
    void connect(Doorway &opposite) override;
};

//the standard concrete doorway implementation that
//allows unrestricted movement between rooms
class OpenDoorway: public Doorway{
    OpenDoorway();
    void connect(Doorway &opposite) override;
};

//a type of doorway that does not allow movement between rooms;
//the 'opposite' end of a BlockedDoorway MUST be another BlockedDoorway
class BlockedDoorway: public Doorway{
    BlockedDoorway();
    void connect(Doorway &opposite) override;
};

//a concrete doorway implementation that does not allow movement
//between rooms and can be 'unlocked' (if the gameplay were to be implemented)
class LockedDoor: public Doorway{
public:
    LockedDoor();
    void connect(Doorway &opposite) override;
    void setlocked(bool locked);
private:
    bool _locked;
};

class Wall: public RoomEdge{
    Wall() = default;
    virtual ~Wall() = default;
    std::string description() override;
    char displayCharacter() override;

};

}


#endif // ROOM_H
