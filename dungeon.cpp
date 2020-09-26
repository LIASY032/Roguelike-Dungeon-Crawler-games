#include "dungeon.h"

using namespace core::dungeon;
using namespace core::dungeon::items;
using namespace core::dungeon::common;
using namespace core::dungeon::magical;
using namespace core::dungeon::basic;


Item::Item(std::string name){
    _name = name;
    _character = 'L';
}

Weapon::Weapon(std::string name){

    _character = 'L';
    _name = name;
}

Item* Weapon::clone() {

    return new Weapon(_name);
}

std::string Item::name(){
    return _name;
}

char Item::displayCharacter(){
    return _character;
}

Consumable::Consumable(std::string name){

    _character = 'L';
    _name = name;
}

Item* Consumable::clone() {
    return new Consumable(_name);
}



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



using namespace core::dungeon::creatures;


AbstractCreature::AbstractCreature(std::string name){
    _name = name;
}

AbstractCreature::AbstractCreature(std::string name, bool boss){
    _name= name;
    setBoss(boss);
}

Monster::Monster(std::string name){
    _name = name;
}

Monster::Monster(std::string name, bool boss){
    _name= name;
    setBoss(boss);
}

AbstractCreature* Monster::clone(){
    return new Monster(_name);
}

AbstractCreature* Monster::clone(bool boss){
    return new Monster(_name, boss);
}

void AbstractCreature::setBoss(bool _boss){
    boss = _boss;
}

bool AbstractCreature::getBoss(){
    return boss;
}

char AbstractCreature::displayCharacter(){
    return _character;
}


