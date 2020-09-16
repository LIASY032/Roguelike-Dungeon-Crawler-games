#include "room.h"
Room::Room(int id){
    _id = id;
}

int Room::id(){
    return _id;
}

std::string* Room::display(){

    for (int i = 0; i < 35; ++i){
        switch (i) {
        case 0: case 6: case 28: case 34:
            output[i] = '+';
            break;
        case 1: case 2: case 4: case 5: case 29: case 30: case 32: case 33:
            output[i] = '-';
            break;
        case 7: case 13: case 21: case 27:
            output[i] = '|';
            break;
        case 3:
            output[i] = northEdge->displayCharacter();
            break;
        case 20:
            output[i] = eastEdge->displayCharacter();
            break;
        case 14:
            output[i] = westEdge->displayCharacter();
            break;
        case 31:
            output[i] = southEdge->displayCharacter();
            break;
        case 16:
            output[i] = _creature->displayCharacter();
        case 17:
            if (_creature->getBoss()){
                output[i] = '*';
            }else{
                output[i] = ' ';
            }
            break;
        case 18:
            output[i] = _item->displayCharacter();
            break;
        default:
            output[i] = ' ';


        }
    }
    return output;
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
}

void Room::setWestEdge(RoomEdge &edge){
    westEdge = &edge;
}

void Room::setNorthEdge(RoomEdge &edge){
    northEdge = &edge;
}

void Room::setSouthEdge(RoomEdge &edge){
    southEdge = &edge;
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
