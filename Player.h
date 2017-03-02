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


private:
    int hp;
    int attack;
    int defence;

};

#endif // Player_H
