#include "Player.h"

#include <iostream>

using namespace std;
Player::Player(int race,int cl4ss)
{
    if (race == 1){
    hp = 8;
    attack = 8;
    defence = 2;
    }
    if(race == 2){
        hp = 8;
        attack = 8;
        defence = 2;
    }
    if(race == 3){
        hp = 10;
        attack = 4;
        defence = 4;
    }
    if(race == 4){
        hp = 6;
        attack = 6;
        defence = 6;
    }
    if(race == 5){
        hp = 4;
        attack = 10;
        defence = 4;
    }
    if(race == 6){
        hp = 7;
        attack = 3;
        defence = 8;
    }
    if(cl4ss == 1){
        hp -= 1;
        attack += 2;
        defence -= 2;
    }
    if(cl4ss == 2){
        hp += 2;
        attack +=1;
        defence -= 2;
    }
    if(cl4ss == 3){
        hp -=2;
        attack +=4;
        defence -= 1;
    }
}
void Player::showStats()
{
    cout <<"Your stats are:\n"<<"HP: "<< hp <<"\n"<<"Attack: "<<attack<<"\n" <<"Defence:" << defence << endl;
}

int Player::toiletBroke()
{
        hp -= 1;
        cout << "Your hp is now "<< hp << endl;

    return hp;
}
