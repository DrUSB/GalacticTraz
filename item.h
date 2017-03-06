#ifndef item_H
#define item_H
#include <string>

using namespace std;

class item
{
    public:
    //Constructor
    item();
    //Destructor
    ~item();
    //Methods
    string getName();
    string getInfo();
    
    //Overload Constructor
    item(string,string);
    
    private:
    string info;
    string item_name;
    
};

#endif //item_H
