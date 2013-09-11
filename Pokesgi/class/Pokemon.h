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
    
    const static int tileHeight = 32;
    const static int tileWidth = 32;
    const static int tileFront = 2;     //Index of the Row to get pokemon in front
    const static int tileBack = 0;      //Index of the Row to get pokemon in back
    const static int nbTileCol = 2;     //Number of columns tiles for a pokemon
    const static int nbTileRow = 4;     //Number of rows tiles for a pokemon
    
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
