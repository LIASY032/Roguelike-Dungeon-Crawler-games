#include "creature.h"

#include <iostream>

using namespace creature;

AbstractCreature::AbstractCreature(std::string name){
    _name = name;
}

AbstractCreature::AbstractCreature(std::string name, bool boss){
    _name= name;
    setBoss(boss);
}

Monster::Monster(std::string name){
    _name = name;
}

Monster::Monster(std::string name, bool boss){
    _name= name;
    setBoss(boss);
}

AbstractCreature* Monster::clone(){
    return new Monster(_name);
}

AbstractCreature* Monster::clone(bool boss){
    return new Monster(_name, boss);
}

void AbstractCreature::setBoss(bool _boss){
    boss = _boss;
}

bool AbstractCreature::getBoss(){
    return boss;
}

char AbstractCreature::displayCharacter(){
    return _character;
}


std::string Monster::name(){
    return _name;
}




