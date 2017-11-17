#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Item.h"
#include "Player.h"

using namespace std;

class Player : public Item
{
    public:
        Player(int a, int b);
        void moveup();
        void movedown();
        void moveright();
        void moveleft();
        /*int Item::getx();
        int Item::gety();
        void Item::setx(int a);
        void Item::sety(int a);*/

    /*protected:

    private:*/
        Item::x;
        Item::y;


};

#endif // PLAYER_H
