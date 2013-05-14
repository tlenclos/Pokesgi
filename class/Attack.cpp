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


//Operator
Attack& Attack::operator--() {
    pp--;
    return *this;
}

Attack Attack::operator--(const int i) {
    Attack atk = *this;
    pp--;
    return atk;
}

//Destructor
Attack::~Attack() {	}
