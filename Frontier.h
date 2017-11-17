#ifndef FRONTIER_H
#define FRONTIER_H
#include <iostream>
#include <vector>
#include <queue>

#include "State.h"


using namespace std;

class Frontier
{
    public:
        Frontier();
        void add(State elmt);
        bool contains(State node);
    protected:
    private:
        priority_queue<State, vector<State>, CompareTotalCost> tree;

};

#endif // FRONTIER_H
