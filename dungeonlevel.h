#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include <iostream>
#include "room.h"
#include <map>
#include <vector>

class DungeonLevel{
public:
    DungeonLevel() = default;
    virtual ~DungeonLevel() = default;
    DungeonLevel(std::string name, int width, int height);
    bool addRoom(Room &room);
    Room* retrieveRoom(int number);
    int width();
    int height();
    int numberOfRooms = _width * _height;
    std::string name();
    virtual std::string description() = 0;
    std::vector<std::string>* display();
    int number();
    void initializeRoom(Room &room);
protected:
    std::string _name;
    int _width = 0;
    int _height = 0;
    int _number = 0;
    std::vector<std::string> _display{};
    int index = 0;
    int initializedIndex = 0;
    std::vector<std::unique_ptr<Room>> rooms;
    std::string _description = "";

};

class BasicDungeonLevel: public DungeonLevel{
public:
    BasicDungeonLevel() = default;
    BasicDungeonLevel(std::string name, int width, int height);
    std::string description() override;
};

class MagicalDungeonLevel: public DungeonLevel{
public:
    MagicalDungeonLevel() = default;
    MagicalDungeonLevel(std::string name, int width, int height);
    std::string description() override;
};

#endif // DUNGEONLEVEL_H
