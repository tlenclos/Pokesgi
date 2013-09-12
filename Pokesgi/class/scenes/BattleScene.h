//
//  BattleScene.h
//  Pokesgi
//
//  Created by Julien Wetstein on 20/08/13.
//  Copyright (c) 2013 Julien Wetstein. All rights reserved.
//

#ifndef __Pokesgi__BattleScene__
#define __Pokesgi__BattleScene__

#include <iostream>
#include "Common.h"
#include "Pokemon.h"
#include "SceneContainer.h"

class BattleScene : public SceneContainer {
private:
    sf::Image tilesetImage;
    sf::Image tilesetImageCharacters;
    sf::Image tilesetImagePokemons;
    
    sf::Texture tilesetTexture;
    sf::Texture tilesetTextureCharacters;
    sf::Texture tilesetTexturePokemons;
    
    sf::Sprite pokemon_b;
    sf::Sprite pokemon_f;
    
    std::vector<Pokemon> listPokemonPlayer;
    std::vector<Pokemon> listPokemonCPU;
    
public:
    BattleScene();
    virtual int Run (sf::RenderWindow &app);
    void DrawScene(sf::RenderWindow &app);
    void LoadPokemons(std::vector<Pokemon> &listPok);
    void ChangePokemon(bool isPlayer, int indexPok);
    void DisplayPokemon(bool isPlayer, int id);
};

#endif /* defined(__Pokesgi__BattleScene__) */
