#include "rapidxml.hpp"
#include <iostream>
#include <string.h>
#include "NLTmxMap.h"

using namespace rapidxml;

NLTmxMap* NLLoadTmxMap( char *xml )
{
    xml_document<> doc;
    doc.parse<0>( xml );
    
    xml_node<> *mapnode = doc.first_node("map");
    
    NLTmxMap* map = new NLTmxMap();
    
    map->width = atoi( mapnode->first_attribute( "width" )->value() );
    map->height = atoi( mapnode->first_attribute( "height" )->value() );
    map->tileWidth = atoi( mapnode->first_attribute( "tilewidth" )->value() );
    map->tileHeight = atoi( mapnode->first_attribute( "tileheight" )->value() );
    
    xml_node<> *tilesetnode = mapnode->first_node( "tileset" );
    
    while ( tilesetnode ) {
        NLTmxMapTileset* tileset = new NLTmxMapTileset();
        
        tileset->firstGid = atoi( tilesetnode->first_attribute( "firstgid" )->value() );
        tileset->name = tilesetnode->first_attribute( "name" )->value();
        tileset->tileWidth =  atoi( tilesetnode->first_attribute( "tilewidth" )->value() );
        tileset->tileHeight = atoi( tilesetnode->first_attribute( "tileheight" )->value() );
        tileset->filename = tilesetnode->first_node( "image" )->first_attribute( "source" )->value();
        
        map->tilesets.push_back( tileset );
        
        tilesetnode = tilesetnode->next_sibling( "tileset" );
    }
    
    const char *separators = " \t,\n\r";
    
    xml_node<> *layernode = mapnode->first_node( "layer" );
    
    while ( layernode ) {
        NLTmxMapLayer* layer = new NLTmxMapLayer();
        
        layer->name = layernode->first_attribute( "name" )->value();
        layer->width = atoi( layernode->first_attribute( "width" )->value() );
        layer->height = atoi( layernode->first_attribute( "height" )->value() );
        
        // TODO assert that the "encoding" attribute is set to "CSV" here.
        
        const char* data = layernode->first_node( "data" )->value();
        
        layer->data = new int[ layer->width * layer->height ];
        
        char* copy = (char*) malloc( strlen( data ) + 1 );
        strcpy( copy, data );
        char* item = strtok( copy, separators );

        int index = 0;
        while ( item ) {
            layer->data[ index ] = atoi( item );
            index++;
            
            item = strtok( 0, separators );
        }

        free( copy );
        
        map->layers.push_back( layer );
        
        layernode = layernode->next_sibling( "layer" );
    }
    
    xml_node<> *objectgroupnode = mapnode->first_node( "objectgroup" );
    
    while ( objectgroupnode ) {
        NLTmxMapObjectGroup* group = new NLTmxMapObjectGroup();
        
        group->name = objectgroupnode->first_attribute( "name" )->value();
        group->width = atoi( objectgroupnode->first_attribute( "width" )->value() );
        group->height = atoi( objectgroupnode->first_attribute( "height" )->value() );
        
        xml_attribute<> *visibleattr = objectgroupnode->first_attribute( "visible" );
        if ( visibleattr ) {
            group->visible = atoi( visibleattr->value() );
        } else {
            group->visible = true;
        }
        
        xml_node<> *objectnode = objectgroupnode->first_node( "object" );
        
        while ( objectnode ) {
            NLTmxMapObject* object = new NLTmxMapObject();
            
            auto nameattr = objectnode->first_attribute( "name" );
            if ( nameattr ) {
                object->name = nameattr->value();
            }
            auto gidattr = objectnode->first_attribute( "gid" );
            if ( gidattr ) {
                object->gid = atoi( gidattr->value() );
            }
            object->x = atoi( objectnode->first_attribute( "x" )->value() );
            object->y = atoi( objectnode->first_attribute( "y" )->value() );
            
            auto widthattr = objectnode->first_attribute( "width" );
            if ( widthattr ) {
                object->width = atoi( widthattr->value() );
            }
            
            auto heightattr = objectnode->first_attribute( "height" );
            if ( heightattr ) {
                object->height = atoi( heightattr->value() );
            }
            
            xml_node<> *propertiesnode = objectnode->first_node( "properties" );
            
            if ( propertiesnode ) {
                
                xml_node<> *propertynode = propertiesnode->first_node( "property" );
                
                while ( propertynode ) {
                    NLTmxMapObjectProperty* property = new NLTmxMapObjectProperty();
                    property->name = propertynode->first_attribute( "name" )->value();
                    property->value = propertynode->first_attribute( "value" )->value();
                    
                    object->properties.push_back( property );
                    
                    propertynode = propertynode->next_sibling( "property" );
                }
            }
            
            group->objects.push_back( object );
            
            objectnode = objectnode->next_sibling( "object" );
        }
        
        map->groups.push_back( group );
        
        objectgroupnode = objectgroupnode->next_sibling( "objectgroup" );
    }
    
    free( (void*) xml );
    
    return map;
}
