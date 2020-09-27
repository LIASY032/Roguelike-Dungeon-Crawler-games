#include "core.h"



using namespace core::dungeon::items;
using namespace core::dungeon;
using namespace core::dungeon::basic;
using namespace core::dungeon::common;
using namespace core::dungeon::magical;
using namespace core;

Game* core::Game::instance(){
    if (!the_Instance){
        the_Instance = new Game();
    }
    return the_Instance;
}


void core::Game::setDungeonType(DungeonLevelBuilder &_levelBuilder){
    levelBuilder = std::shared_ptr<DungeonLevelBuilder> (&_levelBuilder);


}


void core::Game::constraintHelper(Room &origin, Room &destination, Direction direction, int number){
    if (number == 0){
        levelBuilder->buildDoorway(origin, destination, direction, DungeonLevelBuilder::MoveConstraints::None);
    }else if (number == 1){
        levelBuilder->buildDoorway(origin, destination, direction, DungeonLevelBuilder::MoveConstraints::OriginLocked);
    }else if (number == 2){
        levelBuilder->buildDoorway(origin, destination, direction, DungeonLevelBuilder::MoveConstraints::OriginImpassable);
    }else if (number == 3){
        levelBuilder->buildDoorway(origin, destination, direction, DungeonLevelBuilder::MoveConstraints::Destinationlocked);
    }else{
        levelBuilder->buildDoorway(origin, destination, direction, DungeonLevelBuilder::MoveConstraints::DestinationImpassable);
    }
}


void core::Game::createExampleLevel(){
    levelBuilder = std::shared_ptr<DungeonLevelBuilder> (new BasicDungeonLevelBuilder);

    levelBuilder->buildDungeonLevel("Example", 2, 2);
    level = levelBuilder->getDungeonLevel();
    levelBuilder->buildEntrance(*level->retrieveRoom(0), Direction::North);
    levelBuilder->buildExit(*level->retrieveRoom((level->width() * level->height()) - 1), Direction::East);
    levelBuilder->buildDoorway(*level->retrieveRoom(0), *level->retrieveRoom(2), Direction::South, DungeonLevelBuilder::MoveConstraints::DestinationImpassable);

    levelBuilder->buildDoorway(*level->retrieveRoom(2), *level->retrieveRoom(3), Direction::East, DungeonLevelBuilder::MoveConstraints::DestinationImpassable);
    levelBuilder->buildDoorway(*level->retrieveRoom(0), *level->retrieveRoom(1), Direction::East, DungeonLevelBuilder::MoveConstraints::None);
    levelBuilder->buildDoorway(*level->retrieveRoom(1), *level->retrieveRoom(3), Direction::South, DungeonLevelBuilder::MoveConstraints::None);
}

