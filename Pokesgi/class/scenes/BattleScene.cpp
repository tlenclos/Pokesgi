//
//  BattleScene.cpp
//  Pokesgi
//
//  Created by Julien Wetstein on 20/08/13.
//  Copyright (c) 2013 Julien Wetstein. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "BattleScene.h"
#include "Hero.h"
#include "Pokemon.h"

using namespace std;

struct Layer{
    int opacity;
};

BattleScene::BattleScene() {}

int BattleScene::Run(sf::RenderWindow &app) {
    bool running = true;
    sf::Event event;
    
    int width, height;
    Common::settings.Get("width", &width);
    Common::settings.Get("height", &height);
    
    // Ressources
    string resPathTilesetPokemons = resourcePath() + "images/pokemons.png";
    string resPathTilesetCharacters = resourcePath() + "images/personen-dp.png";

    // Test Pokemons
    if (!tilesetImagePokemons.loadFromFile(resPathTilesetPokemons))
    {
        cout << "Failed to load pokemons tile sheet." << endl;
        return false;
    }
    tilesetTexturePokemons.loadFromImage(tilesetImagePokemons);
    
    // This stores each layer of sprites/tiles so they can be drawn in order.
    std::vector <Layer> layers;

    ChangePokemon(true, 0, 3);  //Dracaufeu in back
    ChangePokemon(false, 1, 4);  //Tortank in front
    
    sf::Clock frameClock;
    
    while(running) {
        sf::Time dt = frameClock.restart();
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
        }

        //Clear and change background color
        app.clear(sf::Color(242, 228, 225));
        
        DrawScene(app);
        // Draw
//        for (int layer = 0; layer < layers.size(); layer++) {
//            for (int tile = 0; tile < layers[layer].tiles.size(); tile++) {
//                app.draw(layers[layer].tiles[tile]);
//            }
//        }

        app.display();
    }
    
    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}

void BattleScene::DrawScene(sf::RenderWindow &app) {
    app.draw(pokemon_b);
    app.draw(pokemon_f);
}

void BattleScene::ChangePokemon(bool isPlayer, int pokCol, int pokRow) {
    int tileHeight = Pokemon::tileHeight;
    int tileWidth = Pokemon::tileWidth;
    int scaleSize = 6;
    
    if (isPlayer) {     //Bottom-Left Back
        int x = pokCol * tileWidth*Pokemon::nbTileCol;
        int y = (pokRow * tileHeight*Pokemon::nbTileRow) + (tileHeight*Pokemon::tileBack);
        cout << "Back : " << "x=" << x << " y=" << y << endl;
        pokemon_b.setTexture(tilesetTexturePokemons);
        pokemon_b.setTextureRect(sf::IntRect(x, y, tileWidth, tileHeight));
        pokemon_b.setPosition(20, 300);
        pokemon_b.setScale(scaleSize, scaleSize);
    } else {            //Top-Right Front
        int x = pokCol * tileWidth*Pokemon::nbTileCol;
        int y = (pokRow * tileHeight*Pokemon::nbTileRow) + (tileHeight*Pokemon::tileFront);
        cout << "Front : " << "x=" << x << " y=" << y << endl;
        pokemon_f.setTexture(tilesetTexturePokemons);
        pokemon_f.setTextureRect(sf::IntRect(x, y, tileWidth, tileHeight));
        pokemon_f.setPosition(300, 10);
        pokemon_f.setScale(scaleSize, scaleSize);
    }
}