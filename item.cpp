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

std::string Weapon::name(){
    return _name;
}

Consumable::Consumable(std::string name){

    _name = name;
}

Item* Consumable::clone() {
    return new Consumable;
}

std::string Consumable::name(){
    return _name;
}
