#include "creature.h"

#include <iostream>

using namespace creature;

AbstractCreature::AbstractCreature(std::string name){
    _name = name;
}

Monster::Monster(std::string name){
    _name = name;
}

AbstractCreature* Monster::clone(){
    return new Monster(_name);
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




