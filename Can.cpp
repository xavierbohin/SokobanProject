#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Target.h"
#include "Item.h"
#include "Can.h"

using namespace std;

Can::Can(int a, int b) :Item()
{
    Item::x =a;
    Item::y =b;
}

bool Can::getisontarget(){
    return isontarget;
}

void Can::moveup(){
    Item::sety(Item::gety()-1);
    Can::checktarget();
}
void Can::movedown(){
    Item::sety(Item::gety()+1);
    Can::checktarget();
}
void Can::moveright(){
    Item::setx(Item::getx()+1);
    Can::checktarget();
}
void Can::moveleft(){
    Item::setx(Item::getx()-1);
    Can::checktarget();
}

void Can::checktarget(){
    isontarget = false;
    for(int i = 0; i<numcans; i++){
        if((targets(i).getx == Item::x) && (targets(i).gety == Item::y)){
            isontarget = true;
            break;
        }
    }
}

int Can::closestTarget(){
    int c = 0;
    int w = 1;
    Can::checktarget();
    if (isontarget){
        return (0);
    }
    do{
        for(int a=Item::x-w; a<=Item::x+w; a++){
            for(int i=0; i<numcans; i++){
                if ((targets(i).getx()==a )&&(( targets(i).gety()==Item::y-w) || (targets(i).gety()==Item::y+w))){
                    return(w+(Item::x - a));
                }
            }
        }
        for(int a=Item::y-w+1; a<=Item::y+w-1; a++){
            for(int i=0; i<numcans; i++){
                if ((targets(i).gety()==a )&&(( targets(i).getx()==Item::x-w) || (targets(i).getx()==Item::x+w))){
                    return(w+(Item::y - a));
                }
            }
        }
    }while(true);


}
