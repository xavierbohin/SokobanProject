#ifndef CAN_H
#define CAN_H
#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Target.h"
#include "Item.h"

using namespace std;

class Can : protected Item
{
    public:
        Can(int a, int b);
        void moveup();
        void movedown();
        void moveright();
        void moveleft();
        int closestTarget();
        bool getisontarget();

    protected:
    private:
        bool isontarget;
        void checktarget();
        Item::x;
        Item::y;

};

#endif // CAN_H
