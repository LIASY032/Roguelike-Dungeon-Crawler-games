#ifndef ITEM_H
#define ITEM_H
#include <iostream>

class Item
{
private:
    std::string _name;
public:
    Item(std::string name);
    ~Item() = default;
    virtual Item clone();
    virtual std::string name() = 0;

};


class Weapon : public Item{

};




#endif // ITEM_H
