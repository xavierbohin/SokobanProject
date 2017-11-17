#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Item
{
    public:
        int getx();
        int gety();
        void setx(int a);
        void sety(int a);
        Item();
   // protected:
        int x,y;
};

#endif // ITEM_H
