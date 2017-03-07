#include <iostream>
#include <stdlib.h>
#include <string>
#include "Player.cpp"
#include "Player.h"
#include <stdio.h>
#include <sqlite3.h>

using namespace std;
string secondroom;
string firstAction;

void cellRoom(Player p){
    // This function is for the second room the cell room. It allows for input and output to create a puzzle for the player to figure out how to escape.
    cout << "You may now enter commands to procced"<< endl;
    cin >> secondroom;
    while (secondroom != "search" && secondroom != "info"){
        //while loop to make sure the correct commands are input and if not to allow them to try again
        cout << "Try again" << endl;
        cin >> secondroom;
    }

    if (secondroom == "search"){
        // This if section is for reacting towards the commands the user inputs for example blow bubbles
        cout << "You search the room and find pebbles, weeds ans shells" << endl;
        cin >> firstAction;
    }
   
     else if(secondroom == "info"){
            cout << "You look around the room, its very bright with limited visibility, You hear some sound coming from\n"
                "the pebbles."<< endl;
             cin >> firstAction;
        }
        // This section is accessed once the above action is called (search) So a player has to search the room before just bashing in commands    
        while (firstAction != "swim(over_pebbles)" && firstAction != "swim(weeds)" && firstAction != "swim(shells)" && firstAction != "swim(other_fish)" && firstAction != "search(pebbles)" ){ 
        cout << "Try again" << endl;
        cin >> firstAction;
        }
    
        if (firstAction == "swim(over_pebbles)" || firstAction == "swim(weeds)" || firstAction == "swim(shells)"){
            cout << "You damage your fin, loose 1 life" << endl;
            p.toiletBroke();
        }
        else if ( firstAction == "find(weeds)"){
            cout << "You damage your fin, loose 1 life" << endl;
            p.toiletBroke();
            cout << "While searching for pebbles you find a pearl (use to help distract)" << endl;
            
        }
        
        else if (firstAction == "search(pebbles)"){
            cout << "You search for pebbles and you find a pearl (use to help distract)" << endl;
            
        
            }
           
        }

      

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main()
{
    // This is the main where functions are called and program runs in lineral progression downwards
    // sqlite3 database is added here and made sure it opens successfully. If it opens successfully it is printed when the game opens. Similarly if it fails to open there is a
    // message saying can't open database
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   rc = sqlite3_open("GalacticTrazData.db", &db);

   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }
   /* Create test SQL statement */
   sql = "INSERT INTO INVENTORY (NAME,ITEM_ID,QUANTITY,INFO)"   \
         "VALUES ('Hair pins',0001,1,'Some hair pins');";
       
          /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records created successfully\n");
   }
       
   sqlite3_close(db);
//Variables are declared here as are the data types.
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
    // help menu below
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
    // selection for choosing class and race depending on which combination of either is chosen stats will differ and be a mixture of both, allows more unique stats.
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
    //beginning of game with short introduction
    cout << "You have been caught for your crimes against the Galactical Federation\n"
            "You are held within the most secure prison in the Galaxy, GalacticTraz\n"
            "You must escape tonight if you have any chance of escaping at all, before\n"
            "the prison is in lockdown\n"
            "Good luck."<< endl;
    cin.get();
    cout << "You wake up in the deep sea..." << endl;
    cin.get();
    cout << "You notice the vastness of the sea\n"
            "You notice that you are trapped and there are sharks circling\n"
            "view is blocked and find it difficult to see if there is any way out\n" << endl;
    //function to move player into the third room (blockRoom)
    blockRoom(player1);

    return 0;
}
