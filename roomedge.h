#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include <ios>
enum class Direction: unsigned{
    North,
    South,
    East,
    West
};

class RoomEdge{
public:
    RoomEdge() = default;
    virtual ~RoomEdge() = default;
    std::string description();
    char displayCharacter();
    bool isPassage();
    virtual void setDirection(Direction _direction) = 0;
    Direction getDirection();
protected:
    char character = ' ';

    //store the condition of isPassage, set it false
    bool pass = false;

    //set direction of the roomedge
    Direction direction = Direction::North;
    std::string _description;
};

//Doorway
class Doorway : public RoomEdge{
public:
    Doorway() = default;
    virtual void connect(Doorway &opposite) = 0;
    bool isEntrance();
    bool isExit();
    int type();
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

//a concrete doorway implementation that cannot be entered from the room that contains it,
//but allows movement from the 'opposite' side which MUST be an OpenDoorway or LockedDoor
class OneWayDoor: public Doorway{
public:
    OneWayDoor();
    void connect(Doorway &opposite) override;
    void setDirection(Direction _direction) override;
};

//the standard concrete doorway implementation that
//allows unrestricted movement between rooms
class OpenDoorway: public Doorway{
public:
    OpenDoorway();
    void connect(Doorway &opposite) override;
    void setDirection(Direction _direction) override;
};

//a type of doorway that does not allow movement between rooms;
//the 'opposite' end of a BlockedDoorway MUST be another BlockedDoorway
class BlockedDoorway: public Doorway{
public:
    BlockedDoorway();
    void connect(Doorway &opposite) override;
    void setDirection(Direction _direction) override;
};

//a concrete doorway implementation that does not allow movement
//between rooms and can be 'unlocked' (if the gameplay were to be implemented)
class LockedDoor: public Doorway{
public:
    LockedDoor();
    void connect(Doorway &opposite) override;
    void setlocked(bool locked);
    void setDirection(Direction _direction) override;

private:
    bool _locked;
};


class Wall: public RoomEdge{
public:
    Wall();
    virtual ~Wall() = default;
    void setDirection(Direction _direction) override;


};

class MagicWall: public Wall{
public:
    MagicWall();
};

class RockWall: public Wall{
public:
    RockWall();
};

#endif // ROOMEDGE_H
