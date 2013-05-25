
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
#include "assert.h"

// App includes
#include "Settings.h"
#include "SceneContainer.h"
#include "GameScene.h"

using namespace std;


int main(int, char const**)
{
    // Test settings
	Settings settings(resourcePath() + "settings.dat");
	int width, height;
    string appTitle;
	settings.Get("width", &width);
	settings.Get("height", &height);
    settings.Get("title", &appTitle);
    assert(width > 0);
    assert(height > 0);
    assert(appTitle.length() > 0);
    
    //Applications variables
    std::vector<SceneContainer*> scenes;
    int screen = 0;
    
    //Window creation
    sf::RenderWindow app(sf::VideoMode(width, height), appTitle);
    
    //App icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "images/icon.png")) {
        return EXIT_FAILURE;
    }
    app.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
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
