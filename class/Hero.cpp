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

Hero::Hero() {
    // Rects position for the 4 character images (back, right, face, left)
    rects = new sf::Rect<int>[4];
    
    // Back image
    sf::Rect <int> backRect;
    backRect.top = 556 + tileHeight;
    backRect.left = -19 + tileWidth;
    backRect.height = tileHeight;
    backRect.width = tileWidth;
    rects[0] = backRect;
   
    // Right image
    sf::Rect <int> rightRect;
    rightRect.top = 556 + tileHeight;
    rightRect.left = 30 + tileWidth;
    rightRect.height = tileHeight;
    rightRect.width = tileWidth;
    rects[1] = rightRect;
    
    // Face image
    sf::Rect <int> faceRect;
    faceRect.top = 588 + tileHeight;
    faceRect.left = 78 + tileWidth;
    faceRect.height = tileHeight;
    faceRect.width = tileWidth;
    rects[2] = faceRect;
    
    // Left image
    sf::Rect <int> leftRect;
    leftRect.top = 620 + tileHeight;
    leftRect.left = -19 + tileWidth;
    leftRect.height = tileHeight;
    leftRect.width = tileWidth;
    rects[3] = leftRect;
}

Hero::Hero(string name, sf::Texture &texture) : Hero::Hero() {
    setName(name);
    setTexture(texture);

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(rects[3]);
    setSprite(sprite);
    
    cout << "Texture size " << texture.getSize().x << "/" << texture.getSize().y << endl;
}

// Getters
sf::Sprite Hero::getSprite() const {
    return sprite;
}
sf::Texture Hero::getTexture() const {
    return texture;
}

// Setters
void Hero::setSprite(sf::Sprite newSprite) {
    sprite = newSprite;
}
void Hero::setTexture(sf::Texture newTexture) {
    texture = newTexture;
}

// Add controls to move hero
void Hero::listenInputs() {
    sf::Vector2u position = getPosition();
    int speed = 3;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        cout << "Up" << endl;
        position.y -= speed;
        sprite.setTextureRect(rects[0]);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        cout << "Right" << endl;
        position.x += speed;
        sprite.setTextureRect(rects[1]);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        cout << "Down" << endl;
        position.y += speed;
        sprite.setTextureRect(rects[2]);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        cout << "Left" << endl;
        position.x -= speed;
        sprite.setTextureRect(rects[3]);
    }
    
    setPosition(position);
    sprite.setPosition(position.x, position.y);
}

// Destructor
Hero::~Hero() {	}