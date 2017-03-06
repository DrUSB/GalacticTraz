#include "item.h"

//Contructor
item::item()
{
        
}

//Destructor
item::~item()
{
    
}

//Overload Constructor
item::item(string input_name,string input_info)
{
    item_name = input_name;
    info = input_info;
    
}

//Methods
string item::getName()
{
    return item_name;
}

string item::getInfo()
{
    return info;
}
