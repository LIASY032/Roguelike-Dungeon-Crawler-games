#include "item.h"

#include <iostream>

Item::Item(std::string name){
    _name = name;
    _character = 'L';
}

Weapon::Weapon(std::string name){

    _character = 'L';
    _name = name;
}

Item* Weapon::clone() {

    return new Weapon(_name);
}

std::string Item::name(){
    return _name;
}

char Item::displayCharacter(){
    return _character;
}

Consumable::Consumable(std::string name){

    _character = 'L';
    _name = name;
}

Item* Consumable::clone() {
    return new Consumable(_name);
}


