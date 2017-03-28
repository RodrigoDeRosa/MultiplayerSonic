#include "Stage.hpp"
#include "Layer.hpp"
#include "SpriteGroup.hpp"

Stage::Stage(){
    sprites = NULL;
    front = NULL;
    background = NULL;
    width=0;
    height=0;
}

Stage::~Stage(){
    if (front){
        delete front;
        front = NULL;
    }
    if (background){
        delete background;
        background = NULL;
    }
    if(sprites){
        delete sprites;
        sprites = NULL;
    }
}

void Stage::setDimensiones(int w, int h){
    width = w;
    height = h;
}

int Stage::getWidth(){
    return width;
}

int Stage::getHeight(){
    return height;
}

void Stage::addLayer(Layer* layer){
    /*Si ya se tienen ambas capas no se pueden agregar mas*/
    if (front && background){
        printf("ERROR: Stage already has two layers!\n");
        return;
    }
    /*Si no habia ninguna capa se define la de adelante*/
    if (!front){
        front = layer;
    }else{
        /*Si habia una capa se verifica cual de las dos es la del frente.*/
        if (layer <= front){
            background = layer;
        } else{
            background = front;
            front = layer;
        }
    }
}

void Stage::render(camara* camara){
    if(front) front->render(camara);
    if(background) background->render(camara);
    if(sprites) sprites->render();
}

/*void Stage::render(){
    if(front) front->render();
    if(background) background->render();
    if(sprites) sprites->render();
}*/

void Stage::setSpriteGroup(SpriteGroup* group){
    sprites = group;
}

void Stage::addSprite(Sprite* sprite){
    sprites->add(sprite);
}

SpriteGroup* Stage::getSprites(){
    return sprites;
}