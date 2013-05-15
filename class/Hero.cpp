//
//  Hero.cpp
//  Pokesgi
//
//  Created by Thibault Lenclos on 14/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

#include "Hero.h"

using namespace std;

Hero::Hero() {}
Hero::Hero(string name) {
    setName(name);
}

// Add controls to move hero
void Hero::listenInputs() {    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        cout << "Up" << endl;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        cout << "Right" << endl;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        cout << "Down" << endl;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        cout << "Left" << endl;
    }
}

// Destructor
Hero::~Hero() {	}