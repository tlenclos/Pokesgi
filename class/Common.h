//
//  Common.h
//  Pokesgi
//
//  Created by Thibault Lenclos on 25/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

#ifndef __Pokesgi__Common__
#define __Pokesgi__Common__

#include <iostream>
#include "Settings.h"

class Common {
public:
    static Settings settings;
    static void* loadFile(const char * filename, bool appendNull);
};

#endif /* defined(__Pokesgi__Common__) */
