#ifndef __Pokesgi__Item__
#define __Pokesgi__Item__

#include <string>

using namespace std;

class Item
{
private:
    // Variables
    int id;
    string name;

public:
    enum TypeItem {
        Recovery,
        PokeBall,
        Repel,
        Key
    };
    TypeItem typeItem;

public:
    Item();
    ~Item();
    Item(string newName);

    //getters
    int getId() const;
    string getName() const;
    
    // Setters
    void setId(int newName);
    void setName(string newName);
};


#endif /* defined(__Pokesgi__Item__) */