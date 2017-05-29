#include "Pez.hpp"
#include "../Player.hpp"
#include <stdio.h>
#define WIDTH 50
#define HEIGHT 100


#define FISH_MOV_SPAN 200		//cuantas veces se mueve para un lado
#define FISH_MOV_SPEED 0.3		//cuanto se mueve por vez

using namespace std;

Pez::Pez(int id, float x, float y) : Entidad(id,x,y,WIDTH,HEIGHT){}

void Pez::afectarA(Player* jugador){
	if(jugador->estaAtacando()){
		this->destruida = true;
		//sumar puntos a jugador
	}
	else jugador->recibirGolpe();
}

out_message_t* Pez::getOutMessage(){
	return this->Entidad::getOutMessage(FISH_UPDATE);
}

out_message_t* Pez::getInitMessage(){
	return this->Entidad::getOutMessage(FISH_SET);
}

void Pez::mover(){//draft, faltan frames
	if (contador_mov > FISH_MOV_SPAN){
		contador_mov = 0;
		direccion = (-1)*direccion;
	}
	contador_mov++;
	y+= direccion*FISH_MOV_SPEED;
} 