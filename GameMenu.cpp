#include "GameMenu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <string>

using namespace std;

//Constructor
GameMenu::GameMenu()
{
    
}

//Methods
Player GameMenu::FirstMenu()
{
    cout << "Welcome to GalAcTicTRaz!" << endl;
    cout << "Please press enter to continue" << endl;
    cin.get();
    cout << "Game is now loading..."<< endl;
    cout << "Please press enter to continue" << endl;
    cin.get();
    cout << "For information on commands type help. Otherwise type anything to continue" << endl;
    cin >> firstInput;
    if(firstInput == "help")
    {
      HelpMenu();
    }
    cout << "What is your name prisoner?" << endl;
    cin >> name;
    
    // selection for choosing class and race depending on which combination of either is chosen stats will differ and be a mixture of both, allows more unique stats.
    cout << "Welcome " << name << " What is your race? Choose via the Number\n" << endl;
    cout << "1.Dark Gnome\n"
            "2.Galactical Mushroom\n"
            "3.Ogre\n"
            "4.Human\n"
            "5.Ultimate Fish\n"
            "6.Goblin\n" << endl;
    cin >> race;
    while(race != 1 && race != 2 && race != 3 && race != 4 && race != 5 && race != 6 && cin.fail())
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Wrong input " << race << " , please try again" << endl;
      cin >> race;
    }
    
    cout << "Now please choose a class"<< endl;
    cout << "1.Thief\n"
            "2.Murderer\n"
            "3.Con-Artist\n" << endl;
    cin >> cl4ss;
    while(cl4ss != 1 && cl4ss != 2 && cl4ss != 3 && cin.fail())
    {
     cin.clear();
     cin.ignore(100, '\n');
     cout << "Wrong input " << cl4ss << " , please try again" << endl; 
     cin >> cl4ss;
    }
    Player player1(race,cl4ss);
    player1.showStats();
    player1.getHp();
    cin.get();
    //beginning of game with short introduction
    cout << "You have been caught for your crimes against the Galactical Federation\n"
            "You are held within the most secure prison in the Galaxy, GalacticTraz\n"
            "You must escape tonight if you have any chance of escaping at all, before\n"
            "the prison is in lockdown\n"
            "Good luck."<< endl;
    cout << "Please press enter to continue" << endl;
    cin.get();
    cout << "You wake up in a dark cell room..." << endl;
    cout << "Please press enter to continue" << endl;
    cin.get();
    cout << "You notice the smell of damp in the air\n"
            "The guards start shouting LIGHTS OUT! All the lights start turning off\n"
            "one by one until the prison is almost in pure darkness\n" << endl;
    return player1;
}

void GameMenu::HelpMenu()
{
    
    
    string line;
    ifstream myfile ("help.txt");
    if (myfile.is_open())
    {
        while(getline (myfile,line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }
    else cout << "Cannot open file";
}