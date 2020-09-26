//#include "common.h"

//using namespace core::dungeon::common;

//OneWayDoor::OneWayDoor(){
//    doorwayType = 2;
//}

//void OneWayDoor::setDirection(Direction _direction){
//    direction = _direction;
//    //if the doorway address is equal to 0, the direction of this is entrance or exit
//    if (!_doorway){
//        switch (direction) {
//        case Direction::North:
//            character ='I';
//            _description = "the entrance (One-Way Door) to the dungeon level";
//            break;
//        case Direction::South:
//            character = 'O';
//            _description = "an Exit (One-Way Door) to the dungeon level";
//            break;
//        case Direction::East:
//            character = 'O';
//            _description = "the Exit (One-Way Door) to the dungeon level";
//            break;
//        case Direction::West:
//            character = 'I';
//            _description = "an entrance (One-Way Door) to the dungeon level";
//            break;
//        }
//    }else{


//        _description = "One-Way Door to another chamber";
//        isConnected = true;
//        switch (direction) {
//        case Direction::North:
//            character ='^';

//            break;
//        case Direction::South:
//            character = 'v';

//            break;
//        case Direction::East:
//            character = '>';

//            break;
//        default:
//            character = '<';
//        }
//    }


//}
//void OneWayDoor::connect(Doorway &opposite){
//    pass = true;

//    //check the opposite doorway is open or loecked
//    if (opposite.type() == 1){

//        //this is open doorway
//        _description = "One-Way Door to another chamber";
//        isConnected = true;
//        _doorway = &opposite;
//        if (_doorway->isEntrance()){
//            entrance = true;
//        }
//        if (_doorway->isExit()){
//            exit = true;
//        }
//        character = opposite.displayCharacter();

//    }else{
//        //this is loecked doorway
//        _description = "One-Way Door to another chamber";
//        isConnected = true;
//        switch (direction) {
//        case Direction::North:
//            character ='^';

//            break;
//        case Direction::South:
//            character = 'v';

//            break;
//        case Direction::East:
//            character = '>';

//            break;
//        default:
//            character = '<';
//        }
//    }
//}

//OpenDoorway::OpenDoorway(){
//    //allows unrestricted movement between rooms
//    entrance = true;
//    exit = true;
//    pass = true;

//    _description = "Open Doorway to another chamber";
//    doorwayType = 1;


//}

//void OpenDoorway::setDirection(Direction _direction){
//    direction = _direction;
//    switch (direction) {
//    case Direction::North:
//        character = '^';
//        break;
//    case Direction::South:
//        character = 'v';
//        break;
//    case Direction::East:
//        character = '>';
//        break;
//    case Direction::West:
//        character = '<';
//        break;
//    }
//}

//void OpenDoorway::connect(Doorway &opposite){
//    isConnected = true;
//    _doorway = &opposite;
//}

//BlockedDoorway::BlockedDoorway(){
//    doorwayType = 3;
//    _description = "a Block Doorway to another chamber.";
//    character = 'X';
//    pass = true;
//}

//void BlockedDoorway::setDirection(Direction _direction){
//    direction = _direction;
//    pass =true;
//}

//void BlockedDoorway::connect(Doorway &opposite){
//    //the opposite is always  blocked doorway
//    if (opposite.type() == 3){
//        isConnected = true;
//        _doorway = &opposite;

//    }
//    pass =true;
//}

//LockedDoor::LockedDoor(){
//    doorwayType = 4;
//    pass = true;
//    _locked = false;
//    _description = "a Locked Door to another chamber.";
//    character = '@';
//}

//void LockedDoor::setDirection(Direction _direction){
//    direction = _direction;
//}

//void LockedDoor::setlocked(bool locked){
//    _locked = locked;

//    //if the _locked is true, set the exit and the entrance to true
//    if (_locked){

//        entrance = true;
//        exit = true;
//    }
//}

//void LockedDoor::connect(Doorway &opposite){
//    isConnected = true;
//    _doorway = &opposite;

//}

