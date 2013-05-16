//
//  Pokemon.h
//  Pokesgi
//
//  Created by ThundeR on 13/05/13.
//  Copyright (c) 2013 ThundeR. All rights reserved.
//

#ifndef __Pokesgi__Pokemon__
#define __Pokesgi__Pokemon__

#include <iostream>
#include <string>
#include <vector>
#include "Attack.h"

using namespace std;

class Pokemon{
    
private:
    //Variables
    int id, hp, lvl, atk, def, spd;
    string name, type;
    
public:
    Pokemon();              //Constructeur
    ~Pokemon();             //Destructeur
    
    //Variables
    std::vector<Attack> listAttack;
    
    //Getters
    string getName() const;
    string getType() const;
    int getHP() const;
    int getLevel() const;
    int getAtk() const;
    int getDef() const;
    int getSpd() const;

    //Setters
    void setName(string newName);
    void setType(string newType);
    void setHP(int newHP);
    void setLevel(int newLvl);
    void setAtk(int newAtk);
    void setDef(int newDef);
    void setSpd(int newSpd);
    
    //Methodes
    void addDamage(int nbDamage);
    void launchAttack(Pokemon &pkmTarget, Attack &attack);
    
    
};


#endif /* defined(__Pokesgi__Pokemon__) */
