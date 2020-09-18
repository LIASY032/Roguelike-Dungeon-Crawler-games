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
    if (_item){
        item = (char) _item->displayCharacter();
    }else{
         item = " ";
    }
    if (_creature){
        if (_creature->getBoss()){
            creature = "M*";
        }else{
            creature = "M ";
        }
    }else{
        creature = "  ";
    }
    std::string north;
    north = (char) northEdge->displayCharacter();
    std::string east;
    east = (char) eastEdge->displayCharacter();
    std::string south;
    south = (char) southEdge->displayCharacter();
    std::string west;
    west = (char) westEdge->displayCharacter();
    std::string extend = " ";
    if (eastEdge->isPassage()){
        extend = "-";
    }
    std::string endLine = "        ";
    if (southEdge->isPassage()){
        endLine = "   |    ";
    }

    std::string line = "|     | ";
    _output.push_back("+--" + north + "--+ ");
    _output.push_back(line);
    _output.push_back(west + " " + creature + item + " " + east + extend);
    _output.push_back(line);
    _output.push_back("+--" + south + "--+ ");
    _output.push_back(endLine);
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



RoomEdge* Room::getNorthEdge(){
    return northEdge;
}

RoomEdge* Room::getSouthEdge(){
    return southEdge;
}

RoomEdge* Room::getWestEdge(){
    return westEdge;
}

RoomEdge* Room::getEastEdge(){
    return eastEdge;
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
