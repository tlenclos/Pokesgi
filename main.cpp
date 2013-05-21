
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

#ifdef __APPLE__
// Helper to get resource Path in OSX app
#include "ResourcePath.hpp"
#endif

#ifdef _WIN32
// Windows (x64 and x86)
#include "ResourcePathDefault.h"
#endif

// App includes
#include "NLTmxMap.h"
#include "Hero.h"

using namespace std;

struct Layer{
    int opacity;
    std::vector <sf::Sprite> tiles;
};

static void* loadFile( const char * filename, bool appendNull ) {
    
    FILE* f = fopen( filename, "r" );
    if ( !f ) {
        return 0;
    }
    
    fseek( f, 0, SEEK_END );
    auto length = ftell( f ) + appendNull;
    fseek( f, 0, SEEK_SET );
    
    void* buffer = malloc( length );
    fread( buffer, length, 1, f );
    fclose( f );
    
    if ( appendNull ) {
        ((char*)buffer)[ length-1 ] = 0;
    }
    
    return buffer;
}

int main(int, char const**)
{
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
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(512, 512), "Pokesgi");
    
    // Map loader
    const char* resPathMapChar = const_cast<char*>(resPathMap.c_str());

    char * xml = (char*) loadFile(resPathMapChar, true );
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

    /******
       UI
    *******/
    /*
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "images/icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    */
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Espace pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            ash.listenInputs();
        }

        // Clear screen
        window.clear();
        
        // Draw
        for (int layer = 0; layer < layers.size(); layer++)
        {
            for (int tile = 0; tile < layers[layer].tiles.size(); tile++)
            {
                window.draw(layers[layer].tiles[tile]);
                /*
                 if (drawingBounds.Contains(layers[layer].tiles[tile].GetPosition().x, layers[layer].tiles[tile].GetPosition().y))
                 {
                 
                 }
                 */
            }
        }
        window.draw(ash.getSprite());

        // Update the window
        window.display();
    }

    
    return EXIT_SUCCESS;
}
