#include <QCoreApplication>

#include <iomanip>
#include <iostream>
#include <sstream>
#include "roomedge.h"
#include "item.h"
#include "creature.h"
#include "room.h"
#include <vector>
#include "dungeonlevel.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dungeonlevelbuilder.h"
#include "core.h"

Game* Game::the_Instance = 0;

using namespace std;
int main()
{
//    Game::instance()->createExampleLevel();

//    Game::instance()->displayLevel(std::cout);

MenuInterface interface;
interface.run();

//    OneWayDoor oneWay;
//    OpenDoorway open;
//    open.setDirection(Direction::North);


//    RoomEdge* edge = &oneWay;

//    edge->setDirection(Direction::East);

//    cout << edge->description() << "return character " << edge->displayCharacter()<<endl;

//    BlockedDoorway blocked;
//    edge = &blocked;
//    edge->setDirection(Direction::West);
//    cout << edge->description() << "return character " << edge->displayCharacter()<<endl;

//    edge = &open;

//    cout << edge->description() << "return character " << edge->displayCharacter()<<endl;

//    LockedDoor locked;
//    edge = &locked;
//    edge->setDirection(Direction::East);
//    cout << edge->description() << "return character " << edge->displayCharacter()<<endl;

//    RockWall rock;
//    edge = &rock;
//    edge->setDirection(Direction::West);
//    cout << edge->description() << "return character " << edge->displayCharacter()<<endl;

//    MagicWall magic;
//    edge = &magic;
//    edge->setDirection(Direction::South);
//    cout << edge->description() << "return character " << edge->displayCharacter()<<endl;


//    Weapon weapon("sword");
//    Item* item = weapon.clone();
//    cout << item->name() << item->displayCharacter() <<endl;

//    Consumable consumable("iop");
//    item = consumable.clone();
//    cout << item->name() << item->displayCharacter() <<endl;

//    using namespace creature;
//    AbstractCreature* create;
//    Monster monster("阿巴斯");
//    create = monster.clone();
//    cout << create->name() << "   " << create->displayCharacter() << endl;
//    oneWay.connect(open);

//    blocked.connect(blocked);
//    RockChamber rockChamber{1};


//    rockChamber.setItem(*item);
//    rockChamber.setCreature(*create);
//    rockChamber.setEastEdge(magic);
//    rockChamber.setWestEdge(open);
//    rockChamber.setNorthEdge(locked);
//    rockChamber.setSouthEdge(rock);

//    string output = "";

//    cout << rockChamber.description() << endl;
//    for (int i = 0; i < 6; ++i){
//        cout << rockChamber.display()->at(i) << endl;

//    }

//    MagicalDungeonLevel basic{"audan", 3, 3};
//    DungeonLevel* level = &basic;
//    for (int i = 0; i < 9; ++i){
//        level->addRoom(rockChamber);
//    }


//    for (int i = 0; i < 18; ++i){
//        cout << level->display()->at(i) << endl;

//    }

//    cout << basic.description() << endl;

//    MagicalDungeonLevelBuilder builder;
//    builder.buildDungeonLevel("shi", 3, 3);
//    builder.fillLevel();
//    builder.buildEntrance(*builder.getDungeonLevel()->retrieveRoom(0), Direction::North);
//    cout << builder.getDungeonLevel()->retrieveRoom(0)->description() << endl;
//    for (int i = 0; i < 18; ++i){
//        cout << builder.getDungeonLevel()->display()->at(i) << endl;



//    }







}
