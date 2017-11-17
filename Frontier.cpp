#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "State.h"
#include "Common.h"
#include "Frontier.h"

using namespace std;

Frontier::Frontier()
{
    //ctor
}
void Frontier::add(State elmt){
    tree.push_back(elmt);
}
bool Frontier::contains(State node){
    bool cont;
    for(int i = 0; i<tree.size(); i++){     //For every states in tree
        cont = true;
        if (node.getheurisic() == tree.at(i).getheurisic()){          //if the cost is the same
            if ((node.player.getx() == tree.at(i).player.getx()) && (node.player.gety() == tree.at(i).player.gety())){
                for(int j = 0; j<numcans; j++) {
                    if ((node.cans(j).getx() != tree.at(i).cans(j).getx()) || (node.cans(j).gety() != tree.at(i).cans(j).gety())){
                        cont = false;
                    }
                }
                if(cont){
                    return true;
                }
            }
        }
    }
    return false;
}
