#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main(){
    string name;
    int race;
    int cl4ss;
    string checkForHelp;
    cout << "Welcome to GalAcTicTRaz!" << endl;
    cin.get();
    cout << "Game is now loading..."<< endl;
    cin.get();
    cout << "For information on commands type help. Otherwise type anything to continue" << endl;
    cin >> checkForHelp;
    if (checkForHelp.compare("help") == 0){
        cout << "************************************************\n"
                "                   Help Menu\n"
                "************************************************\n"
                "\nMovements:\n\n"
                "n                Moves to North room\n"
                "e                Moves to East room\n"
                "s                Moves to South room\n"
                "w                Moves to West room\n\n"
                "Character Abilities:\n\n"
                "search                         Searches local room\n"
                "look                           Looks around room\n"
                "talk                           Talks if possible to person in room\n"
                "info                           Gives information on the room you're in\n"
                "pickUp(item)                   Pickes up specified item\n"
                "kill(enemy) with (item)        Kills a specified enemy with a chosen item\n"
                "break(object)                  Breaks chosen object in room\n"
                "open(oject)                    Open specified object e.g Box,Crate\n"
                "drop(object)                   Drops specified item from inventory\n"
                "examine(object)                Examines specified object\n"
                "\n"
                "Game options:\n"
                "save                           Saves game at current point\n"
                "restore                        Return to last save\n"
                "restart                        Restarts game at beginning\n"
                "quit                           Quits game\n"
                "\n"
                "Class/Crime Abilities:\n"
                "Thief:\n"
                "picklock(object)               Picklock a door or chest etc.\n"
                "stealth                        Toggle stealth to go into or out off stealth mode\n"
                "Murderer:\n"
                "smash(object)                  Smashes chosen object for example a door\n"
                "charge(enemy)                  Charges enemy dealing damage same as weapon held + 30%\n\n"
                "Con Artist:\n"
                "teleport(direction)            Works instead of movement but can go past locked doors\n"
                "invisible                      Makes you go invisible\n" << endl;

    }
    cout << "What is your name prisoner?" << endl;
    cin >> name;
    cout << "Welcome " << name << " What is your race? Choose via the Number\n" << endl;
    cout << "1.Dark Gnome\n"
            "2.Galactical Mushroom\n"
            "3.Ogre\n"
            "4.Human\n"
            "5.Ultimate Fish\n"
            "6.Goblin\n" << endl;
    cin >> race;



    return 0;
}
