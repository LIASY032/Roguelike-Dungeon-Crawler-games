#include "dungeonlevel.h"

DungeonLevel::DungeonLevel(std::string name, int width, int height){
    _name = name;
    _width = width;
    _height = height;
}

bool DungeonLevel::addRoom(Room room){// need to be fixed
    rooms.insert({index, room});
    ++index;
    return true;
}

Room DungeonLevel::retrieveRoom(int number){
    return rooms.at(number);//not sure
}

int DungeonLevel::width(){
    return _width;
}

int DungeonLevel::height(){
    return _height;
}

std::string DungeonLevel::name(){
    return _name;
}

std::vector<std::string>* DungeonLevel::display(){
    _number = 8 * _width;//maybe it shall be deleted
    std::string output = "";


    return &_display;
}

int DungeonLevel::number(){
    return _number;
}

BasicDungeonLevel::BasicDungeonLevel(std::string name, int width, int height){
    _name = name;
    _width = width;
    _height = height;
}

std::string BasicDungeonLevel::description(){
    std::string w = std::to_string(_width);
    std::string h = std::to_string(_height);
    return _name + '\n' + "Size: " + w + " x " + h + '\n' + "Type: Dark Cave (Basic Dungeon)";

}

MagicalDungeonLevel::MagicalDungeonLevel(std::string name, int width, int height){
    _name = name;
    _width = width;
    _height = height;
}

std::string MagicalDungeonLevel::description(){
    std::string w = std::to_string(_width);
    std::string h = std::to_string(_height);
    return name() + '\n' + "Size: " + w + " x " + h + '\n' + "Type: Dark Cave (Magical Dungeon)";

}





