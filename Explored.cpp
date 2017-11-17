#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "State.h"


using namespace std;

Explored::Explored()
{

}

bool Explored::contains(State node){
    bool cont;
    for(int i = 0;i<explored.size();i++){
        bool cont = true;
        if (node.getheurisic() == explored.at(i).getheurisic()){
            if ((node.player.getx() == explored.at(i).player.getx()) && (node.player.gety() == explored.at(i).player.gety())){
                for(int j = 0; j<numcans; j++) {
                    if ((node.cans(j).getx() != explored.at(i).cans(j).getx()) || (node.cans(j).gety() != explored.at(i).cans(j).gety())){
                        cont = false;
                        break;
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

void Explored::add(State elmt){
    explored.push_back(elmt);
}
