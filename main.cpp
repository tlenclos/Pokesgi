
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// App includes
#include "SceneContainer.h"
#include "GameScene.h"

using namespace std;


int main(int, char const**)
{
    /*
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "images/icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    */
    
    //Applications variables
    std::vector<SceneContainer*> scenes;
    int screen = 0;
    
    //Window creation
    sf::RenderWindow app(sf::VideoMode(512, 512), "Pokesgi");
    
    //Screens preparations
    GameScene game;
    scenes.push_back (&game);
    
    //Main loop
    while (screen >= 0)
    {
        screen = scenes[screen]->Run(app);
    }

    
    return EXIT_SUCCESS;
}
