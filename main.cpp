

#include <iostream>

#include "dungeon.h"
#include "core.h"

using namespace core;
Game* core::Game::the_Instance = 0;

using namespace std;
int main()
{

    MenuInterface interface;
    interface.run();

    return 0;
}
