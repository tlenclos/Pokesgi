//
//  Person.h
//  Pokesgi
//
//  Created by Thibault Lenclos on 14/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

#ifndef __Pokesgi__Person__
#define __Pokesgi__Person__

#include <iostream>
#include <SFML/System.hpp>

using namespace std;

class Person {
    
private:
    // Variables
    string name;
    sf::Vector2u position;
    
public:
    Person(); // Constructeur
    Person(string name);
    ~Person(); // Destructeur

    // Getters
    string getName() const;
    sf::Vector2u getPosition();
    
    // Setters
    void setName(string newName);
    void setPosition(sf::Vector2u newPosition);
    
};

#endif /* defined(__Pokesgi__Person__) */
