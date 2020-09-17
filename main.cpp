#include <QCoreApplication>

#include <iomanip>
#include <iostream>
#include <sstream>
#include "roomedge.h"
#include "item.h"
#include "creature.h"
#include "room.h"
#include <vector>


using namespace std;
int main()
{
    OneWayDoor oneWay;
    OpenDoorway open;
    open.setDirection(Direction::North);


    RoomEdge* edge = &oneWay;

    edge->setDirection(Direction::East);
//    oneWay.connect(open);
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

    create->setBoss(true);


    RockChamber rockChamber{1};
    rockChamber.setItem(*item);
    rockChamber.setCreature(*create);
    rockChamber.setEastEdge(oneWay);
    rockChamber.setWestEdge(open);
    rockChamber.setNorthEdge(locked);
    rockChamber.setSouthEdge(blocked);
    string display = "";

    for (int i = 0; i < 5; ++i){
        cout << rockChamber.display()->at(i) << endl;
    }
    cout << display << endl;
    return 0;

}
