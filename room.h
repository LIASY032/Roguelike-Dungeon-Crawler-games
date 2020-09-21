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

    RoomEdge* getNorthEdge();
    RoomEdge* getSouthEdge();
    RoomEdge* getEastEdge();
    RoomEdge* getWestEdge();



protected:
    int _id;
    std::unique_ptr<Item> _item = 0;
    std::unique_ptr<AbstractCreature> _creature = 0;
    std::string _description = "";
    std::unique_ptr<RoomEdge> northEdge = 0;
    std::unique_ptr<RoomEdge> southEdge = 0;
    std::unique_ptr<RoomEdge> eastEdge = 0;
    std::unique_ptr<RoomEdge> westEdge = 0;
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
