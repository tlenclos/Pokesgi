#include "Item.h"

using namespace std;


Item::Item(string newName){
	name=newName;
}

//getters
int Item::getId() const {return id;}
string Item::getName() const{return name;}
	
// Setters
void Item::setId(int newId) {id = newId;}
void Item::setName(string newName) {name= newName;}

Item::Item()
{

}


Item::~Item()
{
}
