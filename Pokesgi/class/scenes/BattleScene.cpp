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

sf::Font font;

BattleScene::BattleScene() {
}

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
    
    font.loadFromFile(resourcePath() + "arial.ttf");
    
    LoadPokemons(listPokemonPlayer);
    LoadPokemons(listPokemonCPU);

    ChangePokemon(true, 2);     //Dracaufeu in back
    ChangePokemon(false, 3);    //Pikachu in front

    
    sf::Clock frameClock;
    
    while(running) {
//        sf::Time dt = frameClock.restart();
        //Verifying events
        while (app.pollEvent(event)) {
            switch (event.type) {
                //Close window : exit
                case sf::Event::Closed:
                    return (-1);
                    break;
                    
                //Key pressed
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        //Espace pressed : exit
                        case sf::Keyboard::Escape:
                            return (-1);
                            break;
                            
                        default:
                            break;
                    }
                    break;
                    
                //Mouse click
                case sf::Event::MouseButtonPressed:
                    switch (event.mouseButton.button) {
                        //Click Left
                        case sf::Mouse::Button::Left:
                            cout<<"Click bouton gauche : x=" << event.mouseButton.x << ", y=" << event.mouseButton.y <<endl;
                            break;
                        //Wheel
                        case sf::Mouse::Button::Middle: 
                            cout<<"Click bouton de la molette"<<endl;
                            break;
                        //Click Right
                        case sf::Mouse::Button::Right:  
                            cout<<"Click bouton droit"<<endl;
                            break;
                            
                        default:
                            break;
                    }
                    break;
                    
                default:
                    break;
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
    app.draw(labelHPPlayer);
    app.draw(labelHPCPU);
}

void BattleScene::LoadPokemons(vector<Pokemon> &listPok) {
    listPok.push_back(Pokemon(1, "Bulbizarre"));
    listPok.push_back(Pokemon(3, "Florizarre"));
    listPok.push_back(Pokemon(6, "Dracaufeu"));
    listPok.push_back(Pokemon(25, "Pikachu"));
    listPok.push_back(Pokemon(150, "Mewtwo"));
    listPok.push_back(Pokemon(76, "Grolem"));
    
    cout << "List pokemons: " << listPokemonPlayer.size() << endl;
    for (auto &p: listPok) {
        cout << p.getId() << " " << p.getName() << endl;
    }
}

void BattleScene::ChangePokemon(bool isPlayer, int indexPok) {
    if (isPlayer)
        indexPokemonPlayer = indexPok;
    else
        indexPokemonCPU = indexPok;
    
    Pokemon pok = (isPlayer) ? listPokemonPlayer.at(indexPok) : listPokemonCPU.at(indexPok);
    
    DisplayPokemon(isPlayer, pok.getId());
    DisplayHP(isPlayer, pok);
}



void BattleScene::DisplayPokemon(bool isPlayer, int id) {
    int tileHeight = Pokemon::tileHeight;
    int tileWidth = Pokemon::tileWidth;
    const int scaleSize = 6;
    
    if (id>3) {         //Double Florizarre
        id++;
        if (id>25)      //Double Pikachu
            id++;
    }
    
    const int nbCol = 2;
    //   const int nbRow = 76;
    int pokCol = ((id % nbCol) == 0) ? 1 : 0;
    int pokRow = (id-1) / 2;
    
    cout << "Position : Id=" << id << " Col=" << pokCol << " Row=" << pokRow << endl;
    
    int tileFace = (isPlayer) ? Pokemon::tileBack : Pokemon::tileFront;
    int x = pokCol * tileWidth*Pokemon::nbTileCol;
    int y = (pokRow * tileHeight*Pokemon::nbTileRow) + (tileHeight* tileFace);
    
//    cout << ((isPlayer) ? "Back : " : "Front :") << "x=" << x << " y=" << y << endl;
    
    sf::Sprite *sprite = (isPlayer) ? &pokemon_b : &pokemon_f;
    sprite->setTexture(tilesetTexturePokemons);
    sprite->setTextureRect(sf::IntRect(x, y, tileWidth, tileHeight));
    sprite->setScale(scaleSize, scaleSize);
    if (isPlayer)
        sprite->setPosition(20, 300);
    else
        sprite->setPosition(300, 10);
}

void BattleScene::DisplayHP(bool isPlayer, Pokemon &pkm) {
    sf::Text *label = (isPlayer) ? &labelHPPlayer : &labelHPCPU;
    stringstream hp;
    hp << pkm.getHealthPoint() << "/" << pkm.getHealthPoint();
    label->setString(hp.str());
    label->setFont(font);
    label->setColor(sf::Color::Black);
    label->setCharacterSize(20);
    if (isPlayer)
        label->setPosition(250,50);
    else
        label->setPosition(50,50);
}
