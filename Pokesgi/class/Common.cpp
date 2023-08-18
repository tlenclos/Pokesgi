//
//  Common.cpp
//  Pokesgi
//
//  Created by Thibault Lenclos on 25/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//
#include <stdlib.h>
#include "Common.h"

#ifdef _WIN32
// Windows (x64 and x86)
#include "ResourcePathDefault.h"
#else
// Helper to get resource Path in UNIX like systems
#include "ResourcePath.hpp"
#endif



void* Common::loadFile( const char * filename, bool appendNull ) {

    FILE* f = fopen( filename, "rb" );
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

Settings Common::settings(resourcePath() + "settings.dat");
