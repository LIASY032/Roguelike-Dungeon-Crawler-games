#ifndef ITEM_H
#define ITEM_H
#include <iostream>




class Item
{
private:
    std::string _name;
public:
    Item() = default;
    Item(std::string name);
    virtual ~Item() = default;
    virtual Item* clone() = 0;
    virtual std::string name() = 0;

};

class Weapon : public Item{
public:
    Weapon() = default;
    Weapon(std::string name);
    Item* clone() override;
    std::string name() override;
private:
    std::string _name;
};


class Consumable: public Item{
public:
    Consumable() = default;
    Consumable(std::string name);
    Item* clone() override;
    std::string name() override;
private:
    std::string _name;
};




#endif // ITEM_H
