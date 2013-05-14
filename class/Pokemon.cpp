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
    hp = 100;
    listAttack = * new vector<Attack>(0);
}

//Getters
string Pokemon::getName() const { return name; }
string Pokemon::getType() const { return type; }
int Pokemon::getHP() const { return hp; }
int Pokemon::getLevel() const { return lvl; }
int Pokemon::getAtk() const { return atk; }
int Pokemon::getDef() const { return def; }
int Pokemon::getSpd() const { return spd; }

//Setters
void Pokemon::setName(string newName) { name = newName; }
void Pokemon::setType(string newType) { type = newType; }
void Pokemon::setHP(int newHP) { hp = newHP; }
void Pokemon::setLevel(int newLvl) { lvl = newLvl; }
void Pokemon::setAtk(int newAtk) { atk = newAtk; }
void Pokemon::setDef(int newDef) { def = newDef; }
void Pokemon::setSpd(int newSpd) { spd = newSpd; }

//Methodes
void Pokemon::addDamage(int nbDamage){
    hp -= nbDamage;
    if (hp < 0)
        hp = 0;
}

void Pokemon::launchAttack(Pokemon &pkmTarget, Attack &attack){
    if (attack.getPP() > 0) {
        pkmTarget.addDamage(attack.getDamage());
        attack--;
    }
}

//Destructor
Pokemon::~Pokemon() {	}

