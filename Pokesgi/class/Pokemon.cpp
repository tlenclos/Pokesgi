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
    healthPoint = 100;
    listAttack = * new vector<Attack>(0);
}

Pokemon::Pokemon(const int id, const string name) : Pokemon::Pokemon() {
    this->id = id;
    this->name = name;
}

//Getters
int Pokemon::getId() const { return id; }
string Pokemon::getName() const { return name; }
string Pokemon::getType() const { return type; }
int Pokemon::getHealthPoint() const { return healthPoint; }
int Pokemon::getLevel() const { return level; }
int Pokemon::getAttack() const { return attack; }
int Pokemon::getDefense() const { return defense; }
int Pokemon::getSpeed() const { return speed; }

//Setters
void Pokemon::setId(int newId) { id = newId; }
void Pokemon::setName(string newName) { name = newName; }
void Pokemon::setType(string newType) { type = newType; }
void Pokemon::setHealthPoint(int newHP) { healthPoint = newHP; }
void Pokemon::setLevel(int newLvl) { level = newLvl; }
void Pokemon::setAttack(int newAtk) { attack = newAtk; }
void Pokemon::setDefense(int newDef) { defense = newDef; }
void Pokemon::setSpeed(int newSpd) { speed = newSpd; }

//Methodes
void Pokemon::takeDamage(int nbDamage){
    healthPoint -= nbDamage;
    if (healthPoint < 0)
        healthPoint = 0;
}

void Pokemon::heal(int nbHealthPoint){
	healthPoint += nbHealthPoint;
}

void Pokemon::launchAttack(Pokemon &pkmTarget, Attack &attack){
    if (attack.getPP() > 0) {
        pkmTarget.takeDamage(attack.getDamage());
        attack--;
    }
}

//Destructor
Pokemon::~Pokemon() {	}

