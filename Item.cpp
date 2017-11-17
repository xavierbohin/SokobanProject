#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Item.h"

using namespace std;

Item::Item()
{

}
int Item::getx(){return Item::x;}
int Item::gety(){return Item::y;}
void Item::setx(int a){Item::x = a;}
void Item::sety(int a){Item::y = a;}
