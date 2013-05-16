//
//  Hero.cpp
//  Pokesgi
//
//  Created by Thibault Lenclos on 14/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

// TODO : Add reference to the texture in a private property of Hero
#include "Hero.h"

using namespace std;

Hero::Hero() {}

Hero::Hero(string name, sf::Texture texture) : Hero::Hero() {
    setName(name);
    
    int tileHeight = 100;
    int tileWidth = 100;
    
    sf::Rect <int> rect;
    rect.top = 3 * tileHeight;
    rect.left = 3 * tileWidth;
    rect.height = tileHeight;
    rect.width = tileWidth;
    
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(rect);
    setSprite(sprite);
    
    cout << "Texture size " << texture.getSize().x << "/" << texture.getSize().y << endl;
}

// Getters
sf::Sprite Hero::getSprite() const {
    return sprite;
}

// Setters
void Hero::setSprite(sf::Sprite newSprite) {
    sprite = newSprite;
}

// Add controls to move hero
void Hero::listenInputs() {
    sf::Vector2u position = getPosition();
    int speed = 3;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        cout << "Up" << endl;
        position.y -= speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        cout << "Right" << endl;
        position.x += speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        cout << "Down" << endl;
        position.y += speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        cout << "Left" << endl;
        position.x -= speed;
    }
    
    setPosition(position);
    sprite.setPosition(position.x, position.y);
}

// Destructor
Hero::~Hero() {	}