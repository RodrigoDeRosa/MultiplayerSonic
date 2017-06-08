#include "Estado.hpp"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

Estado::Estado(){
	this->estado = NORMAL;
}

state_type Estado::get(){
	return this->estado;
}

void Estado::set(state_type estado){
	if(estado == INVENCIBLE) this->setInvencible();
	else this->estado = estado;
}

void* state_change(void* arg){
	Estado* estado = (Estado*)arg;
	sleep(10);
	if(estado->get() == INVENCIBLE) estado->set(NORMAL);
	return NULL;
}

void Estado::setInvencible(){
	this->estado = INVENCIBLE;
	pthread_t timeThreadID;
	void* timeThread_exit;
	pthread_create(&timeThreadID, NULL, state_change, this);
	//pthread_join(timeThreadID, &timeThread_exit);
}

void Estado::updateFrame(){
	this->frame++;
	if(this->frame >= 9) this->frame = 0;
}

int Estado::getFrame(){
	this->updateFrame();
	return this->frame;
}

bool Estado::recibirGolpe(){
	switch(this->estado){
		case INVENCIBLE:
			return false;
		case ESCUDO:
			this->set(NORMAL);
			return false;
		case NORMAL:
			return true;
	}
}