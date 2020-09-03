#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include "item.h"
#include "creature.h"
using namespace creature;
namespace dungeon {
enum Direction {
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
    virtual Item item() = 0;
    virtual void setItem(Item newItem) = 0;
    virtual AbstractCreature creature() = 0;
    virtual void setCreature(AbstractCreature newCreature) = 0;

protected:
    int _id;
    Item* item;

};

}


#endif // ROOM_H
