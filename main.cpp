#include <iostream>
#include <stdlib.h>
#include <string>
#include "Player.cpp"
#include "Player.h"
#include <stdio.h>
#include <sqlite3.h>
#include "GameMenu.h"
#include "GameMenu.cpp"
#include "item.h"
#include "item.cpp" 
#include <vector>

using namespace std;
string firstRoom;
string firstAction;
string getOutCell;



void cellRoom(Player p)
{
    GameMenu game;
    // This function is for the first room the cell room. It allows for input and output to create a puzzle for the player to figure out how to escape.
    cout << "You may now enter commands to procced"<< endl;
    cin >> firstRoom;
    if(firstRoom == "help")
    {
        game.HelpMenu();
        cin >> firstRoom;
    }
    

    while (firstRoom != "search" && firstRoom != "info" )
    {
        //while loop to make sure the correct commands are input and if not to allow them to try again
        cout << "Try again" << endl;
        cin >> firstRoom;
    }
    
     if (firstRoom == "search")
     {
        // This if section is for reacting towards the commands the user inputs for example breaking a sink
        cout << "You search the room and find a bed, toilet_bowl,cell_door,sink and window." << endl;
        cin >> firstAction;
        if(firstAction == "help")
        {
            game.HelpMenu();
            cin >> firstAction;
        }
     }
   
     else if (firstRoom == "info")
       {
            cout << "You look around the room, its hard to see anything as its so dark, You notice some light coming through\n"
                    "shining onto a bed."<< endl;
             cin >> firstAction;
             if(firstAction == "help")
             {
                game.HelpMenu();
                cin >> firstAction;
             }
        }
        // This section is accessed once the above action is called (search) So a player has to search the room before just bashing in commands    
        while (firstAction != "break(toilet_bowl)" && firstAction != "break(sink)" && firstAction != "break(cell_door)" && firstAction != "break(window)" && firstAction != "search(sink)" )
        { 
        cout << "Try again" << endl;
        cin >> firstAction;
        }
    
        if (firstAction == "break(toilet_bowl)" || firstAction == "break(cell_door)" || firstAction == "break(window)")
        {
            cout << "You cut your hand and lose 1 health" << endl;
            p.toiletBroke();
            p.death();
        }
        else if ( firstAction == "break(sink)")
        {
            cout << "You cut your hand and lose 1 heath" << endl;
            p.toiletBroke();
            p.death();
            item hairpin("Hair pin","These can be used for picklocking");
            vector <item> Inventory;
            Inventory.push_back(hairpin);
            cout << "You now have a " << Inventory[0].getName() << " in your inventory " << Inventory[0].getInfo() << endl;
            
            
        }
        
        else if (firstAction == "search(sink)")
        {
            item hairpin("Hair pin","These can be used for picklocking");
            vector <item> Inventory;
            Inventory.push_back(hairpin);
            cout << "You now have a " << Inventory[0].getName() << " in your inventory " << Inventory[0].getInfo() << endl;
            
        }
    
        cin >> getOutCell;
        if(getOutCell == "help")
        {
            game.HelpMenu();
            cin >> getOutCell;
        }
     
        while(getOutCell != "picklock(cell_door)" && getOutCell != "picklock(door)" )
        {
            cout << "Try Again" << endl;
            cin >> getOutCell;
        }
    
        if(getOutCell == "picklock(cell_door)" || "picklock(door)")
        {
            cout << "You Succesfully picklock the door and escape the cell!!\n"
                    "You walk into the <insert room name here>"<< endl;
        }
           
}



static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   int i;
   for(i=0; i<argc; i++)
   {
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

   if( rc )
   {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }else
    {
      fprintf(stderr, "Opened database successfully\n");
    }
   /* Create test SQL statement */
   sql = "INSERT INTO INVENTORY (NAME,ITEM_ID,QUANTITY,INFO)"   \
         "VALUES ('Hair pins',1,1,'Some hair pins');";
       
          /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK )
   {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else
    {
      fprintf(stdout, "Records created successfully\n");
    }
       
   sqlite3_close(db);
    
    GameMenu G1;
    cellRoom(G1.FirstMenu());
    
    return 0;
}
