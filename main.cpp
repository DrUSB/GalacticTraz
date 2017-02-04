#include <iostream>

using namespace std;

int main(){
    string checkForHelp;
    cout << "Welcome to Galactic StrongHold!" << endl;
    cin.get();
    cout << "Game is now loading..."<< endl;
    cin.get();
    cout << "Type help for more information on what commands to use!"<< endl;
    cin >> checkForHelp;
    if (checkForHelp.compare("help") == 0){
        cout << "************************************************\n"
                "                   Help Menu\n************************************************\n"
                "\nMovements:\n\nmoveN        Moves to North room\nmoveE        Moves to East room\nmoveS        Moves to South room\nmoveW        Moves to West room\nsearch       Searches local room\ntalk         Talks if possible to person in room\ninfo         Gives information on the room you're in"
                "\n\n***Character Abilities***\n " << endl;
    }

    return 0;
}
