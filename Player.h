#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Item.h"
#include "Player.h"

using namespace std;

class Player : protected Item
{
    public:
        Player();
        void moveup();
        void movedown();
        void moveright();
        void moveleft();
        Item::getx();
        Item::gety();
        Item::setx(int a);
        Item::sety(int a);

    protected:

    private:
        Item::x;
        Item::y;


};

#endif // PLAYER_H
