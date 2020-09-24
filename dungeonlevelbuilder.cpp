#include "dungeonlevelbuilder.h"


DungeonLevel* DungeonLevelBuilder::getDungeonLevel(){

    return level.get();
}

int DungeonLevelBuilder::generateRandomNumber(int number){
    srand(time(0));
    return rand()%number;
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
    originEdge.connect(destinationEdge);
}

void MagicalDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height){


    level = std::unique_ptr<DungeonLevel> (new MagicalDungeonLevel{name, width, height});

    for (int i = 0; i < level->numberOfRooms; ++i){

        level->initializeRoom(*buildRoom(i));
    }

}



Room* MagicalDungeonLevelBuilder::buildRoom(int id){
    int number = generateRandomNumber(2);
    if (number == 0){
        return new EnchantedLiboratory(id);

    }else{

        return new AlchemistsLaboratory(id);
    }

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
            buildDoorwayHelper(destination, origin, *new BlockedDoorway(), *new BlockedDoorway(), direction);
        }else{
            if (number == 0){
                buildDoorwayHelper(destination, origin, *new OneWayDoor(), *new LockedDoor(), direction);
            }else{
                buildDoorwayHelper(destination, origin, *new OneWayDoor(), *new OpenDoorway(),direction);
            }
        }

        break;
    case DungeonLevelBuilder::MoveConstraints::OriginLocked:
        if (lock == 0){
            buildDoorwayHelper(destination, origin, *new LockedDoor(),*new OpenDoorway(), direction);
        }else if (lock == 1){
            buildDoorwayHelper(destination, origin,*new LockedDoor(), *new OneWayDoor(),direction);
        }else{
            buildDoorwayHelper(destination, origin,*new LockedDoor(), *new LockedDoor(),direction);
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



void MagicalDungeonLevelBuilder::buildEntrance(Room &room, Direction direction){

    switch (direction) {
    case Direction::North:

        room.setNorthEdge(*new OneWayDoor());
        break;
    default:
        room.setWestEdge(*new OneWayDoor());
    }
}

void MagicalDungeonLevelBuilder::buildExit(Room &room, Direction direction){
    switch (direction) {
    case Direction::South:

        room.setSouthEdge(*new OneWayDoor());

        break;
    default:
        room.setEastEdge(*new OneWayDoor());

    }
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
    int number = generateRandomNumber(3);

    if (number == 0){
        room.setCreature(*goblin.clone());
    }else if (number == 1){
        room.setCreature(*wizard.clone());
    }else{
        room.setCreature(*dragon.clone());
    }
}

void BasicDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height){

    level = std::unique_ptr<DungeonLevel> (new BasicDungeonLevel{name, width, height});
    for (int i = 0; i < level->numberOfRooms; ++i){

        level->initializeRoom(*buildRoom(i));
    }
}



Room* BasicDungeonLevelBuilder::buildRoom(int id){
    int number = generateRandomNumber(2);
    if (number == 0){
        return new RockChamber(id);

    }else{

        return new QuartzChamber(id);
    }
}



void BasicDungeonLevelBuilder::buildEntrance(Room &room, Direction direction){
    switch (direction) {
    case Direction::North:

        room.setNorthEdge(*new OneWayDoor());
        break;
    default:
        room.setWestEdge(*new OneWayDoor());
    }
}

void BasicDungeonLevelBuilder::buildExit(Room &room, Direction direction){
    switch (direction) {
    case Direction::South:

        room.setSouthEdge(*new OneWayDoor());

        break;
    default:
        room.setEastEdge(*new OneWayDoor());

    }
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
    int othernumber = generateRandomNumber(3);
    if (othernumber == 0){
        room.setCreature(*goblin.clone());
    }else if (othernumber == 1){
        room.setCreature(*wizard.clone());
    }else{
        room.setCreature(*werewolf.clone());
    }
}
