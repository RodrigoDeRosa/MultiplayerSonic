#pragma once
#include "Sprite.h"
#include <vector>

using namespace std;

class SpriteGroup
{
	vector <Sprite*> sprites; //vector de punteros a Sprite
	int sprites_size;
public:
	SpriteGroup();
	void add(Sprite * sprite);
	void remove(Sprite sprite);
	void update();
	void draw(SDL_Surface * sup);
	void empty();
	bool has(Sprite sprite);
	SpriteGroup copy();
};

