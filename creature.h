#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>

namespace creature{
    class AbstractCreature{
    public:
        AbstractCreature() = default;
        AbstractCreature(std::string name);
        virtual ~AbstractCreature() = default;
        virtual AbstractCreature* clone() = 0;
        virtual std::string name() = 0;
        virtual char displayCharacter() = 0;
    private:
        std::string _name;
    };

    class Monster : public AbstractCreature{
    public:
        Monster() = default;
        Monster(std::string name);
        AbstractCreature* clone() override;
        std::string name() override;
        char displayCharacter() override;
    private:
        std::string _name;
    };


};

#endif // CREATURE_H
