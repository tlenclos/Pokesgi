//
//  Attack.h
//  Pokesgi
//
//  Created by ThundeR on 13/05/13.
//  Copyright (c) 2013 ThundeR. All rights reserved.
//

#ifndef __Pokesgi__Attack__
#define __Pokesgi__Attack__

#include <iostream>
#include <string>

using namespace std;


class Attack{
    
private:
    //Variables
    int id, damage, pp;
    std::string name, type;
    
public:
    Attack();              //Constructeur
    ~Attack();             //Destructeur
    
    //Getters
    string getName() const;
    string getType() const;
    int getDamage() const;
    int getPP() const;
    
    //Setters
    void setName(string newName);
    void setType(string newType);
    void setPP(int newPP);
    void setDamage(int newDamage);
    
    //Methodes
    void launchAttack();
    
    
};

#endif /* defined(__Pokesgi__Attack__) */
