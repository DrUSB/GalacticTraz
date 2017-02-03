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
        cout << "**********-------------Help Menu--------------**********\n***Movements:***\nMove North\nMove East\nMove South\nMove West" << endl;
    }

    return 0;
}
