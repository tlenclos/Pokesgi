//
//  Trainer.h
//  Pokesgi
//
//  Created by Thibault Lenclos on 14/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

#ifndef __Pokesgi__Trainer__
#define __Pokesgi__Trainer__

#include <iostream>
#include <string>
#include <vector>

#include "Person.h"
#include "Pokemon.h"

using namespace std;

class Trainer : public Person {
    
public:
    Trainer(); // Constructeur
    ~Trainer(); // Destructeur
    
    // Variables
    vector<Pokemon> pokemons;
    //vector<Item> items;   TODO after
};

#endif /* defined(__Pokesgi__Trainer__) */
