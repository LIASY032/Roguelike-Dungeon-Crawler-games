#include "dungeon.h"

using namespace dungeon;
using namespace dungeon::common;

Room::Room(int id){
    _id = id;
}

int Room::id(){
    return _id;
}



Item* Room::item(){
    return _item;
}

void Room::setItem(Item &newItem){
    _item = &newItem;
}

AbstractCreature* Room::creature(){
    return _creature;
}

void Room::setCreature(AbstractCreature &newCreature){
    _creature = &newCreature;
}

//RoomEdge
bool RoomEdge::isPassage(){
    return pass;
}


//Doorway

void Doorway::connect(Doorway &opposite){
    isConnected = true;
    _doorway = &opposite;
}

bool Doorway::isEntrance(){
    return entrance;
}

bool Doorway::isExit(){
    return exit;
}

int Doorway::type(){
    return doorwayType;
}

std::string Doorway::description(){
    return _description;
}

OneWayDoor::OneWayDoor(){
    doorwayType = 2;

}

void OneWayDoor::connect(Doorway &opposite){
    if (opposite.type() == 1 || opposite.type() == 4){
        pass = true;
        isConnected = true;
        _doorway = &opposite;

        //allows movement from the 'opposite' side
        //which MUST be an OpenDoorway or LockedDoor
        if (_doorway->isExit()){
            entrance = true;
            _description = "the entrance (One-Way Door)";
            character = '<';
        }
        if (_doorway->isEntrance()){
            exit = true;
            _description = "an Exit (One-Way Door)";
            character = '>';
        }
    }
}

OpenDoorway::OpenDoorway(){
    //allows unrestricted movement between rooms
    entrance = true;
    exit = true;
    pass = true;

    doorwayType = 1;

    _description = "an Open Doorway";
    character = '>';
}

void OpenDoorway::connect(Doorway &opposite){
    isConnected = true;
    _doorway = &opposite;
}

BlockedDoorway::BlockedDoorway(){
    doorwayType = 3;
    _description = "a Block Doorway";
    character = 'X';
}

void BlockedDoorway::connect(Doorway &opposite){
//    if (opposite.type() == 3){
//        isConnected = true;
//        _doorway = &opposite;
//    }
}

LockedDoor::LockedDoor(){
    doorwayType = 4;
    _locked = false;
    _description = "a Locked Door";
}

void LockedDoor::setlocked(bool locked){
    _locked = locked;
    //if the _locked is true, set the exit and the entrance to true
    if (_locked){
        pass = true;
        entrance = true;
        exit = true;
    }
}
void LockedDoor::connect(Doorway &opposite){
    isConnected = true;
    _doorway = &opposite;
    character = '@';
}




std::string Wall::description(){
    return _description;

}

char Wall::displayCharacter(){
    return _character;
}


using namespace dungeon::basic;
RockWall::RockWall(){
    _description = "Rock Wall";
}


using namespace dungeon::magical;
MagicWall::MagicWall(){
    _description = "Magic Wall";
}
