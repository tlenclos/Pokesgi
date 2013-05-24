//
//  GameScene.h
//  Pokesgi
//
//  Created by Thibault Lenclos on 24/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

#ifndef __Pokesgi__GameScene__
#define __Pokesgi__GameScene__

#include <iostream>
#include "SceneContainer.h"

class GameScene : public SceneContainer
{
private:
public:
    GameScene();
    virtual int Run (sf::RenderWindow &app);
};

#endif /* defined(__Pokesgi__GameScene__) */
