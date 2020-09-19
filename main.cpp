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
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>


using namespace std;
int main()
{
    OneWayDoor oneWay;
    OpenDoorway open;
    open.setDirection(Direction::North);


    RoomEdge* edge = &oneWay;

    edge->setDirection(Direction::East);

    cout << edge->description() << "return character " << edge->displayCharacter()<<endl;

    BlockedDoorway blocked;
    edge = &blocked;
    edge->setDirection(Direction::West);
    cout << edge->description() << "return character " << edge->displayCharacter()<<endl;

    edge = &open;

    cout << edge->description() << "return character " << edge->displayCharacter()<<endl;

    LockedDoor locked;
    edge = &locked;
    edge->setDirection(Direction::East);
    cout << edge->description() << "return character " << edge->displayCharacter()<<endl;

    RockWall rock;
    edge = &rock;
    edge->setDirection(Direction::West);
    cout << edge->description() << "return character " << edge->displayCharacter()<<endl;

    MagicWall magic;
    edge = &magic;
    edge->setDirection(Direction::South);
    cout << edge->description() << "return character " << edge->displayCharacter()<<endl;


    Weapon weapon("sword");
    Item* item = weapon.clone();
    cout << item->name() << item->displayCharacter() <<endl;

    Consumable consumable("iop");
    item = consumable.clone();
    cout << item->name() << item->displayCharacter() <<endl;

    using namespace creature;
    AbstractCreature* create;
    Monster monster("阿巴斯");
    create = monster.clone();
    cout << create->name() << "   " << create->displayCharacter() << endl;
    oneWay.connect(open);

    blocked.connect(blocked);
    RockChamber rockChamber{1};
    rockChamber.setItem(*item);
    rockChamber.setCreature(*create);
    rockChamber.setEastEdge(blocked);
    rockChamber.setWestEdge(open);
    rockChamber.setNorthEdge(locked);
    rockChamber.setSouthEdge(oneWay);

    string output = "";

    for (int i = 0; i < 6; ++i){
        cout << rockChamber.display()->at(i) << endl;

    }




    BasicDungeonLevel basic{"audan", 3, 3};
    basic.addRoom(rockChamber);
    basic.addRoom(rockChamber);
    basic.addRoom(rockChamber);
    basic.addRoom(rockChamber);
    basic.addRoom(rockChamber);
    basic.addRoom(rockChamber);
    basic.addRoom(rockChamber);
    basic.addRoom(rockChamber);
    basic.addRoom(rockChamber);

    for (int i = 0; i < 18; ++i){
        cout << basic.display()->at(i) << endl;

    }

    cout << basic.description() << endl;
    srand(time(0));

    for(int i = 0; i<4; i++)
        printf(" %d ", rand());
    return 0;

}
