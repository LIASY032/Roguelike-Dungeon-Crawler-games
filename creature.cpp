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
    return new Monster;
}

std::string Monster::name(){
    return _name;
}


//need to be fixed later
char Monster::displayCharacter(){
    return 's';
}
