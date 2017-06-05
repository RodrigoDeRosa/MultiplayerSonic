#include "BonusMoneda.hpp"
#include "../Player.hpp"
#include <stdio.h>
#define WIDTH 100
#define HEIGHT 120

using namespace std;

BonusMoneda::BonusMoneda(int id, float x, float y) : Entidad(id,x,y,WIDTH,HEIGHT){
	frame = 0;
}

void BonusMoneda::afectarA(Player* jugador){
	jugador->agregarMonedas(10);
	this->destruida = true;
}

out_message_t* BonusMoneda::getOutMessage(){
	out_message_t* state = this->Entidad::getOutMessage(BONUS_UPDATE);
	return state;
}

out_message_t* BonusMoneda::getInitMessage(){
	return this->Entidad::getOutMessage(BONUS_SET);
}

void BonusMoneda::mover(){}