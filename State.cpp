#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Item.h"

#include "Player.h"
#include "Can.h"
#include "State.h"
using namespace std;

State::State()
{
    cost = 0;
    for(int i=0;i<dimx;i++){
        for(int j=0;j<dimy;j++){
            if(field[i][j]=='M'){
                player = Player(i,j);
                field[i][j] = '.';
            }
            if(field[i][j]=='J'){
                cans.push_back(Can(i,j));
                field[i][j] = '.';
            }
        }
    }
    calculateheuristic();
    string steps();
}

bool State::isGoal(){
    for(int i = 0; i < numcans; i++){
        if (not (State::cans.at(i).getisontarget())) return false;
    }
    return true;
}

int State::getcost(){
    return cost;
}

int State::gettotalcost(){
    return totalcost;
}

int State::getheurisic(){
    return heuristic;
}

//Calcultes the heuristic value and set the heuristic and total cost variables
//int heuristic
//int totalcost
void State::calculateheuristic(){
    int h = 0;
    for(int i = 0; i < numcans; i++){
        h =+ State::cans.at(i).closestTarget();
    }
    h = h + closestcanfromplayer();
    heuristic = h;
    totalcost = cost + heuristic;
    return;
}

//Returns the distance (x+y) of the closest can from the player
int State::closestcanfromplayer(){
    int w = 1;
    do{
        for(int a=player.getx()-w; a<=player.getx()+w; a++){
            for(int i=0; i<numcans;i++){
                if ((cans.at(i).getx() == a )&&((cans.at(i).gety()==player.gety()-w) || (cans.at(i).gety()==player.gety()+w))){
                    return(w + (player.getx()-a) );
                }
            }
        }
        for(int a = player.gety()-w; a <= player.gety()+w; a++){
            for(int i=0; i<numcans;i++){
                if ((cans.at(i).gety() == a )&&((cans.at(i).getx()==player.getx()-w) || (cans.at(i).getx()==player.getx()+w))){
                    return(w + (player.gety()-a) );
                }
            }
        }
    }while(true);
}

//Return -1 if there is no can here, returns the can number if a can is here.
int State::whichCanIsHere(int x,int y){
    for(int i = 0; i < numcans; i++){
        if((cans.at(i).getx() == x) && (cans.at(i).gety() == y)) return i;
    }
    return -1;
}

//Return the same state
bool State::moveup(){
    int canNumber;
    if (field[State::player.getx()][State::player.gety()-1] == 'X') return false;
    canNumber = whichCanIsHere(player.getx(),player.gety()-1);
    if (canNumber == -1){
        player.moveup();
        cost++;
        calculateheuristic();
        return true ;
    }
    if ((field[State::player.getx()][State::player.gety()-2] == 'X')  || (whichCanIsHere(player.getx(),player.gety()-2) != -1 )){
        return false;
    }
    player.moveup();
    cost++;
    cans.at(canNumber).moveup();
    calculateheuristic();
    steps.push_back('U');
    return true;
}

bool State::movedown(){
    int canNumber;
    if (field[State::player.getx()][State::player.gety()+1] == 'X') return false;
    canNumber = whichCanIsHere(player.getx(),player.gety()+1);
    if (canNumber == -1){
        player.movedown();
        cost++;
        calculateheuristic();
        return true ;
    }
    if ((field[State::player.getx()][State::player.gety()+2] == 'X')  || (whichCanIsHere(player.getx(),player.gety()+2) != -1 )){
        return false;
    }
    player.movedown();
    cost++;
    cans.at(canNumber).movedown();
    calculateheuristic();
    steps.push_back('D');
    return true ;
}

bool State::moveleft(){
    int canNumber;
    if (field[State::player.getx()-1][State::player.gety()] == 'X') return false;
    canNumber = whichCanIsHere(player.getx()-1,player.gety());
    if (canNumber == -1){
        player.moveleft();
        cost++;
        calculateheuristic();
        return true ;
    }
    if ((field[State::player.getx()-2][State::player.gety()] == 'X')  || (whichCanIsHere(player.getx()-2,player.gety()) != -1 )){
        return false;
    }
    player.moveleft();
    cost++;
    cans.at(canNumber).moveleft();
    calculateheuristic();
    steps.push_back('L');
    return true;
}

bool State::moveright(){
    int canNumber;
    if (field[State::player.getx()+1][State::player.gety()] == 'X') return false;
    canNumber = whichCanIsHere(player.getx()+1,player.gety());
    if (canNumber == -1){
        player.moveright();
        cost++;
        calculateheuristic();
        return true;
    }
    if ((field[State::player.getx()+2][State::player.gety()] == 'X')  || (whichCanIsHere(player.getx()+2,player.gety()) != -1 )){
        return false;
    }
    player.moveright();
    cost++;
    cans.at(canNumber).moveright();
    calculateheuristic();
    steps.push_back('R');
    return true;
}

bool State::isequalto(State state2){
    bool cont = true;
    if (State::getheurisic() == state2.getheurisic()){
        if ((State::player.getx() == state2.player.getx()) && (State::player.gety() == state2.player.gety())){
            for(int j = 0;j<numcans;j++) {
                if ((State::cans.at(j).getx() != state2.cans.at(j).getx()) || (State::cans.at(j).gety() != state2.cans.at(j).gety())){
                    cont = false;
                    break;
                }
            }
            if(cont){
                return true;
            }
        }
    }
    return false;
}
