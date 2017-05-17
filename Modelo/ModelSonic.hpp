#ifndef TALLERSONIC_MODELSONIC_HPP
#define TALLERSONIC_MODELSONIC_HPP

#include "MoveSonic.hpp"
#include <iostream>

using namespace std;

class ModelSonic{
private:

    MoveSonic* bloque_pers;
    int frameRight, frameLeft;
    float direccionX, direccionY;

public:
    ModelSonic();
    void setMoveSonic(MoveSonic*);
    void moveRight(float);
    void moveLeft(float);
    void jump(float, float);
    int getFrame();
    move_type getMovement();
    float getX();
    float getY();
    float getDirX();
    float getDirY();
    void update(float,float,float,float);
};

#endif //TALLERSONIC_MODELSONIC_HPP