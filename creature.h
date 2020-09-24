#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>

namespace creature{
    class AbstractCreature{
    public:
        AbstractCreature() = default;
        AbstractCreature(std::string name);
        AbstractCreature(std::string name, bool boss);
        virtual ~AbstractCreature() = default;
        virtual AbstractCreature* clone() = 0;
        virtual AbstractCreature* clone(bool boss) = 0;
        virtual std::string name() = 0;
        char displayCharacter();
        bool getBoss();
        void setBoss(bool _boss);
    protected:
        std::string _name;
        bool boss = false;
        char _character ='M';
    };

    class Monster : public AbstractCreature{
    public:
        Monster() = default;
        Monster(std::string name);
        Monster(std::string name, bool boss);
        AbstractCreature* clone() override;
        AbstractCreature * clone(bool boss) override;
        std::string name() override;

    };


};

#endif // CREATURE_H
