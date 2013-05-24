//
//  GameScene.cpp
//  Pokesgi
//
//  Created by Thibault Lenclos on 24/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "Helper.h"
#include "GameScene.h"
#include "Hero.h"

using namespace std;

struct Layer{
    int opacity;
    std::vector <sf::Sprite> tiles;
};

GameScene::GameScene() {}

int GameScene::Run(sf::RenderWindow &app) {
    bool running = true;
    sf::Event event;
    
    // Ressources
    string resPathMap = resourcePath() + "map.tmx";
    string resPathTileset = resourcePath() + "tileset-shinygold.png";
    string resPathTilesetCharacters = resourcePath() + "personen-dp.png";
    
    // Test Hero
    sf::Image tilesetImageCharacters;
    if (!tilesetImageCharacters.loadFromFile(resPathTilesetCharacters))
    {
        cout << "Failed to load characters tile sheet." << endl;
        return false;
    }
    sf::Texture tilesetTextureCharacters;
    tilesetTextureCharacters.loadFromImage(tilesetImageCharacters);
    
    Hero ash("Ash", tilesetTextureCharacters);
    sf::Vector2u initPosition(2, 5);
    ash.setPosition(initPosition);
    cout << ash.getName() + " est à la position " << ash.getPosition().x << "/" << ash.getPosition().y << endl;
    
    // Map loader
    const char* resPathMapChar = const_cast<char*>(resPathMap.c_str());
    char * xml = (char*) Helper::loadFile(resPathMapChar, true );
    NLTmxMap* map = NLLoadTmxMap( xml );
    
    
    int tileWidth = map->tileWidth;
    int tileHeight = map->tileHeight;
    int firstgid = 1; // TODO : Try to get it from TMX file
    
    // This stores each layer of sprites/tiles so they can be drawn in order.
    std::vector <Layer> layers;
    
    // Tileset loader
    sf::Image tilesetImage;
    if (!tilesetImage.loadFromFile(resPathTileset)) // Load the tileset image
    {
        cout << "Failed to load tile sheet." << endl;
        return false;
    }
    sf::Texture tilesetTexture;
    tilesetTexture.loadFromImage(tilesetImage);
    
    sf::Vector2u tilesetSize = tilesetImage.getSize();
    int columns = tilesetSize.x / tileWidth;
    int rows = tilesetSize.y / tileHeight;
    
    // tiles/subrects are counted from 0, left to right, top to bottom
    std::vector <sf::Rect<int> > subRects; // container of subrects (to divide the tilesheet image up)
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            sf::Rect <int> rect;
            rect.top = y * tileHeight;
            rect.left = x * tileWidth;
            rect.height = tileHeight;
            rect.width = tileWidth;
            subRects.push_back(rect);
        }
    }
    
    for(auto layer : map->layers)
    {
        Layer layerMap;
        int dataSize = layer->width*layer->height;
        int x = 0;
        int y = 0;
        
        cout << layer->name << endl;
        
        for(int i = 0; i < dataSize; i++) {
            int subRectToUse = layer->data[i] - firstgid;
            if(subRectToUse >= 0) {
                sf::Sprite sprite;
                sprite.setTexture(tilesetTexture);
                sprite.setTextureRect(subRects[subRectToUse]);
                sprite.setPosition(x * tileWidth, y * tileHeight);
                layerMap.tiles.push_back(sprite);
            }
            
            //increment x, y
            x++;
            if (x >= layer->width)//if x has "hit" the end (right) of the map, reset it to the start (left)
            {
                x = 0;
                y++;
                if (y >= layer->height)
                {
                    y = 0;
                }
            }
        }
        layers.push_back(layerMap);
    }
    
    while(running) {
        //Verifying events
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
            
            // Espace pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                return (-1);
            }
            
            ash.listenInputs();
        }
        
        // Draw
        for (int layer = 0; layer < layers.size(); layer++)
        {
            for (int tile = 0; tile < layers[layer].tiles.size(); tile++)
            {
                app.draw(layers[layer].tiles[tile]);
            }
        }
        app.draw(ash.getSprite());
        
        app.display();
    }
    
    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}