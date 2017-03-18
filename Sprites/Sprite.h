#include "SDL2/SDL.h"
#include <iostream>
#include "LTexture.h"

#ifndef SRC_SPRITE_H_
#define SRC_SPRITE_H_

class Sprite {
	LTexture* get_texture() const;
protected:
	LTexture texture;
	int origin_x, origin_y, width, height;
public:
	Sprite(Uint32 color, int x, int y);
	void update();
	void draw(SDL_Renderer * destination);
	void set_texture(LTexture* new_texture)
	bool operator==(const Sprite &other) const;
};

#endif
