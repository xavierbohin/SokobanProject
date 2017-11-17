#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Target.h"
#include "Item.h"
#include "State.h"
#include "Player.h"
#include "Can.h"
#include "Explored.h"
#include "Frontier.h"

using namespace std;

char field[][];
Target targets[];
int dimx,dimy,numcans;


struct CompareTotalCost{    //operator to use the priority_queue
    bool operator()(State const & s1, State const & s2){
        return s1.totalcost < s2.totalcost;
    }
};

int main()
{
    //****************************************
    // insert the reading of the .txt file
    //****************************************
    int exploredNodes = 0;
    State movedup;
    State moveddown;
    State movedleft;
    State movedright;

    Explored explored = new Explored()
    node = new State(dimx,dimy,numcans,field);
    node.settotalcost(node.getcost+node.getheuristic);
    Frontier frontier = new Frontier;
    //priority_queue<State, vector<State>, CompareTotalCost> frontier; //priority queue of states sorted by total cost
    frontier.push(node);
    while ( not frontier.empty()){
        node = frontier.top();
        frontier.pop();
        if (node.isGoal()){
            return node.steps;
        }
        explored.add(node);
        cout << exploredNodes << endl;

        movedup = node;
        if( not movedup.moveup()){
            if not ((explored.contains(movedup)) || (frontier.contains(movedup))){
                frontier.add(movedup);
            }
            else if ()

        }

        moveddown = node;
        if( not moveddown.movedown()){
            if not ((explored.contains(moveddown)) || (frontier.contains(moveddown))){
                frontier.add(moveddown);
            }
            else if ()
        }

        movedleft = node;
        if( not movedleft.moveleft()){
            if not ((explored.contains(movedleft)) || (frontier.contains(movedleft))){
                frontier.add(movedleft);
            }
            else if ()
        }

        movedright = node;
        if( not movedright.moveright()){
            if not ((explored.contains(movedright)) || (frontier.contains(movedright))){
                frontier.add(movedright);
            }
            else if ()
        }
    }
    cout << "failure" << endl;

    return 0;
}
