#include "room.h"
Room::Room(int id){
    _id = id;
}

int Room::id(){
    return _id;
}

std::vector<std::string>* Room::display(){
    std::string item = " ";
    std::string creature = "  ";


//    for (int i = 0; i < 35; ++i){
//        switch (i) {
//        case 0: case 6: case 28: case 34:
//            output[i] = '+';
//            break;
//        case 1: case 2: case 4: case 5: case 29: case 30: case 32: case 33:
//            output[i] = '-';
//            break;
//        case 7: case 13: case 21: case 27:
//            output[i] = '|';
//            break;
//        case 3:
//            output[i] = northEdge->displayCharacter();
//            break;
//        case 20:
//            output[i] = eastEdge->displayCharacter();
//            break;
//        case 14:
//            output[i] = westEdge->displayCharacter();
//            break;
//        case 31:
//            output[i] = southEdge->displayCharacter();
//            break;
//        case 16:
//            if (_creature){
//                output[i] = _creature->displayCharacter();
//            }else{
//                output[i] = ' ';
//            }
//            break;
//        case 17:
//            if (_creature){
//                if (_creature->getBoss()){
//                    output[i] = '*';
//                    creature =  "* ";
//                }else{
//                    output[i] = ' ';
//                    creature = "M ";
//                }
//            }else{
//                output[i] = ' ';
//            }
//            break;
//        case 18:
//            if (_item){
//                output[i] = _item->displayCharacter();
//                item = "L";
//            }else{
//                output[i] = ' ';
//            }
//            break;
//        default:
//            output[i] = ' ';
//        }
//    }

    if (_creature){
        if (_creature->getBoss()){

            creature =  "M*";
        }else{

            creature = "M ";
        }
    }
    if (_item){

        item = "L";

    }


    std::string north;
    north= (char) northEdge->displayCharacter();
    std::string east;
    east = (char) eastEdge->displayCharacter();
    std::string south;
    south = (char) southEdge->displayCharacter();
    std::string west;
    west = (char) westEdge->displayCharacter();
    std::string first = "+--" + north + "--+";
    std::string line = "|     |";
    std::string second = west + " " + creature + item + " " + east;
    std::string third = "+--" + south + "--+";

    _output.push_back(first);
    _output.push_back(line);
    _output.push_back(second);
    _output.push_back(line);
    _output.push_back(third);


    return &_output;
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

void Room::setEastEdge(RoomEdge &edge){
    eastEdge = &edge;
    eastEdge->setDirection(Direction::East);
}

void Room::setWestEdge(RoomEdge &edge){
    westEdge = &edge;
    westEdge->setDirection(Direction::West);
}

void Room::setNorthEdge(RoomEdge &edge){
    northEdge = &edge;
    northEdge->setDirection(Direction::North);
}

void Room::setSouthEdge(RoomEdge &edge){
    southEdge = &edge;
    southEdge->setDirection(Direction::South);
}

std::string Room::description(){
    _description = _description + '\n' + northEdge->description() +
                   '\n' + southEdge->description() + '\n' +
                   eastEdge->description() + '\n' +
                   westEdge->description() + '\n';
    if (_creature){
        if (_creature->getBoss()){
            _description = _description + "There is a BOSS " + _creature->name() + "to fight\n";
        }else{
            _description = _description + "There is a " + _creature->name() + "to fight\n";
        }
    }
    if (_item){
        _description = _description + "There is a " + _item->name() + " to pick up\n";
    }
    return _description;
}

RockChamber::RockChamber(int id){
    _id = id;
    _description = "A dark and empty chamber. (Rock Chamber)";
}

QuartzChamber::QuartzChamber(int id){
    _id = id;
    _description = "A chamber that glitters like a "
                   "thousand stars in the torchlight. (Quartz Chamber)";

}

AlchemistsLaboratory::AlchemistsLaboratory(int id){
    _id = id;
    _description = "An Alchemists Laboratory";
}

EnchantedLiboratory::EnchantedLiboratory(int id){
    _id = id;
    _description = "An Enchanted Liboratory";
}
