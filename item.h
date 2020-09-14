#ifndef ITEM_H
#define ITEM_H
#include <iostream>




class Item
{
protected:
    std::string _name;
public:
    Item() = default;
    Item(std::string name);
    virtual ~Item() = default;
    virtual Item* clone() = 0;
    std::string name();
    char displayCharacter();

};

class Weapon : public Item{
public:
    Weapon() = default;
    Weapon(std::string name);
    Item* clone() override;

};


class Consumable: public Item{
public:
    Consumable() = default;
    Consumable(std::string name);
    Item* clone() override;

};




#endif // ITEM_H