void Game::createRandomLevel(std::string name, int witch, int height){

    levelBuilder->buildDungeonLevel(name, witch, height);
    level = levelBuilder->getDungeonLevel();
    double number = randomDouble();

    //create the level's entrance
    if (levelBuilder->generateRandomNumber(2) == 0){
        levelBuilder->buildEntrance(*level->retrieveRoom(0), Direction::North);
    }else{
        levelBuilder->buildEntrance(*level->retrieveRoom(0), Direction::West);
    }

    //create the exit room and it should have a boss monster and an item.
    if (levelBuilder->generateRandomNumber(2) == 0){
        levelBuilder->buildExit(*level->retrieveRoom(level->numberOfRooms - 1), Direction::East);
    }else{
        levelBuilder->buildExit(*level->retrieveRoom(level->numberOfRooms - 1), Direction::South);
    }
    

    /**
     * @brief side store the side number
     * example
     * 1 1 2
     * 1 1 2
     * 3 3 4
     * it record the number 2
     */
    int side = level->width() - 1;

    bool leftdowncorner = true;
    //according above the diagram to modify the room
    for (int i = 0; i < level->numberOfRooms - 1; ++i){
        
        int randnumber = randomDouble();
        int otherrand = randomDouble();
        double buildornot = randomDouble();
        double randomitem = randomDouble();
        double randomMonster = randomDouble();
        number = randomDouble();


        if (i < (level->numberOfRooms - level->width())){
            //modify 2's room south
            if (i == side){
                //if this room's west edge is passage
                if (level->retrieveRoom(i)->getWestEdge()->isPassage()){
                    if (buildornot > 2.5){
                        constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + level->width()), Direction::South, randnumber);
                    }
                }else{
                    constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + level->width()), Direction::South, randnumber);
                }
                side = level->width() +side;

            }else{//modify 1's room east edge or south edge
                //if the room's north and west is not passage

                if (buildornot >= 2 && buildornot < 4){
                    constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + level->width()), Direction::South, randnumber);
                    constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + 1), Direction::East, otherrand);
                }else if (buildornot < 5 && buildornot >= 4) {
                    constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + level->width()), Direction::South, randnumber);
                }else{
                    constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + 1), Direction::East, otherrand);

                }
            }
        }else{//modify 3's room east edge

            if (leftdowncorner){
                if (buildornot > 2.5){
                    constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + 1), Direction::East, randnumber);
                }
                //if the left down corner's north is not passage, next room's north is not passage, and the east is not passage
                if (!level->retrieveRoom(i)->getNorthEdge()->isPassage() && !level->retrieveRoom(i + 1)->getNorthEdge()->isPassage() && !level->retrieveRoom(i)->getEastEdge()->isPassage()){
                    constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + 1), Direction::East, randnumber);
                    constraintHelper(*level->retrieveRoom(i - level->width()), *level->retrieveRoom(i ), Direction::South, randnumber);
                }

                if (!level->retrieveRoom(i + 1)->getWestEdge()->isPassage() && level->retrieveRoom(i + 1)->getNorthEdge()->isPassage() && !level->retrieveRoom(i)->getNorthEdge()->isPassage()){
                    constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + 1), Direction::East, randnumber);
                }
                leftdowncorner = false;

            }else{
                if (level->retrieveRoom(i)->getNorthEdge()->isPassage()){
                    if (buildornot > 2.5){
                        constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + 1), Direction::East, randnumber);
                    }
                }else{
                    constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + 1), Direction::East, randnumber);
                }
            }

        }



        //randomly create items
        if (randomitem >= 2.5){
            levelBuilder->buildItem(*level->retrieveRoom(i));
        }
        //randomly create monsters, but the entrance room must not have a monster

        if (i != 0 && randomMonster >= 2.5){
            levelBuilder->buildCreature(*level->retrieveRoom(i));
        }
    }
    
    if (level->height() != 1){
        if (!level->retrieveRoom(level->numberOfRooms - 1)->getWestEdge()->isPassage() && !level->retrieveRoom(level->numberOfRooms - 1)->getNorthEdge()->isPassage()){
            if (randomDouble() >= 2.5){
                constraintHelper(*level->retrieveRoom(level->numberOfRooms - 2), *level->retrieveRoom(level->numberOfRooms - 1), Direction::East, randomDouble());
            }else{
                constraintHelper(*level->retrieveRoom(level->numberOfRooms - level->width()), *level->retrieveRoom(level->numberOfRooms - 1), Direction::South, randomDouble());
            }
        }
    }
    
}

void Game::displayLevel(std::ostream &display){
    for (int i = 0; i < levelBuilder->getDungeonLevel()->height() * 6; ++i){
        display << level->display()->at(i) << std::endl;

    }

}

double Game::randomDouble(){
    static std::default_random_engine generator(unsigned(time(nullptr)));
    std::uniform_real_distribution<double> distribution(0, 5);
    return distribution(generator);
}
void Game::descriptionLevel(std::ostream &display){
    display <<"\n" << level->description() << "\n" << std::endl;
}

DungeonLevel* Game::getLevel(){
    return level;
}

bool MenuInterface::isNumber(std::string &input){
    for (int i = 0; i < input.length(); i++)
        if (isdigit(input[i]) == false)
            return false;

    return true;
}