std::string Monster::name(){
    return _name;
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

void Wall::setDirection(Direction _direction){
    direction = _direction;
    if (direction == Direction::North || direction == Direction::South){
        character = '-';
    }else{
        character = '|';
    }
}

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

DungeonLevel::DungeonLevel(std::string name, int width, int height){
    _name = name;
    _width = width;
    _height = height;
    rooms.resize(width * height);
    numberOfRooms = width * height;

}

bool DungeonLevel::addRoom(Room &room){
    rooms.at(index) = std::unique_ptr<Room> (&room) ;
    ++index;
    return true;
}

void DungeonLevel::initializeRoom(Room &room){
    rooms.at(initializedIndex) = std::unique_ptr<Room> (&room) ;
    ++initializedIndex;
}

Room* DungeonLevel::retrieveRoom(int number){
    return rooms.at(number).get();
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

    std::string input = "";
    int count = 0;

    for (int i = 0; i < _height * 6; ++i){
        if (i%6 == 0 && i != 0){
            count = count + _width;
        }

        _display.push_back("");
        for (int column = 0; column < _width; ++column){
            input = input + rooms.at(count + column)->display()->at(i%6);

        }

        _display.at(i) = input;
        input = "";
    }


    return &_display;
}

int DungeonLevel::number(){
    return _number;
}

DungeonLevel* DungeonLevelBuilder::getDungeonLevel(){

    return level;
}

int DungeonLevelBuilder::generateRandomNumber(int number){
    srand(time(0));
    return rand()%number;
}

Direction DungeonLevelBuilder::reverseDirection(Direction direction){
    switch (direction) {
    case Direction::North:
        return Direction::South;
        break;
    case Direction::East:
        return Direction::West;
        break;
    case Direction::West:
        return Direction::East;
        break;
    case Direction::South:
        return Direction::North;
    }

}
void DungeonLevelBuilder::buildDoorwayHelper(Room &origin, Room &destination, Doorway &originEdge, Doorway &destinationEdge, Direction direction){


    switch (direction) {
    case Direction::North:
        origin.setNorthEdge(originEdge);
        destination.setSouthEdge(destinationEdge);
        break;
    case Direction::East:
        origin.setEastEdge(originEdge);
        destination.setWestEdge(destinationEdge);
        break;
    case Direction::West:
        origin.setWestEdge(originEdge);
        destination.setEastEdge(destinationEdge);
        break;
    default:
        origin.setSouthEdge(originEdge);
        destination.setNorthEdge(destinationEdge);
    }
    destinationEdge.connect(originEdge);
    originEdge.connect(destinationEdge);

}
void DungeonLevelBuilder::buildDoorway(Room &origin, Room &destination, Direction direction, DungeonLevelBuilder::MoveConstraints constraints){
    int number = generateRandomNumber(2);
    int block = generateRandomNumber(2);
    int lock = generateRandomNumber(3);


    switch (constraints) {
    case DungeonLevelBuilder::MoveConstraints::None:
        buildDoorwayHelper(origin, destination, *new OpenDoorway(), *new OpenDoorway(), direction);
        break;
    case DungeonLevelBuilder::MoveConstraints::OriginImpassable:

        if (block == 0){
            buildDoorwayHelper(origin, destination, *new BlockedDoorway(), *new BlockedDoorway(), direction);
        }else{
            if (number == 0){
                buildDoorwayHelper(origin, destination, *new OneWayDoor(), *new LockedDoor, direction);
            }else{
                buildDoorwayHelper(origin, destination, *new OneWayDoor(), *new OpenDoorway,direction);
            }
        }

        break;
    case DungeonLevelBuilder::MoveConstraints::DestinationImpassable:
        if (block == 0){
            buildDoorwayHelper(destination, origin, *new BlockedDoorway(), *new BlockedDoorway(), reverseDirection(direction));
        }else{
            if (number == 0){
                buildDoorwayHelper(destination, origin, *new OneWayDoor(), *new LockedDoor(), reverseDirection(direction));
            }else{
                buildDoorwayHelper(destination, origin, *new OneWayDoor(), *new OpenDoorway(),reverseDirection(direction));
            }
        }

        break;
    case DungeonLevelBuilder::MoveConstraints::OriginLocked:
        if (lock == 0){
            buildDoorwayHelper(destination, origin, *new LockedDoor(),*new OpenDoorway(), reverseDirection(direction));
        }else if (lock == 1){
            buildDoorwayHelper(destination, origin,*new LockedDoor(), *new OneWayDoor(),reverseDirection(direction));
        }else{
            buildDoorwayHelper(destination, origin,*new LockedDoor(), *new LockedDoor(),reverseDirection(direction));
        }

        break;
    default:
        if (lock == 0){
            buildDoorwayHelper(origin, destination, *new LockedDoor(),*new OpenDoorway(), direction);
        }else if (lock == 1){
            buildDoorwayHelper(origin, destination,*new LockedDoor(), *new OneWayDoor(),direction);
        }else{
            buildDoorwayHelper(origin, destination,*new LockedDoor(), *new LockedDoor(),direction);
        }
    }

}


OneWayDoor::OneWayDoor(){
    doorwayType = 2;
}

void OneWayDoor::setDirection(Direction _direction){
    direction = _direction;
    //if the doorway address is equal to 0, the direction of this is entrance or exit
    if (!_doorway){
        switch (direction) {
        case Direction::North:
            character ='I';
            _description = "the entrance (One-Way Door) to the dungeon level";
            break;
        case Direction::South:
            character = 'O';
            _description = "an Exit (One-Way Door) to the dungeon level";
            break;
        case Direction::East:
            character = 'O';
            _description = "the Exit (One-Way Door) to the dungeon level";
            break;
        case Direction::West:
            character = 'I';
            _description = "an entrance (One-Way Door) to the dungeon level";
            break;
        }
    }else{


        _description = "One-Way Door to another chamber";
        isConnected = true;
        switch (direction) {
        case Direction::North:
            character ='^';

            break;
        case Direction::South:
            character = 'v';

            break;
        case Direction::East:
            character = '>';

            break;
        default:
            character = '<';
        }
    }


}
void OneWayDoor::connect(Doorway &opposite){
    pass = true;

    //check the opposite doorway is open or loecked
    if (opposite.type() == 1){

        //this is open doorway
        _description = "One-Way Door to another chamber";
        isConnected = true;
        _doorway = &opposite;
        if (_doorway->isEntrance()){
            entrance = true;
        }
        if (_doorway->isExit()){
            exit = true;
        }
        character = opposite.displayCharacter();

    }else{
        //this is loecked doorway
        _description = "One-Way Door to another chamber";
        isConnected = true;
        switch (direction) {
        case Direction::North:
            character ='^';

            break;
        case Direction::South:
            character = 'v';

            break;
        case Direction::East:
            character = '>';

            break;
        default:
            character = '<';
        }
    }
}

OpenDoorway::OpenDoorway(){
    //allows unrestricted movement between rooms
    entrance = true;
    exit = true;
    pass = true;

    _description = "Open Doorway to another chamber";
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
    pass = true;
}

void BlockedDoorway::setDirection(Direction _direction){
    direction = _direction;
    pass =true;
}

void BlockedDoorway::connect(Doorway &opposite){
    //the opposite is always  blocked doorway
    if (opposite.type() == 3){
        isConnected = true;
        _doorway = &opposite;

    }
    pass =true;
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




RockWall::RockWall(){
    _description = "Rock Wall.";
}

RockChamber::RockChamber(int id){
    _id = id;
    _description = "A dark and empty chamber. (Rock Chamber)";
    //initializes the room is around the rock wall
    setEastEdge(*new RockWall());
    setWestEdge(*new RockWall());
    setNorthEdge(*new RockWall());
    setSouthEdge(*new RockWall());
}

QuartzChamber::QuartzChamber(int id){
    _id = id;
    _description = "A chamber that glitters like a "
                   "thousand stars in the torchlight. (Quartz Chamber)";
    //initializes the room is around the rock wall
    setEastEdge(*new RockWall());
    setWestEdge(*new RockWall());
    setNorthEdge(*new RockWall());
    setSouthEdge(*new RockWall());
}

BasicDungeonLevel::BasicDungeonLevel(std::string name, int width, int height){
    _name = name;
    _width = width;
    _height = height;
    numberOfRooms = width * height;
    rooms.resize(width * height);
}

std::string BasicDungeonLevel::description(){
    std::string w = std::to_string(_width);
    std::string h = std::to_string(_height);
    return _name + '\n' + "Size: " + w + " x " + h + '\n' + "Type: Dark Cave (Basic Dungeon)";

}

void BasicDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height){

    level = new BasicDungeonLevel{name, width, height};

    //initializes the level, the four directions of the rooms are rock walls
    for (int i = 0; i < level->numberOfRooms; ++i){

        level->initializeRoom(*buildRoom(i));
    }
}



Room* BasicDungeonLevelBuilder::buildRoom(int id){
    int number = generateRandomNumber(2);

    //randomlt generates the room
    if (number == 0){
        return new RockChamber(id);

    }else{

        return new QuartzChamber(id);
    }
}



void BasicDungeonLevelBuilder::buildEntrance(Room &room, Direction direction){
    //the enterance only has two direction, either North or west
    switch (direction) {
    case Direction::North:

        room.setNorthEdge(*new OneWayDoor());
        break;
    default:
        room.setWestEdge(*new OneWayDoor());
    }
}

void BasicDungeonLevelBuilder::buildExit(Room &room, Direction direction){
    //the exit only has two direction, either south or east
    switch (direction) {
    case Direction::South:

        room.setSouthEdge(*new OneWayDoor());

        break;
    default:
        room.setEastEdge(*new OneWayDoor());

    }
    //the exit room should have a boss and an item
    int number = generateRandomNumber(6);
    if (number == 0){
        room.setItem(*hpotion.clone());
    }else if (number == 1){
        room.setItem(*cocktail.clone());
    }else if (number == 2){
        room.setItem(*bomb.clone());
    }else if (number == 3){
        room.setItem(*boomerang.clone());
    }else if (number == 4){
        room.setItem(*sword.clone());
    }else{
        room.setItem(*axe.clone());
    }

    int othernumber = generateRandomNumber(3);
    if (othernumber == 0){
        room.setCreature(*goblin.clone(true));
    }else if (othernumber == 1){
        room.setCreature(*wizard.clone(true));
    }else{
        room.setCreature(*werewolf.clone(true));
    }
}

void BasicDungeonLevelBuilder::buildItem(Room &room){
    int number = generateRandomNumber(6);
    //randomly create an item
    if (number == 0){
        room.setItem(*hpotion.clone());
    }else if (number == 1){
        room.setItem(*cocktail.clone());
    }else if (number == 2){
        room.setItem(*bomb.clone());
    }else if (number == 3){
        room.setItem(*boomerang.clone());
    }else if (number == 4){
        room.setItem(*sword.clone());
    }else{
        room.setItem(*axe.clone());
    }

}

void BasicDungeonLevelBuilder::buildCreature(Room &room){
    //randomly create a monster
    int othernumber = generateRandomNumber(3);
    if (othernumber == 0){
        room.setCreature(*goblin.clone());
    }else if (othernumber == 1){
        room.setCreature(*wizard.clone());
    }else{
        room.setCreature(*werewolf.clone());
    }
}




MagicWall::MagicWall(){

    _description = "Magic Wall.";
}

AlchemistsLaboratory::AlchemistsLaboratory(int id){
    _id = id;
    _description = "An Alchemists Laboratory";

    //initializes the room is around the magic wall
    setEastEdge(*new MagicWall());
    setWestEdge(*new MagicWall());
    setNorthEdge(*new MagicWall());
    setSouthEdge(*new MagicWall());
}

EnchantedLiboratory::EnchantedLiboratory(int id){
    _id = id;
    _description = "An Enchanted Liboratory";

    //initializes the room is around the magic wall
    setEastEdge(*new MagicWall());
    setWestEdge(*new MagicWall());
    setNorthEdge(*new MagicWall());
    setSouthEdge(*new MagicWall());
}




MagicalDungeonLevel::MagicalDungeonLevel(std::string name, int width, int height){
    _name = name;
    _width = width;
    _height = height;
    numberOfRooms = width * height;

    rooms.resize(width * height);
}

std::string MagicalDungeonLevel::description(){
    std::string w = std::to_string(_width);
    std::string h = std::to_string(_height);
    return name() + '\n' + "Size: " + w + " x " + h + '\n' + "Type: Dark Cave (Magical Dungeon)";

}

void MagicalDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height){


    level = new MagicalDungeonLevel{name, width, height};


    //initializes the level, the four directions of the rooms are magic walls
    for (int i = 0; i < level->numberOfRooms; ++i){

        level->initializeRoom(*buildRoom(i));
    }

}



