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
    int id, healthPoint, level, attack, defense, speed;
    string name, type;
    
public:
    Pokemon();              //Constructeur
    ~Pokemon();             //Destructeur
    
    //Variables
    std::vector<Attack> listAttack;
    
    //Getters
    string getName() const;
    string getType() const;
    int getHealthPoint() const;
    int getLevel() const;
    int getAttack() const;
    int getDefense() const;
    int getSpeed() const;

    //Setters
    void setName(string newName);
    void setType(string newType);
    void setHealthPoint(int newHP);
    void setLevel(int newLvl);
    void setAttack(int newAtk);
    void setDefense(int newDef);
    void setSpeed(int newSpd);
    
    //Methodes
    void takeDamage(int nbDamage);
    void heal(int nbHealthPoint);


    void launchAttack(Pokemon &pkmTarget, Attack &attack);
    
    
};


#endif /* defined(__Pokesgi__Pokemon__) */
