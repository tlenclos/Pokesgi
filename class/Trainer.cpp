//
//  Trainer.cpp
//  Pokesgi
//
//  Created by Thibault Lenclos on 14/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

#include "Trainer.h"

using namespace std;

//Constructor
Trainer::Trainer() {
    pokemons = * new vector<Pokemon>(0);
    items = * new vector<Item>(0);
	gold = 0;
}

//Destructor
Trainer::~Trainer() {	}

//Methods
int Trainer::getGold() const { return gold; }
void Trainer::setGold(int newGold) { gold = newGold; }

void Trainer::addGold(int numberGold) {gold += numberGold;}
void Trainer::removeGold(int numberGold) {gold -= numberGold;}