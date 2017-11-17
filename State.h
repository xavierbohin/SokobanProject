#ifndef STATE_H
#define STATE_H
#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Item.h"
#include "State.h"
#include "Player.h"
#include "Can.h"
#include "Common.h"

using namespace std;

class State
{
    public:
        State();
        void calculateheuristic();
        int getcost();
        int gettotalcost();
        int getheurisic();
        bool moveup();
        bool movedown();
        bool moveleft();
        bool moveright();
        bool isequalto();
        bool isGoal();

    /*protected:
    private:*/
        string steps;
        int cost;
        int heuristic;
        int totalcost;
        Player player;
        int numcan;
        vector<Can> cans;
        int whichCanIsHere(int x,int y);
        int closestcanfromplayer();
};

#endif // STATE_H
