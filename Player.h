#ifndef Player_H
#define Player_H
class Player{
public:
    Player(int race,int cl4ss);
    void showStats();
    int toiletBroke();


private:
    int hp;
    int attack;
    int defence;

};

#endif // Player_H
