#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Can.h"
#include "Player.h"
#include "State.h"
#include "Common.h"
#include "Explored.h"


using namespace std;

Explored::Explored()
{

}

bool Explored::contains(State node){
    bool cont;
    for(int i = 0; i<(int)explored.size(); i++){
        bool cont = true;
        if (node.getheurisic() == explored.at(i).getheurisic()){
            if ((node.player.getx() == explored.at(i).player.getx()) && (node.player.gety() == explored.at(i).player.gety())){
                for(int j = 0; j<numcans; j++) {
                    if ((node.cans.at(j).getx() != explored.at(i).cans.at(j).getx()) || (node.cans.at(j).gety() != explored.at(i).cans.at(j).gety())){
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
