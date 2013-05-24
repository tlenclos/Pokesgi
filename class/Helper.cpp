//
//  Helper.cpp
//  Pokesgi
//
//  Created by Thibault Lenclos on 24/05/13.
//  Copyright (c) 2013 Thibault Lenclos. All rights reserved.
//

#include "Helper.h"

void* Helper::loadFile( const char * filename, bool appendNull ) {
    
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