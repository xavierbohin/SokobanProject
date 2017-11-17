#ifndef EXPLORED_H
#define EXPLORED_H
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include "State.h"
#include "Common.h"

using namespace std;

class Explored
{
    public:
        Explored();
        bool contains(State);
        void add(State node);
    /*protected:
    private:*/
        vector<State> explored;
};

#endif // EXPLORED_H
