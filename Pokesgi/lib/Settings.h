//
//  Settings.h
//  Pokesgi
//
//  Created by Thibault Lenclos on 24/05/13.
//  From https://github.com/LaurentGomila/SFML/wiki/Source%3A-Settings-Parser
//

#ifndef __Pokesgi__Settings__
#define __Pokesgi__Settings__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>

class Settings
{
protected:
	bool isChanged;
	std :: string filename;
	std :: vector < std :: pair < std :: string, std :: string> > data;
	size_t size, max_width;
public:
	Settings(std :: string file);
	Settings(std :: string file, size_t width);
	~Settings();
    
	void Read();
	void Write();
    
	bool IsChanged();
    
	void Get(std :: string param, std :: string* value);
	void Get(std :: string param, bool* value);
	void Get(std :: string param, char* value);
	void Get(std :: string param, int* value);
	void Get(std :: string param, float* value);
    
	void Set(std :: string param, std :: string value);
	void Set(std :: string param, bool value);
	void Set(std :: string param, char value);
	void Set(std :: string param, int value);
	void Set(std :: string param, float value);
};

#endif /* defined(__Pokesgi__Settings__) */
