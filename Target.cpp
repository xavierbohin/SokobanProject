#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Item.h"
#include "Common.h"
#include "Target.h"

using namespace std;

Target::Target(int a, int b) :Item()
{
    Item::x=a;
    Item::y=b;
}
