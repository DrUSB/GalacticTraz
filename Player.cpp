#include "Player.h"
#include <iostream>

using namespace std;
//Constructor
Player::Player() {
    
}
//Destructor
Player::~Player() {
    
}

Player::Player(int race,int cl4ss)
{

    if (race == 1 /*|| race == "Dark Gnome" || race == "Dark gnome" || race == "dark gnome"*/)
    {
    hp = 8;
    attack = 8;
    defence = 2;
    }
    if(race == 2)
    {
        hp = 8;
        attack = 8;
        defence = 2;
    }
    if(race == 3)
    {
        hp = 10;
        attack = 4;
        defence = 4;
    }
    if(race == 4)
    {
        hp = 6;
        attack = 6;
        defence = 6;
    }
    if(race == 5)
    {
        hp = 4;
        attack = 2;
        defence = 4;
    }
    if(race == 6)
    {
        hp = 7;
        attack = 3;
        defence = 8;
    }
  
    if(cl4ss == 1/* || cl4ss == "thief" || cl4ss == "Thief"*/)
    {
        hp -= 1;
        attack += 2;
        defence -= 2;
    }
    if(cl4ss == 2/* || cl4ss == "murderer" || cl4ss == "Murderer"*/)
    {
        hp += 2;
        attack +=1;
        defence -= 2;
    }
    if(cl4ss == 3/* || cl4ss == "Con-Artist" || cl4ss == "Con Artist" || cl4ss == "con artist" || cl4ss == "Con artist" || cl4ss == "Con-artist"*/)
    {
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

int Player::pebbles()
{
    hp -= 1;
    cout << "Your hp is now "<< hp << endl;
    
    return hp;
}



int Player::door_lock()
{
    hp -= 1;
    cout << "Your hp is now "<< hp << endl;
    
    return hp;
}

    
void Player::death()
    
{
    if(hp <= 0)
    {
     cout << "You are dead\nGame over..." << endl;
     exit(0);
    }
}


/*void Player::attackSkill(enemy)
{
NOT FINISHED CODE    (enemy hp) - ((attack) - (enemy defence) )
}*/



int Player::getHp()
{
    return (hp);
}

int Player::getAtt()
{
    return (attack);
}

int Player::getDef()
{
    return (defence);
}



