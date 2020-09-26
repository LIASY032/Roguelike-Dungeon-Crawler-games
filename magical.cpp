//#include "magical.h"


//using namespace core::dungeon::basic;
//using namespace core::dungeon::items;
//using namespace core::dungeon::common;
//using namespace core::dungeon::magical;

//MagicWall::MagicWall(){

//    _description = "Magic Wall.";
//}

//AlchemistsLaboratory::AlchemistsLaboratory(int id){
//    _id = id;
//    _description = "An Alchemists Laboratory";

//    //initializes the room is around the magic wall
//    setEastEdge(*new MagicWall());
//    setWestEdge(*new MagicWall());
//    setNorthEdge(*new MagicWall());
//    setSouthEdge(*new MagicWall());
//}

//EnchantedLiboratory::EnchantedLiboratory(int id){
//    _id = id;
//    _description = "An Enchanted Liboratory";

//    //initializes the room is around the magic wall
//    setEastEdge(*new MagicWall());
//    setWestEdge(*new MagicWall());
//    setNorthEdge(*new MagicWall());
//    setSouthEdge(*new MagicWall());
//}




//MagicalDungeonLevel::MagicalDungeonLevel(std::string name, int width, int height){
//    _name = name;
//    _width = width;
//    _height = height;
//    numberOfRooms = width * height;

//    rooms.resize(width * height);
//}

//std::string MagicalDungeonLevel::description(){
//    std::string w = std::to_string(_width);
//    std::string h = std::to_string(_height);
//    return name() + '\n' + "Size: " + w + " x " + h + '\n' + "Type: Dark Cave (Magical Dungeon)";

//}

//void MagicalDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height){


//    level = std::unique_ptr<DungeonLevel> (new MagicalDungeonLevel{name, width, height});


//    //initializes the level, the four directions of the rooms are magic walls
//    for (int i = 0; i < level->numberOfRooms; ++i){

//        level->initializeRoom(*buildRoom(i));
//    }

//}



//Room* MagicalDungeonLevelBuilder::buildRoom(int id){
//    int number = generateRandomNumber(2);

//    //randomlt generates the room
//    if (number == 0){
//        return new EnchantedLiboratory(id);

//    }else{

//        return new AlchemistsLaboratory(id);
//    }

//}



//void MagicalDungeonLevelBuilder::buildEntrance(Room &room, Direction direction){

//    //the enterance only has two direction, either North or west
//    switch (direction) {
//    case Direction::North:

//        room.setNorthEdge(*new OneWayDoor());
//        break;
//    default:
//        room.setWestEdge(*new OneWayDoor());
//    }
//}

//void MagicalDungeonLevelBuilder::buildExit(Room &room, Direction direction){
//    //the exit only has two direction, either south or east
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
//        room.setItem(*rpotion.clone());
//    }else if (number == 3){
//        room.setItem(*boomerang.clone());
//    }else if (number == 4){
//        room.setItem(*staff.clone());
//    }else{
//        room.setItem(*wand.clone());
//    }

//    int othernumber = generateRandomNumber(3);
//    if (othernumber == 0){
//        room.setCreature(*goblin.clone(true));
//    }else if (othernumber == 1){
//        room.setCreature(*wizard.clone(true));
//    }else{
//        room.setCreature(*dragon.clone(true));
//    }


//}

//void MagicalDungeonLevelBuilder::buildItem(Room &room){
//    int number = generateRandomNumber(6);

//    //randomly create an item
//    if (number == 0){
//        room.setItem(*hpotion.clone());
//    }else if (number == 1){
//        room.setItem(*cocktail.clone());
//    }else if (number == 2){
//        room.setItem(*rpotion.clone());
//    }else if (number == 3){
//        room.setItem(*boomerang.clone());
//    }else if (number == 4){
//        room.setItem(*staff.clone());
//    }else{
//        room.setItem(*wand.clone());
//    }
//}

//void MagicalDungeonLevelBuilder::buildCreature(Room &room){
//    //randomly create a monster
//    int number = generateRandomNumber(3);

//    if (number == 0){
//        room.setCreature(*goblin.clone());
//    }else if (number == 1){
//        room.setCreature(*wizard.clone());
//    }else{
//        room.setCreature(*dragon.clone());
//    }
//}

