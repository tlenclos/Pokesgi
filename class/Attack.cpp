//
//  Attack.cpp
//  Pokesgi
//
//  Created by ThundeR on 13/05/13.
//  Copyright (c) 2013 ThundeR. All rights reserved.
//

#include "Attack.h"

//Constructor
Attack::Attack() {
   
}

//Getters
int Attack::getDamage() const { return damage; }
int Attack::getPP() const { return pp; }
string Attack::getName() const { return name; }
string Attack::getType() const { return type; }

//Setters
void Attack::setName(string newName) { name = newName; }
void Attack::setType(string newType) { type = newType; }
void Attack::setPP(int newPP) { pp = newPP; }
void Attack::setDamage(int newDamage) { damage = newDamage; }

//Methodes
void launchAttack() {
    
}

//Destructor
Attack::~Attack() {	}
