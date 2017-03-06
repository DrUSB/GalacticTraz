#ifndef GameMenu_H
#define GameMenu_H
#include "Player.h"
#include <string>

using namespace std;

class GameMenu
{

    public:
    //Constuctor
    GameMenu();
    Player FirstMenu();
    void HelpMenu();



   private:
    string name;
    int race;
    int cl4ss;
    string firstRoom;
    string firstAction;
    string getOutCell;
    string firstInput;
    Player player1;


    //Methods declaration
    

};
#endif // GameMenu_H

