#include "item.h"

#include <iostream>

Item::Item(std::string name){
    _name = name;
}

Weapon::Weapon(std::string name){

    _name = name;
}

Item* Weapon::clone() {

    return new Weapon;
}

std::string Item::name(){
    return _name;
}

char Item::displayCharacter(){
    return 'L';
}

Consumable::Consumable(std::string name){

    _name = name;
}

Item* Consumable::clone() {
    return new Consumable;
}


