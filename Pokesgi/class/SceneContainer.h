//
//  ScenesContainer.h
//  Pokesgi
//
//  Created by Thibault Lenclos on 24/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

#ifndef __Pokesgi__ScenesContainer__
#define __Pokesgi__ScenesContainer__

#ifdef _WIN32
// Windows (x64 and x86)
#include "ResourcePathDefault.h"
#else
// Helper to get resource Path in UNIX like systems
#include "ResourcePath.hpp"
#endif


#include <iostream>
#include <SFML/Graphics.hpp>
#include <NLTmx/NLTmxMap.h>

class SceneContainer {
public :
    virtual int Run (sf::RenderWindow &App) = 0;
};

#endif /* defined(__Pokesgi__ScenesContainer__) */
