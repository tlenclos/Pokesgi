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
#include "AnimatedSprite.h"

class Hero : public Trainer
{
private:
    // Variables
    Animation animations[4];
    AnimatedSprite sprite;
    sf::Texture texture;
public:
    Hero(); // Constructeur
    Hero(string name, sf::Texture &texture);
    ~Hero(); // Destructeur
    
    // Getters
    AnimatedSprite getSprite() const;
    sf::Texture getTexture() const;
    
    // Setters
    void setSprite(AnimatedSprite sprite);
    void setTexture(sf::Texture texture);
    
    // Methodes
    void heroInit();
    void listenInputs(sf::Time elapsedTime);
    void update(sf::Time time); // update state
};

#endif /* defined(__Pokesgi__Hero__) */
