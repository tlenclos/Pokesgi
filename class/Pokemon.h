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
    int id, pv, lvl, att, def, vit;
    string name, type;
    
public:
    Pokemon();              //Constructeur
    ~Pokemon();             //Destructeur
    
    //Variables
    std::vector<Attack> listAttack;
    
    //Getters
    string getName() const;
    string getType() const;
    int getPV() const;
    int getLevel() const;
    int getAtt() const;
    int getDef() const;
    int getVit() const;

    //Setters
    void setName(string newName);
    void setType(string newType);
    void setPV(int newPV);
    void setLevel(int newLvl);
    void setAtt(int newAtt);
    void setDef(int newDef);
    void setVit(int newVit);
    
    //Methodes
    void addDamage(int nbDamage);
    void attack(Pokemon &pkmTarget);
    
    
};


#endif /* defined(__Pokesgi__Pokemon__) */
