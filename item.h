#ifndef item_H
#define item_H

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