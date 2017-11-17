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
#include "Common.h"

using namespace std;




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

    dimx = 3;
    dimy = 3;
    numcans = 1;
    field[1][1] = '.';
    field[2][1] = '.';
    field[3][1] = '.';
    field[1][2] = '.';
    field[2][2] = 'J';
    field[3][2] = '.';
    field[1][3] = 'M';
    field[2][3] = '.';
    field[3][3] = '.';
    targets[1] = new Target(1,3);


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
