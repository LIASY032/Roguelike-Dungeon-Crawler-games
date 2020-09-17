#ifndef ROOM_H
#define ROOM_H
#include "roomedge.h"
#include "item.h"
#include "creature.h"
using namespace creature;
#include <iostream>
#include <vector>

class Room
{
public:
    Room() = default;
    virtual ~Room() = default;
    Room(int id);
    std::string description();
    std::vector<std::string>* display();
    int id();
    Item* item();
    void setItem(Item &newItem);
    AbstractCreature* creature();
    void setCreature(AbstractCreature &newCreature);
    void setNorthEdge(RoomEdge &edge);
    void setSouthEdge(RoomEdge &edge);
    void setEastEdge(RoomEdge &edge);
    void setWestEdge(RoomEdge &edge);


protected:
    int _id;
    Item* _item;
    AbstractCreature* _creature;
    std::string _description = "";
    RoomEdge* northEdge;
    RoomEdge* southEdge;
    RoomEdge* eastEdge;
    RoomEdge* westEdge;
    std::vector<std::string> _output;

};

class RockChamber: public Room{
public:
    RockChamber() = default;
    RockChamber(int id);

};


class QuartzChamber:public Room{
public:
    QuartzChamber() = default;
    QuartzChamber(int id);
};

class AlchemistsLaboratory: public Room{
public:
    AlchemistsLaboratory() = default;
    AlchemistsLaboratory(int id);

};

class EnchantedLiboratory:public Room{
public:
    EnchantedLiboratory() = default;
    EnchantedLiboratory(int id);
};


#endif // ROOM_H
