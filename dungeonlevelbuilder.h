#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H
#include <iostream>
#include "room.h"
#include "dungeonlevel.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

class DungeonLevelBuilder{
public:

    enum class MoveConstraints: unsigned{
        None = 0,
        OriginImpassable = 1,
        DestinationImpassable = 2,
        OriginLocked = 4,
        Destinationlocked = 8
    };

    DungeonLevelBuilder() = default;
    virtual ~DungeonLevelBuilder() = default;
    virtual void buildDungeonLevel(std::string name, int width, int height);
    virtual Room* buildRoom(int id);
    virtual void buildDoorway(Room &origin, Room &destination, Direction direction, DungeonLevelBuilder::MoveConstraints constraints);
    virtual void buildEntrance(Room &room, Direction direction);
    virtual void buildExit(Room &room, Direction direction);
    virtual void buildItem(Room &room);
    virtual void buildCreature(Room &room);
    DungeonLevel* getDungeonLevel();
    int generateRandomNumber(int number);
protected:

    DungeonLevel* level;
    Consumable hpotion{"Health Potion"};
    Consumable cocktail{"Molotov Cocktail"};
    Consumable rpotion{"Resistance potion"};
    Weapon boomerang{"Boomerang"};
    Weapon staff{"Wizard's Staff"};
    Weapon wand{"Magic Wand"};
    Consumable bomb{"Smoke Bomb"};
    Weapon sword{"Short Sword"};
    Weapon axe{"Battle Axe"};
    Monster goblin{"Goblin"};
    Monster werewolf{"Werewolf"};
    Monster wizard{"Evil Wizard"};
    Monster dragon{"Dragon"};

};

class MagicalDungeonLevelBuilder: public DungeonLevelBuilder{
public:
    MagicalDungeonLevelBuilder() = default;
    void buildDungeonLevel(std::string name, int width, int height) override;
    Room* buildRoom(int id) override;
    void buildDoorway(Room &origin, Room &destination, Direction direction, DungeonLevelBuilder::MoveConstraints constraints) override;
    void buildEntrance(Room &room, Direction direction) override;
    void buildExit(Room &room, Direction direction) override;
    void buildItem(Room &room) override;
    void buildCreature(Room &room) override;
};

class BasicDungeonLevelBuilder: public DungeonLevelBuilder{
public:
    BasicDungeonLevelBuilder() = default;
    void buildDungeonLevel(std::string name, int width, int height) override;
    Room* buildRoom(int id) override;
    void buildDoorway(Room &origin, Room &destination, Direction direction, DungeonLevelBuilder::MoveConstraints constraints) override;
    void buildEntrance(Room &room, Direction direction) override;
    void buildExit(Room &room, Direction direction) override;
    void buildItem(Room &room) override;
    void buildCreature(Room &room) override;
};

#endif // DUNGEONLEVELBUILDER_H
