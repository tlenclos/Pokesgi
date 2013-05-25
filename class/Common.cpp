//
//  Common.cpp
//  Pokesgi
//
//  Created by Thibault Lenclos on 25/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

#include "Common.h"

#ifdef __APPLE__
// Helper to get resource Path in OSX app
#include "ResourcePath.hpp"
#endif

#ifdef _WIN32
// Windows (x64 and x86)
#include "ResourcePathDefault.h"
#endif

Settings Common::settings(resourcePath() + "settings.dat");