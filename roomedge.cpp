#include "roomedge.h"



//RoomEdge
bool RoomEdge::isPassage(){
    return pass;
}

char RoomEdge::displayCharacter(){
    return character;
}


Direction RoomEdge::getDirection(){
    return direction;
}

std::string RoomEdge::description(){
    std::string output = "";
    switch (direction) {
    case Direction::East:
        output = "EAST ";
        break;
    case Direction::West:
        output = "West ";
        break;
    case Direction::North:
        output = "North ";
        break;
        default:
        output = "South ";


    }
    return "To the " + output + "is the " + _description;
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
    pass = true;


}

void OneWayDoor::setDirection(Direction _direction){
    direction = _direction;
    switch (direction) {
    case Direction::North:
        character ='v';
        _description = "the entrance (One-Way Door) to the dungeon level";
        break;
    case Direction::South:
        character = 'v';
        _description = "an Exit (One-Way Door) to the dungeon level";
        break;
    case Direction::East:
        character = '>';
        _description = "the entrance (One-Way Door) to the dungeon level";
        break;
    case Direction::West:
        character = '>';
        _description = "an Exit (One-Way Door) to the dungeon level";
        break;
    }
}
void OneWayDoor::connect(Doorway &opposite){
    if (opposite.type() == 1 || opposite.type() == 4){
        isConnected = true;
        _doorway = &opposite;
        if (_doorway->isEntrance()){
            entrance = true;
            _description = "One-Way Door to another chamber";
        }
        if (_doorway->isExit()){
            exit = true;
            _description = "One-Way Door to another chamber";
        }
        character = opposite.displayCharacter();

    }
}

OpenDoorway::OpenDoorway(){
    //allows unrestricted movement between rooms
    entrance = true;
    exit = true;
    pass = true;

    doorwayType = 1;


}

void OpenDoorway::setDirection(Direction _direction){
    direction = _direction;
    switch (direction) {
    case Direction::North:
        character = '^';
        break;
    case Direction::South:
        character = 'v';
        break;
    case Direction::East:
        character = '>';
        break;
    case Direction::West:
        character = '<';
        break;
    }
}

void OpenDoorway::connect(Doorway &opposite){
    isConnected = true;
    _doorway = &opposite;
}

BlockedDoorway::BlockedDoorway(){
    doorwayType = 3;
    _description = "a Block Doorway to another chamber.";
    character = 'X';
}

void BlockedDoorway::setDirection(Direction _direction){
    direction = _direction;
}

void BlockedDoorway::connect(Doorway &opposite){
        if (opposite.type() == 3){
            isConnected = true;
            _doorway = &opposite;
        }
}

LockedDoor::LockedDoor(){
    doorwayType = 4;
    pass = true;
    _locked = false;
    _description = "a Locked Door to another chamber.";
    character = '@';
}

void LockedDoor::setDirection(Direction _direction){
    direction = _direction;
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


Wall::Wall(){

}

void Wall::setDirection(Direction _direction){
    direction = _direction;
    if (direction == Direction::North || direction == Direction::South){
        character = '-';
    }else{
        character = '|';
    }
}




RockWall::RockWall(){
    _description = "Rock Wall.";
}



MagicWall::MagicWall(){
    _description = "Magic Wall.";
}
