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
        item = 'L';
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
    return _item.get();
}

void Room::setItem(Item &newItem){
    _item = std::unique_ptr<Item>(&newItem);
}

AbstractCreature* Room::creature(){
    return _creature.get();
}

void Room::setCreature(AbstractCreature &newCreature){
    _creature = std::unique_ptr<AbstractCreature> (&newCreature);
}

void Room::setEastEdge(RoomEdge &edge){
    eastEdge = std::unique_ptr<RoomEdge> (&edge);
    eastEdge->setDirection(Direction::East);
}

void Room::setWestEdge(RoomEdge &edge){
    westEdge = std::unique_ptr<RoomEdge> (&edge);
    westEdge->setDirection(Direction::West);
}

void Room::setNorthEdge(RoomEdge &edge){
    northEdge = std::unique_ptr<RoomEdge> (&edge);
    northEdge->setDirection(Direction::North);
}

void Room::setSouthEdge(RoomEdge &edge){
    southEdge = std::unique_ptr<RoomEdge> (&edge);
    southEdge->setDirection(Direction::South);
}



RoomEdge* Room::getNorthEdge(){
    return northEdge.get();
}

RoomEdge* Room::getSouthEdge(){
    return southEdge.get();
}

RoomEdge* Room::getWestEdge(){
    return westEdge.get();
}

RoomEdge* Room::getEastEdge(){
    return eastEdge.get();
}

std::string Room::description(){
    _description = _description + '\n' + northEdge->description() +
                   '\n' + southEdge->description() + '\n' +
                   eastEdge->description() + '\n' +
                   westEdge->description() + '\n';
    if (_creature){
        if (_creature->getBoss()){
            _description = _description + "There is a BOSS " + _creature->name() + " to fight\n";
        }else{
            _description = _description + "There is a " + _creature->name() + " to fight\n";
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
    setEastEdge(*new RockWall());
    setWestEdge(*new RockWall());
    setNorthEdge(*new RockWall());
    setSouthEdge(*new RockWall());
}

QuartzChamber::QuartzChamber(int id){
    _id = id;
    _description = "A chamber that glitters like a "
                   "thousand stars in the torchlight. (Quartz Chamber)";

    setEastEdge(*new RockWall());
    setWestEdge(*new RockWall());
    setNorthEdge(*new RockWall());
    setSouthEdge(*new RockWall());
}

AlchemistsLaboratory::AlchemistsLaboratory(int id){
    _id = id;
    _description = "An Alchemists Laboratory";

    setEastEdge(*new MagicWall());
    setWestEdge(*new MagicWall());
    setNorthEdge(*new MagicWall());
    setSouthEdge(*new MagicWall());
}

EnchantedLiboratory::EnchantedLiboratory(int id){
    _id = id;
    _description = "An Enchanted Liboratory";

    setEastEdge(*new MagicWall());
    setWestEdge(*new MagicWall());
    setNorthEdge(*new MagicWall());
    setSouthEdge(*new MagicWall());
}
