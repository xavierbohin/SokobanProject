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
    tree.push(elmt);
}
/*bool Frontier::contains(State node){
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
}*/

bool Frontier::contains(State node){
    tree2 = tree;
    bool cont;
    do{     //For every states in tree
        cont = true;
        if (node.getheurisic() == tree2.top().getheurisic()){          //if the cost is the same
            if ((node.player.getx() == tree2.top().player.getx()) && (node.player.gety() == tree2.top().player.gety())){
                for(int j = 0; j<numcans; j++) {
                    if ((node.cans.at(j).getx() != tree2.top().cans.at(j).getx()) || (node.cans.at(j).gety() != tree2.top().cans.at(j).gety())){
                        cont = false;
                    }
                }
                if(cont){
                    return true;
                }
            }
        }
        tree2.pop();
    }while(not tree2.empty());
    return false;
}
