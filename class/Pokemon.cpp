//
//  Pokemon.cpp
//  Pokesgi
//
//  Created by ThundeR on 13/05/13.
//  Copyright (c) 2013 ThundeR. All rights reserved.
//

#include "Pokemon.h"

using namespace std;

//Constructor
Pokemon::Pokemon() {
    pv = 100;
    listAttack = * new vector<Attack>(0);
}

//Getters
string Pokemon::getName() const { return name; }
string Pokemon::getType() const { return type; }
int Pokemon::getPV() const { return pv; }
int Pokemon::getLevel() const { return lvl; }
int Pokemon::getAtt() const { return att; }
int Pokemon::getDef() const { return def; }
int Pokemon::getVit() const { return vit; }

//Setters
void Pokemon::setName(string newName) { name = newName; }
void Pokemon::setType(string newType) { type = newType; }
void Pokemon::setPV(int newPV) { pv = newPV; }
void Pokemon::setLevel(int newLvl) { lvl = newLvl; }
void Pokemon::setAtt(int newAtt) { att = newAtt; }
void Pokemon::setDef(int newDef) { def = newDef; }
void Pokemon::setVit(int newVit) { vit = newVit; }

//Methodes
void Pokemon::addDamage(int nbDamage){
    pv -= nbDamage;
    if (pv < 0)
        pv = 0;
}

void Pokemon::attack(Pokemon &pkmTarget){
    //pkmTarget.addDamage();
}

//Destructor
Pokemon::~Pokemon() {	}