void MenuInterface::viewMenu(std::ostream &display, std::istream &input){
    std::string option = "";
    do {
        display << "\nWhat would you like to do?\n"
                   "(d)escribe the dungeon level\n"
                   "(v)iew the dungeon level\n"
                   "(r)eturn to the main menu\n> ";
        input >> option;
        if (option == "d"){
            Game::instance()->descriptionLevel(display);
        }
        if (option == "r"){
            break;
        }
        if (option == "v"){
            Game::instance()->displayLevel(display);
            display << "\n*Press Enter to continue*\n> ";
            fgetc(stdin);
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            do {

                std::string exploration;
                display << "\nWhat would you want to do\n"
                           "(d)escribe a room\n"
                           "(r)eturn to previous menu\n> ";
                input >> exploration;
                bool quit = true;

                if (exploration == "d"){
                    do{
                        display << "\nWhich room would you like to describe? ("
                                << "1 - " << Game::instance()->getLevel()->numberOfRooms << ")\n> ";
                        input >> option;
                        if (isNumber(option)){
                            //describes the room
                            int number = std::stoi(option);
                            if (number > 0 && number <= Game::instance()->getLevel()->numberOfRooms){
                                display << Game::instance()->getLevel()->retrieveRoom(number - 1)->description() << std::endl;
                                quit = false;
                            }else{
                                display << "\nPlease enter the number\n";
                            }
                        }
                    } while(quit);

                }
                if (exploration == "r"){
                    break;
                }
            }while (true);

        }

    }while (true);
}

MenuInterface::MenuInterface(std::ostream &display, std::istream &input){
    std::string option = "";
    std::string name = "";
    int width = 0;
    int height = 0;
    bool quit = true;
    do {
        display << "\nWhat would you like to do?\n"
                << "(g)enerate the example level\n"
                << "(r)andom dungeon level\n"
                << "(q)uit\n> ";
        input >> option;
        if (option == "g"){
            Game::instance()->createExampleLevel();
            viewMenu(display, input);
        }
        if (option == "r"){
            do {
                display << "\nWhat would you like to call the level?\n> ";
                input >> name;
                if (name != ""){
                    break;
                }
            }while (true);

            //enter the height
            bool quit1 = true;
            do {
                display << "\nHow many rows in *" << name << "*?\n> ";
                input >> option;
                if (isNumber(option)){
                    //convert a string to int
                    height = std::stoi(option);

                    //only allows enter 2 - 4
                    if (height >= 1 && height < 5){
                        quit1 = false;

                    }else{
                        display << "Only allows to enter 1 - 4\n";
                    }
                }else{
                    display << "\nPlease enter the number\n";
                }

            }while(quit1);

            // enter the width
            quit1 = true;
            do {
                display << "\nHow many columns in *" << name << "*?\n> ";
                input >> option;
                if (isNumber(option)){
                    width = std::stoi(option);
                    if (width >= 1 && width < 5){
                        quit1 = false;

                    }else{
                        display << "Only allows to enter 1 - 4\n";
                    }
                }else{
                    display << "\nPlease enter the number\n";
                }
            }while (quit1);


            //choose which types of dungeon level user want to
            do{
                display << "\nWhat type of dungeon level is it? (b)asic or (m)agic\n> ";
                input >> option;

                if (option == "b"){
                    Game::instance()->setDungeonType(*new BasicDungeonLevelBuilder());
                    Game::instance()->createRandomLevel(name, width, height);
                    break;
                }
                if (option == "m"){
                    Game::instance()->setDungeonType(*new MagicalDungeonLevelBuilder());
                    Game::instance()->createRandomLevel(name, width, height);
                    break;
                }
            }while(true);
            viewMenu(display, input);

        }

        //quit the while loop
        if (option == "q"){
            display << "\n*Are you sure you want to quit? (y/n)\n> ";
            input >> option;
            if (option == "y"){
                quit = false;
            }
        }
    } while(quit);
    display << "\n\nGoodbye!" << std::endl;


}

void MenuInterface::displayWelcome(std::string author, std::string title){
    std::cout << "Welcome to: " << title << "\n\t\tDeveloped by " << author << "\n\t COMP 3023 Software Development with C++" << std::endl;
}

void MenuInterface::run(){
    displayWelcome();
    MenuInterface(std::cout, std::cin);
}

