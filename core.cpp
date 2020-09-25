#include "core.h"


Game* Game::instance(){
    if (!the_Instance){
        the_Instance = new Game();
    }
    return the_Instance;
}

void Game::setDungeonType(DungeonLevelBuilder &_levelBuilder){
    levelBuilder = std::shared_ptr<DungeonLevelBuilder> (&_levelBuilder);
    level = levelBuilder->getDungeonLevel();
    double number = randomDouble();
    if (levelBuilder->generateRandomNumber(2) == 0){
        levelBuilder->buildEntrance(*level->retrieveRoom(0), Direction::North);
    }else{
        levelBuilder->buildEntrance(*level->retrieveRoom(0), Direction::West);
    }

    _levelBuilder.buildCreature(*level->retrieveRoom(0));
    if (levelBuilder->generateRandomNumber(2) == 0){
        levelBuilder->buildExit(*level->retrieveRoom(level->numberOfRooms - 1), Direction::East);
    }else{
        levelBuilder->buildExit(*level->retrieveRoom(level->numberOfRooms - 1), Direction::South);
    }
    int side = level->width() - 1;
    for (int i = 0; i < level->numberOfRooms - 1; ++i){
        int randnumber = levelBuilder->generateRandomNumber(6);
        int otherrand = levelBuilder->generateRandomNumber(6);

        number = randomDouble();
        if (i < (level->numberOfRooms - level->width())){
            if (i == side){
                constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + level->width()), Direction::South, randnumber);
                side = level->width() +side;

            }else{
                constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + level->width()), Direction::South, randnumber);
                constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + 1), Direction::East, otherrand);

            }
        }else{
            constraintHelper(*level->retrieveRoom(i), *level->retrieveRoom(i + 1), Direction::East, randnumber);

        }


    }

    for (int i = 0; i < level->numberOfRooms; ++i){
        std::cout << i << " " << level->retrieveRoom(i)->description() << std::endl;
    }




}

void Game::constraintHelper(Room &origin, Room &destination, Direction direction, int number){
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

void Game::createExampleLevel(){
    levelBuilder = std::shared_ptr<DungeonLevelBuilder> (new BasicDungeonLevelBuilder);

    levelBuilder->buildDungeonLevel("Example", 2, 2);
    level = levelBuilder->getDungeonLevel();
    levelBuilder->buildEntrance(*level->retrieveRoom(0), Direction::North);
    levelBuilder->buildExit(*level->retrieveRoom((level->width() * level->height()) - 1), Direction::East);
    levelBuilder->buildDoorway(*level->retrieveRoom(0), *level->retrieveRoom(2), Direction::South, DungeonLevelBuilder::MoveConstraints::None);

    levelBuilder->buildDoorway(*level->retrieveRoom(0), *level->retrieveRoom(1), Direction::East, DungeonLevelBuilder::MoveConstraints::None);
    levelBuilder->buildDoorway(*level->retrieveRoom(1), *level->retrieveRoom(3), Direction::South, DungeonLevelBuilder::MoveConstraints::OriginImpassable);
}

void Game::displayLevel(std::ostream &display){
    for (int i = 0; i < levelBuilder->getDungeonLevel()->height() * 6; ++i){
        display << level->display()->at(i) << std::endl;

    }

}

double Game::randomDouble(){
    srand(time(0));
    return (double)rand();
}

MenuInterface::MenuInterface(std::ostream &display, std::istream &input){
    std::string option = "";
    std::string name = "";
    int width = 0;
    int height = 0;
    bool quit = true;
    do {
        display << "What would you like to do?\n"
                << "(g)enerate the example level\n"
                << "(r)andom dungeon level\n"
                << "(q)uit" << std::endl;
        input >> option;
        if (option == "g"){
            Game::instance()->createExampleLevel();


        }
        if (option == "r"){
            display << "What would you like to call the level?" << std::endl;
            input >> name;
            display << "How many rows in *" << name << "*?" << std::endl;
            input >> height;
            display << "How many columns in *" << name << "*?" << std::endl;
            input >> width;
            do{
                display << "What type of dungeon level is it? (b)asic or (m)agic" << std::endl;
                input >> option;

                if (option == "b"){
                    builder = new BasicDungeonLevelBuilder();
                    builder->buildDungeonLevel(name, width, height);
                    Game::instance()->setDungeonType(*builder);
                    break;
                }
                if (option == "m"){
                    builder = new MagicalDungeonLevelBuilder();
                    builder->buildDungeonLevel(name, width, height);
                    Game::instance()->setDungeonType(*builder);
                    break;
                }
            }while(true);
            do {
                display << "What would you like to do?\n"
                           "(d)escribe the dungeon level\n"
                           "(v)iew the dungeon level\n"
                           "(r)eturn to the main menu" << std::endl;
                input >> option;
                if (option == "d"){
                    display << builder->getDungeonLevel()->description() << std::endl;
                }
                if (option == "r"){
                    break;
                }
                if (option == "v"){
                    Game::instance()->displayLevel(display);
                    display << "*Press Enter to continue*";

                    if (input.get() == '\n'){
                        do {
                            display << "What would you want to do\n"
                                       "(d)escribe a room\n"
                                       "(r)eturn to previous menu" << std::endl;
                            input >> option;
                            if (option == "d"){
                                do {
                                    display << "Which room would you like to describe? ("
                                            << "1 - " << builder->getDungeonLevel()->numberOfRooms << ")" << std::endl;
                                    input >> option;
                                    if (isdigit(option[0]) && (int)option[0] > 0 && (int) option[0] < builder->getDungeonLevel()->numberOfRooms + 1 ){
                                        int number = (int) option[0];
                                        builder->getDungeonLevel()->retrieveRoom(number - 1)->description();
                                        break;
                                    }
                                }while (true);

                            }
                            if (option == "r"){
                                break;
                            }
                        }while (true);
                    }

                }

            }while (true);


        }
        if (option == "q"){
            display << "*Are you sure you want to quit? (y/n)" << std::endl;
            input >> option;
            if (option == "y"){
                quit = false;
            }
        }
    } while(quit);


}

void MenuInterface::displayWelcome(std::string author, std::string title){
    std::cout << "Welcome to: " << title << "\n\t\tDeveloped by " << author << "\n\t COMP 3023 Software Development with C++" << std::endl;
}

void MenuInterface::run(){
    displayWelcome();
    MenuInterface(std::cout, std::cin);
}

