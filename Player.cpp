#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "Item.h"
#include "Player.h"

using namespace std;

Player::Player() :Item()
{
    Item::x = 0 ;
    Item::y = 0 ;
}

Player::Player(int a,int b) :Item()
{
    Item::x =a;
    Item::y =b;
}
void Player::moveup(){
    Item::sety(Item::gety()+1);
}
void Player::movedown(){
    Item::sety(Item::gety()-1);
}
void Player::moveleft(){
    Item::setx(Item::getx()-1);
}
void Player::moveright(){
    Item::setx(Item::getx()+1);
}
