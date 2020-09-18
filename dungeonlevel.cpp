#include "dungeonlevel.h"

DungeonLevel::DungeonLevel(std::string name, int width, int height){
    _name = name;
    _width = width;
    _height = height;
}

bool DungeonLevel::addRoom(Room room){
    rooms.push_back(room);

    return true;
}

Room DungeonLevel::retrieveRoom(int number){
    return rooms.at(number);
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

//    for (int i = 0; i < _height * 6; ++i){
//        _display.push_back("");
//    }

    std::string input = "";
    int count = 0;
    for (int i = 0; i < _height * 6; ++i){
         _display.push_back("");
        for (int column = 0; column < _width; ++column){
            input = input + rooms.at(column).display()->at(i%6);
        }
        if (i%6 == 0){
            ++count;
        }
        _display.at(i) = input;
        input = "";
    }


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





