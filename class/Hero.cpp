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

void Hero::heroInit() {
    // Aniations
    Animation backAnimation;
    backAnimation.setSpriteSheet(texture);
    backAnimation.addFrame(sf::IntRect(4, 580, tileWidth, tileHeight));
    backAnimation.addFrame(sf::IntRect(99, 579, tileWidth, tileHeight));
    backAnimation.addFrame(sf::IntRect(4, 580, tileWidth, tileHeight));
    backAnimation.addFrame(sf::IntRect(99, 579, tileWidth, tileHeight));
    animations[0] = backAnimation;
    
    Animation rightAnimation;
    rightAnimation.setSpriteSheet(texture);
    rightAnimation.addFrame(sf::IntRect(52, 580, tileWidth, tileHeight));
    rightAnimation.addFrame(sf::IntRect(52, 611, tileWidth, tileHeight));
    rightAnimation.addFrame(sf::IntRect(52, 580, tileWidth, tileHeight));
    rightAnimation.addFrame(sf::IntRect(52, 611, tileWidth, tileHeight));
    animations[1] = rightAnimation;
    
    Animation faceAnimation;
    faceAnimation.setSpriteSheet(texture);
    faceAnimation.addFrame(sf::IntRect(98, 612, tileWidth, tileHeight));
    faceAnimation.addFrame(sf::IntRect(98, 643, tileWidth, tileHeight));
    faceAnimation.addFrame(sf::IntRect(98, 612, tileWidth, tileHeight));
    faceAnimation.addFrame(sf::IntRect(98, 643, tileWidth, tileHeight));
    animations[2] = faceAnimation;
    
    Animation leftAnimation;
    leftAnimation.setSpriteSheet(texture);
    leftAnimation.addFrame(sf::IntRect(4, 644, tileWidth, tileHeight));
    leftAnimation.addFrame(sf::IntRect(4, 611, tileWidth, tileHeight));
    leftAnimation.addFrame(sf::IntRect(4, 644, tileWidth, tileHeight));
    leftAnimation.addFrame(sf::IntRect(4, 611, tileWidth, tileHeight));
    animations[3] = leftAnimation;
    
    // Sprite
    AnimatedSprite sprite(sf::seconds(0.2));
    sprite.setAnimation(animations[2]);
    setSprite(sprite);
}

Hero::Hero(string name, sf::Texture &texture) {
    setName(name);
    setTexture(texture);
    heroInit();
}

// Getters
AnimatedSprite Hero::getSprite() const {
    return sprite;
}
sf::Texture Hero::getTexture() const {
    return texture;
}

// Setters
void Hero::setSprite(AnimatedSprite newSprite) {
    sprite = newSprite;
}
void Hero::setTexture(sf::Texture newTexture) {
    texture = newTexture;
}

// Add controls to move hero
void Hero::listenInputs() {
    sf::Vector2u position = getPosition();
    int speed = 3;
    bool inAction = false;
    Orientation newOrientation = orientation;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        cout << "Up" << endl;
        position.y -= speed;
        newOrientation = Orientation::North;
        inAction = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        cout << "Right" << endl;
        position.x += speed;
        newOrientation = Orientation::East;
        inAction = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        cout << "Down" << endl;
        position.y += speed;
        newOrientation = Orientation::South;
        inAction = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        cout << "Left" << endl;
        position.x -= speed;
        newOrientation = Orientation::West;
        inAction = true;
    }
    
    if (newOrientation != orientation) {
        orientation = newOrientation;
        sprite.setAnimation(animations[orientation]);
    }
    
    if (inAction) {
        sprite.play();
    } else {
        sprite.pause();
    }
    
    setPosition(position);
    sprite.setPosition(position.x, position.y);
}

// Update sprite state
void Hero::update(sf::Time time) {
    sprite.update(time);
}

// Destructor
Hero::~Hero() {	}