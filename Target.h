#ifndef TARGET_H
#define TARGET_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Item.h"
#include "Common.h"

using namespace std;

class Target : public Item
{
    public:
        Target(int a, int b);
    /*protected:
    private:*/
        Item::x;
        Item::y;
};

#endif // TARGET_H
