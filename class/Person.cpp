//
//  Person.cpp
//  Pokesgi
//
//  Created by Thibault Lenclos on 14/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

#include "Person.h"

using namespace std;

// Constructor
Person::Person() {}
Person::Person(string name) {
    setName(name);
}

// Getters
string Person::getName() const { return name; }
sf::Vector2u Person::getPosition() { return position; }

// Setters
void Person::setName(string newName) { name = newName; }
void Person::setPosition(sf::Vector2u newPosition) { position = newPosition; }

// Destructor
Person::~Person() {	}

int Person::tileHeight = 24;
int Person::tileWidth = 22;
