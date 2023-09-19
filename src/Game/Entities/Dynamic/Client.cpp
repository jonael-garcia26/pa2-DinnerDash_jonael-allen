#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    delete burger;
}
void Client::render(){

    //Clients will shift from red to yellow as there patience becomes lower
    
    if(normal){
        ofSetColor(255);
        burger->render();
        ofSetColor (255,255,255);
        sprite.draw(x, y, width, height);
    }
    
    if(red){
        ofSetColor(255);
        burger->render();
        ofSetColor (255,255,0);
        sprite.draw(x, y, width, height);
    }
    
    if(redder){
        ofSetColor(255);
        burger->render();
        ofSetColor (255,128,0);
        sprite.draw(x, y, width, height);
    }
    
    if(reddest){
        ofSetColor(255);
        burger->render();
        ofSetColor (255,0,0);
        sprite.draw(x, y, width, height);
    }

    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);

    if(patience > 1500){
        normal = true;
    }
    
    if(patience <= 1500){
        red = true;
    }
    
    if(patience <= 1000){
        redder = true;
    }

    if(patience <= 500){
        reddest = true;
    }

    if(patience == 0){
        isLeaving = true;
        lostClients++;  // cuando la paciencia acaba el contador aumenta
        Clientsleaving++;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){

    // Si el burger  del primer cliente es igual el cliente se puede ir, limpia la pantalla del burger del jugador y le entrega el burger al cliente
    // de lo contrario revisa si alguno de los clientes tiene el mismo burger que el jugador 
    // si no hay ningun cliente con el mismo burger ningun cliente se va y borra el burger del jugador

    if(this->burger->equals(*burger)){
        isLeaving = true;
        Clientsleaving++;
        burger->clear();
        return burger->getBurgerPrice(this->burger->getIngredients());
    }else if(nextClient != nullptr){
        return nextClient->serve(burger);
    }else{
        burger->clear();
        isLeaving = false;
        return 0;
    } 
}

int Client::lostClients = 0; // definicion de la variable
int Client::Clientsleaving = 0; // define contador de cuandos clientes salen del local