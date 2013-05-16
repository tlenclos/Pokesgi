//
//  Hero.h
//  Pokesgi
//
//  Created by Thibault Lenclos on 14/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

#ifndef __Pokesgi__Hero__
#define __Pokesgi__Hero__

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Trainer.h"


class Hero : public Trainer
{
public:
    Hero(); // Constructeur
    Hero(string name);
    ~Hero(); // Destructeur
    
    // Methodes
    void listenInputs();
};

#endif /* defined(__Pokesgi__Hero__) */
