#ifndef GameMenuameMenu_H
#define GameMenuameMenu_H
#include "Player.h"

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

