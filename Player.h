#ifndef Player_H
#define Player_H
class Player{
public:
    //Constructor
    Player();
    //Destructor
    ~Player();
    
    Player(int, int);
    void showStats();
    int toiletBroke();
    void death();
    void attackSkill();
    int getHp();
    int getAtt();
    int getDef();
    


private:
    int hp;
    int attack;
    int defence;

};

#endif // Player_H
