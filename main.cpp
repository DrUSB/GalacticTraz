#include <iostream>
#include <stdlib.h>
#include <string>
#include "Player.h"

using namespace std;
string firstRoom;
    void cellRoom(){
    cout << "You may now enter commands to procced"<< endl;
    cin >> firstRoom;
    if (firstRoom == "search"){
        cout << "You search the room and find a bed, toilet bowl,cell door,sink and window." << endl;
    }
    else if(firstRoom == "info"){
        cout << "You look around the room, its hard to see anything as its so dark, You notice some light coming through\n"
                "shining onto a bed."<< endl;

    }
    else{
        cout << "PLease try again" << endl;
        return cellRoom();
    }

    }



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
    cout << "1.Thief\n"
            "2.Murderer\n"
            "3.Con-Artist\n" << endl;
    cout << "Now please choose a class"<< endl;
    cin >> cl4ss;
    Player player1(race,cl4ss);
    player1.showStats();
    cin.get();
    cout << "You have been caught for your crimes against the Galactical Federation\n"
            "You are held within the most secure prison in the Galaxy, GalacticTraz\n"
            "You must escape tonight if you have any chance of escaping at all, before\n"
            "the prison is in lockdown\n"
            "Good luck."<< endl;
    cin.get();
    cout << "You wake up in a dark cell room..." << endl;
    cin.get();
    cout << "You notice the smell of damp in the air\n"
            "The guards start shouting LIGHTS OUT! All the lights start turning off\n"
            "one by one until the prison is almost in pure darkness\n" << endl;
    cellRoom();

    return 0;
}
