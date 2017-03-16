#include <iostream>
#include <stdlib.h>
#include <string>
#include "Player.h"
#include <stdio.h>
#include <sqlite3.h>
#include "GameMenu.h"
#include "item.h"
#include <vector>
#include "libsqlite.hpp"
using namespace std;
string firstRoom;
string firstAction;
string getOutCell;

void sqliteinsert()
{
    sqlite3 *db;
    int rc;
    const char *sql;
    
    rc = sqlite3_open("/Users/sharankaur/Documents/glactic traz/glactic traz/GalacticTrazData.db", &db);
    
    if( rc )
    {
        cout << "cant open database" << endl;
    }
    else
    {
        cout << "Opened database successfully" << endl;
    }
    /* Create test SQL statement */
    sql = "INSERT INTO INVENTORY (NAME,ITEM_ID,QUANTITY,INFO)"   \
    "VALUES ('Hair pins',1,1,'Some hair pins');";
  
    
    

    /* Create test SQL statement */
    sql = "INSERT INTO INVENTORY (NAME,ITEM_ID,QUANTITY,INFO)"   \
    "VALUES ('Silver coin',2,1'A silver coin');";
    

    sqlite3_close(db);
}

        
void cellRoom(Player p)
{
    sqliteinsert();
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
                    "You walk into the Cave room"<< endl;
        }

}






string c_room;

void cave_room()
    
{
    sqliteinsert();
    GameMenu game;
    // This function is for the first room the cell room. It allows for input and output to create a puzzle for the player to figure out how to escape.
    
    Player p;
    item pebbles("Pebbles","Some shiny pebbles");
    item weeds("weeds", "weeds plants");
    item plants("plants", "wild plants");
    item door_lock("door_lock", "lock on the door");
    item glass("glass", "some pieces of glass");
    
    cout << "You are now in the cave room "<<endl;
    
    cout << "view is blocked and find it difficult to see if there is any way out"<<endl;
    
    cout << "You may now enter commands to procced"<< endl;
    
    cin >> c_room;
    if(c_room == "help")
        
    {
        game.HelpMenu();
        cin >> c_room;
    
    }
    
    while (c_room != "search" && c_room != "info")
    {
        cout<<"Try again"<< endl;
        cin >> c_room;
    }
    
    if (c_room == "search")
    {
        cout<<"You enter the room and see it deserted with weeds, pebbles, plants, door_lock and glass."<<endl;
        cin >> firstAction;
        
        if(firstAction == "help")
        {
            game.HelpMenu();
            cin >> firstAction;
        }
    }
    
    else if (c_room == "info")
    {
    
        cout<<"As you approach inwards, it becomes apparent it is empty with only the light coming through the holes..."<<endl;
        cin >> firstAction;
        if(firstAction == "help")
        {
            game.HelpMenu();
            cin >> firstAction;
        }
    }
    
          // This section is accessed once the above action is called (search) So a player has to search the room before just bashing in commands
      while (firstAction != "search(weeds)" && firstAction != "break(pebbles)" && firstAction != "break(door_lock)" && firstAction != "break(broken pieces of rock)" && firstAction != "break(plants)" && firstAction != "eat(weeds)" )
          
      {
        cout <<"Try again" <<endl;
        cin >> firstAction;
      }
    
      if ( firstAction == "break(pebbles)" || firstAction == "break(door_lock)" || firstAction == "break(plants)" || firstAction == "break(glass)")
          
      {
        cout << "You cut your hand and lose 1 health" << endl;
        p.pebbles();
        p.door_lock();
      }
      else if ( firstAction == "eat(weeds)")
          
      {
          cout << "You ate posionous food and loose 1 health" <<endl;
          p.pebbles();
          p.door_lock();
          item Silvercoin("Silver coin","These can be used to open the door" );
          vector <item> Inventory;
          Inventory.push_back(Silvercoin);
          cout << "You now have a " << Inventory[0].getName() << " in your inventory " << Inventory[0].getInfo() << endl;
      }
    
      else if (firstAction == "search(weeds)")
      {
          item Silvercoin("Silver Coin","These can be used to open the door");
          vector <item> Inventory;
          Inventory.push_back(Silvercoin);
          cout << "You now have a " << Inventory[0].getName() << " in your inventory " << Inventory[0].getInfo() << endl;
          
      }
    
    

    
    
    while(getOutCell != "picklock(door_lock)" && getOutCell != "picklock(door)" )
    {
        cout << "Try Again" << endl;
        cin >> getOutCell;
    }
    
    if(getOutCell == "picklock(door_lock)" || "picklock(door)")
    {
        cout << "You Succesfully picklock the door and escape the Cave room!!\n"
        "Well Done! You are free now"<< endl;
    }
    
}
    
    
    
    
    
      

int main()
{

    
    GameMenu G1;
    cellRoom(G1.FirstMenu());
    cave_room();
    
    return 0;

}




