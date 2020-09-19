#include "dungeonlevelbuilder.h"


DungeonLevel* DungeonLevelBuilder::getDungeonLevel(){
    return level;
}

int DungeonLevelBuilder::generateRandomNumber(int number){
    srand(time(0));
    return rand()%number;
}

void MagicalDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height){
    MagicalDungeonLevel _level(name, width, height);
    level = &_level;
}

Room* MagicalDungeonLevelBuilder::buildRoom(int id){
    Room* room;
    int number = generateRandomNumber(2);
    if (number == 0){
        EnchantedLiboratory enchant{id};
        room = &enchant;
    }else{
        AlchemistsLaboratory alchemist{id};
        room = &alchemist;
    }

    return room;
}

void MagicalDungeonLevelBuilder::buildDoorway(Room &origin, Room &destination, Direction direction, DungeonLevelBuilder::MoveConstraints constraints){
    int number = generateRandomNumber(2);

    RoomEdge* originEdge;
    RoomEdge* destinationEdge;
    switch (constraints) {
    case DungeonLevelBuilder::MoveConstraints::None:
        originEdge = new OpenDoorway();
        destinationEdge = new OpenDoorway();
        break;
    case DungeonLevelBuilder::MoveConstraints::OriginImpassable:

        originEdge = new OneWayDoor();
        if (number == 0){

            destinationEdge = new OpenDoorway();
        }else{
            destinationEdge= new LockedDoor();
        }
        break;
    case DungeonLevelBuilder::MoveConstraints::DestinationImpassable:
        destinationEdge = new OneWayDoor();
        if (number == 0){
            originEdge = new OpenDoorway();
        }else{
            originEdge= new LockedDoor();
        }
        break;
    case DungeonLevelBuilder::MoveConstraints::OriginLocked:
        originEdge = new LockedDoor();
        if (number == 0){

            destinationEdge = new OpenDoorway();
        }else{
            destinationEdge= new OneWayDoor();
        }
        break;
    default:
        destinationEdge = new LockedDoor();
        if (number == 0){
            originEdge = new OpenDoorway();
        }else{
            originEdge= new OneWayDoor();
        }
    }
    switch (direction) {
    case Direction::North:
        origin.setNorthEdge(*originEdge);
        destination.setSouthEdge(*destinationEdge);
        break;
    case Direction::East:
        origin.setEastEdge(*originEdge);
        destination.setWestEdge(*destinationEdge);
        break;
    case Direction::West:
        origin.setWestEdge(*originEdge);
        destination.setEastEdge(*destinationEdge);
        break;
    default:
        origin.setSouthEdge(*originEdge);
        destination.setNorthEdge(*destinationEdge);
    }

}

void MagicalDungeonLevelBuilder::buildEntrance(Room &room, Direction direction){
    OneWayDoor oneWay;
    MagicWall wall;
    switch (direction) {
    case Direction::North:

        room.setNorthEdge(oneWay);
        room.setWestEdge(wall);
        break;
    default:
        room.setWestEdge(oneWay);
        room.setNorthEdge(wall);
    }
}

void MagicalDungeonLevelBuilder::buildExit(Room &room, Direction direction){
    OneWayDoor oneWay;
    MagicWall wall;
    switch (direction) {
    case Direction::South:

        room.setSouthEdge(oneWay);
        room.setEastEdge(wall);
        break;
    default:
        room.setEastEdge(oneWay);
        room.setSouthEdge(wall);
    }
    int number = generateRandomNumber(6);
    Item* item;
    if (number == 0){
        item = hpotion.clone();
    }else if (number == 1){
        item = cocktail.clone();
    }else if (number == 2){
        item = rpotion.clone();
    }else if (number == 3){
        item = boomerang.clone();
    }else if (number == 4){
        item = staff.clone();
    }else{
        item = wand.clone();
    }
    room.setItem(*item);

    int othernumber = generateRandomNumber(3);
    AbstractCreature* creature;
    if (othernumber == 0){
        creature = goblin.clone();
    }else if (othernumber == 1){
        creature = wizard.clone();
    }else{
        creature = dragon.clone();
    }
    creature->setBoss(true);
    room.setCreature(*creature);

}

void MagicalDungeonLevelBuilder::buildItem(Room &room){
    int number = generateRandomNumber(6);
    Item* item;
    if (number == 0){
        item = hpotion.clone();
    }else if (number == 1){
        item = cocktail.clone();
    }else if (number == 2){
        item = rpotion.clone();
    }else if (number == 3){
        item = boomerang.clone();
    }else if (number == 4){
        item = staff.clone();
    }else{
        item = wand.clone();
    }
    room.setItem(*item);
}

void MagicalDungeonLevelBuilder::buildCreature(Room &room){
    int number = generateRandomNumber(3);
    AbstractCreature* creature;
    if (number == 0){
        creature = goblin.clone();
    }else if (number == 1){
        creature = wizard.clone();
    }else{
        creature = dragon.clone();
    }
    room.setCreature(*creature);
}

void BasicDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height){
    BasicDungeonLevel _level{name, width, height};
    level = &_level;
}

Room* BasicDungeonLevelBuilder::buildRoom(int id){
    Room* room;
    int number = generateRandomNumber(2);
    if (number == 0){
        RockChamber enchant{id};
        room = &enchant;
    }else{
        QuartzChamber alchemist{id};
        room = &alchemist;
    }

    return room;
}


void BasicDungeonLevelBuilder::buildDoorway(Room &origin, Room &destination, Direction direction, DungeonLevelBuilder::MoveConstraints constraints){
    int number = generateRandomNumber(2);

    RoomEdge* originEdge;
    RoomEdge* destinationEdge;
    switch (constraints) {
    case DungeonLevelBuilder::MoveConstraints::None:

        originEdge = new OpenDoorway();
        destinationEdge = new OpenDoorway();
        break;
    case DungeonLevelBuilder::MoveConstraints::OriginImpassable:

        originEdge = new OneWayDoor();
        if (number == 0){

            destinationEdge = new OpenDoorway();
        }else{
            destinationEdge= new LockedDoor();
        }
        break;
    case DungeonLevelBuilder::MoveConstraints::DestinationImpassable:
        destinationEdge = new OneWayDoor();
        if (number == 0){
            originEdge = new OpenDoorway();
        }else{
            originEdge= new LockedDoor();
        }
        break;
    case DungeonLevelBuilder::MoveConstraints::OriginLocked:
        originEdge = new LockedDoor();
        if (number == 0){

            destinationEdge = new OpenDoorway();
        }else{
            destinationEdge= new OneWayDoor();
        }
        break;
    default:
        destinationEdge = new LockedDoor();
        if (number == 0){
            originEdge = new OpenDoorway();
        }else{
            originEdge= new OneWayDoor();
        }
    }
    switch (direction) {
    case Direction::North:
        origin.setNorthEdge(*originEdge);
        destination.setSouthEdge(*destinationEdge);
        break;
    case Direction::East:
        origin.setEastEdge(*originEdge);
        destination.setWestEdge(*destinationEdge);
        break;
    case Direction::West:
        origin.setWestEdge(*originEdge);
        destination.setEastEdge(*destinationEdge);
        break;
    default:
        origin.setSouthEdge(*originEdge);
        destination.setNorthEdge(*destinationEdge);
    }

}

void BasicDungeonLevelBuilder::buildEntrance(Room &room, Direction direction){
    OneWayDoor oneWay;
    RockWall wall;
    switch (direction) {
    case Direction::North:

        room.setNorthEdge(oneWay);
        room.setWestEdge(wall);
        break;
    default:
        room.setWestEdge(oneWay);
        room.setNorthEdge(wall);
    }
}

void BasicDungeonLevelBuilder::buildExit(Room &room, Direction direction){
    OneWayDoor oneWay;
    RockWall wall;
    switch (direction) {
    case Direction::South:

        room.setSouthEdge(oneWay);
        room.setEastEdge(wall);
        break;
    default:
        room.setEastEdge(oneWay);
        room.setSouthEdge(wall);
    }
    int number = generateRandomNumber(6);
    Item* item;
    if (number == 0){
        item = hpotion.clone();
    }else if (number == 1){
        item = cocktail.clone();
    }else if (number == 2){
        item = bomb.clone();
    }else if (number == 3){
        item = boomerang.clone();
    }else if (number == 4){
        item = sword.clone();
    }else{
        item = axe.clone();
    }
    room.setItem(*item);

    int othernumber = generateRandomNumber(3);
    AbstractCreature* creature;
    if (othernumber == 0){
        creature = goblin.clone();
    }else if (othernumber == 1){
        creature = wizard.clone();
    }else{
        creature = werewolf.clone();
    }
    creature->setBoss(true);
    room.setCreature(*creature);
}

void BasicDungeonLevelBuilder::buildItem(Room &room){
    int number = generateRandomNumber(6);
    Item* item;
    if (number == 0){
        item = hpotion.clone();
    }else if (number == 1){
        item = cocktail.clone();
    }else if (number == 2){
        item = bomb.clone();
    }else if (number == 3){
        item = boomerang.clone();
    }else if (number == 4){
        item = sword.clone();
    }else{
        item = axe.clone();
    }
    room.setItem(*item);

}

void BasicDungeonLevelBuilder::buildCreature(Room &room){
    int othernumber = generateRandomNumber(3);
    AbstractCreature* creature;
    if (othernumber == 0){
        creature = goblin.clone();
    }else if (othernumber == 1){
        creature = wizard.clone();
    }else{
        creature = werewolf.clone();
    }
    creature->setBoss(true);
    room.setCreature(*creature);
}
