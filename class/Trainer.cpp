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
}

//Destructor
Trainer::~Trainer() {	}

