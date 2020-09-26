//#include "basic.h"
//using namespace core::dungeon::basic;
//using namespace core::dungeon::common;

//RockWall::RockWall(){
//    _description = "Rock Wall.";
//}

//RockChamber::RockChamber(int id){
//    _id = id;
//    _description = "A dark and empty chamber. (Rock Chamber)";
//    //initializes the room is around the rock wall
//    setEastEdge(*new RockWall());
//    setWestEdge(*new RockWall());
//    setNorthEdge(*new RockWall());
//    setSouthEdge(*new RockWall());
//}

//QuartzChamber::QuartzChamber(int id){
//    _id = id;
//    _description = "A chamber that glitters like a "
//                   "thousand stars in the torchlight. (Quartz Chamber)";
//    //initializes the room is around the rock wall
//    setEastEdge(*new RockWall());
//    setWestEdge(*new RockWall());
//    setNorthEdge(*new RockWall());
//    setSouthEdge(*new RockWall());
//}

//BasicDungeonLevel::BasicDungeonLevel(std::string name, int width, int height){
//    _name = name;
//    _width = width;
//    _height = height;
//    numberOfRooms = width * height;
//    rooms.resize(width * height);
//}

//std::string BasicDungeonLevel::description(){
//    std::string w = std::to_string(_width);
//    std::string h = std::to_string(_height);
//    return _name + '\n' + "Size: " + w + " x " + h + '\n' + "Type: Dark Cave (Basic Dungeon)";

//}

//void BasicDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height){

//    level = std::unique_ptr<DungeonLevel> (new BasicDungeonLevel{name, width, height});

//     //initializes the level, the four directions of the rooms are rock walls
//    for (int i = 0; i < level->numberOfRooms; ++i){

//        level->initializeRoom(*buildRoom(i));
//    }
//}



//Room* BasicDungeonLevelBuilder::buildRoom(int id){
//    int number = generateRandomNumber(2);

//      //randomlt generates the room
//    if (number == 0){
//        return new RockChamber(id);

//    }else{

//        return new QuartzChamber(id);
//    }
//}



//void BasicDungeonLevelBuilder::buildEntrance(Room &room, Direction direction){
//    //the enterance only has two direction, either North or west
//    switch (direction) {
//    case Direction::North:

//        room.setNorthEdge(*new OneWayDoor());
//        break;
//    default:
//        room.setWestEdge(*new OneWayDoor());
//    }
//}

//void BasicDungeonLevelBuilder::buildExit(Room &room, Direction direction){
//     //the exit only has two direction, either south or east
//    switch (direction) {
//    case Direction::South:

//        room.setSouthEdge(*new OneWayDoor());

//        break;
//    default:
//        room.setEastEdge(*new OneWayDoor());

//    }
//    //the exit room should have a boss and an item
//    int number = generateRandomNumber(6);
//    if (number == 0){
//        room.setItem(*hpotion.clone());
//    }else if (number == 1){
//        room.setItem(*cocktail.clone());
//    }else if (number == 2){
//        room.setItem(*bomb.clone());
//    }else if (number == 3){
//        room.setItem(*boomerang.clone());
//    }else if (number == 4){
//        room.setItem(*sword.clone());
//    }else{
//        room.setItem(*axe.clone());
//    }

//    int othernumber = generateRandomNumber(3);
//    if (othernumber == 0){
//        room.setCreature(*goblin.clone(true));
//    }else if (othernumber == 1){
//        room.setCreature(*wizard.clone(true));
//    }else{
//        room.setCreature(*werewolf.clone(true));
//    }
//}

//void BasicDungeonLevelBuilder::buildItem(Room &room){
//    int number = generateRandomNumber(6);
//    //randomly create an item
//    if (number == 0){
//        room.setItem(*hpotion.clone());
//    }else if (number == 1){
//        room.setItem(*cocktail.clone());
//    }else if (number == 2){
//        room.setItem(*bomb.clone());
//    }else if (number == 3){
//        room.setItem(*boomerang.clone());
//    }else if (number == 4){
//        room.setItem(*sword.clone());
//    }else{
//        room.setItem(*axe.clone());
//    }

//}

//void BasicDungeonLevelBuilder::buildCreature(Room &room){
//    //randomly create a monster
//    int othernumber = generateRandomNumber(3);
//    if (othernumber == 0){
//        room.setCreature(*goblin.clone());
//    }else if (othernumber == 1){
//        room.setCreature(*wizard.clone());
//    }else{
//        room.setCreature(*werewolf.clone());
//    }
//}

