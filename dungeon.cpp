#include "dungeon.h"

using namespace dungeon;

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

OneWayDoor::OneWayDoor(){
    doorwayType = 2;
}

void OneWayDoor::connect(Doorway &opposite){
    if (opposite.type() == 1 || opposite.type() == 4){
        isConnected = true;
        _doorway = &opposite;

        //allows movement from the 'opposite' side
        //which MUST be an OpenDoorway or LockedDoor
        if (_doorway->isExit()){
            entrance = true;
        }
        if (_doorway->isEntrance()){
            exit = true;
        }
    }
}

OpenDoorway::OpenDoorway(){
    //allows unrestricted movement between rooms
    entrance = true;
    exit = true;

    doorwayType = 1;
}

void OpenDoorway::connect(Doorway &opposite){
    isConnected = true;
    _doorway = &opposite;
}

BlockedDoorway::BlockedDoorway(){
    doorwayType = 3;
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
}

void LockedDoor::setlocked(bool locked){
    _locked = locked;
    //if the _locked is true, set the exit and the entrance to true
    if (_locked){
        entrance = true;
        exit = true;
    }
}
void LockedDoor::connect(Doorway &opposite){
    isConnected = true;
    _doorway = &opposite;
}





