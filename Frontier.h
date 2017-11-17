#ifndef FRONTIER_H
#define FRONTIER_H
#include <iostream>
#include <vector>
#include <queue>

#include "State.h"
#include "Common.h"


using namespace std;

struct CompareTotalCost{    //operator to use the priority_queue
    bool operator()(State const & s1, State const & s2){
        return s1.totalcost < s2.totalcost;
    }
};

class Frontier
{
    public:
        Frontier();
        void add(State elmt);
        bool contains(State node);
    /*protected:
    private:*/
        priority_queue<State, vector<State>, CompareTotalCost> tree;
        priority_queue<State, vector<State>, CompareTotalCost> tree2;


};

#endif // FRONTIER_H