Room* MagicalDungeonLevelBuilder::buildRoom(int id){
    int number = generateRandomNumber(2);

    //randomlt generates the room
    if (number == 0){
        return new EnchantedLiboratory(id);

    }else{

        return new AlchemistsLaboratory(id);
    }

}



void MagicalDungeonLevelBuilder::buildEntrance(Room &room, Direction direction){

    //the enterance only has two direction, either North or west
    switch (direction) {
    case Direction::North:

        room.setNorthEdge(*new OneWayDoor());
        break;
    default:
        room.setWestEdge(*new OneWayDoor());
    }
}

void MagicalDungeonLevelBuilder::buildExit(Room &room, Direction direction){
    //the exit only has two direction, either south or east
    switch (direction) {
    case Direction::South:

        room.setSouthEdge(*new OneWayDoor());

        break;
    default:
        room.setEastEdge(*new OneWayDoor());

    }

    //the exit room should have a boss and an item
    int number = generateRandomNumber(6);
    if (number == 0){
        room.setItem(*hpotion.clone());
    }else if (number == 1){
        room.setItem(*cocktail.clone());
    }else if (number == 2){
        room.setItem(*rpotion.clone());
    }else if (number == 3){
        room.setItem(*boomerang.clone());
    }else if (number == 4){
        room.setItem(*staff.clone());
    }else{
        room.setItem(*wand.clone());
    }

    int othernumber = generateRandomNumber(3);
    if (othernumber == 0){
        room.setCreature(*goblin.clone(true));
    }else if (othernumber == 1){
        room.setCreature(*wizard.clone(true));
    }else{
        room.setCreature(*dragon.clone(true));
    }


}

void MagicalDungeonLevelBuilder::buildItem(Room &room){
    int number = generateRandomNumber(6);

    //randomly create an item
    if (number == 0){
        room.setItem(*hpotion.clone());
    }else if (number == 1){
        room.setItem(*cocktail.clone());
    }else if (number == 2){
        room.setItem(*rpotion.clone());
    }else if (number == 3){
        room.setItem(*boomerang.clone());
    }else if (number == 4){
        room.setItem(*staff.clone());
    }else{
        room.setItem(*wand.clone());
    }
}

void MagicalDungeonLevelBuilder::buildCreature(Room &room){
    //randomly create a monster
    int number = generateRandomNumber(3);

    if (number == 0){
        room.setCreature(*goblin.clone());
    }else if (number == 1){
        room.setCreature(*wizard.clone());
    }else{
        room.setCreature(*dragon.clone());
    }
}


