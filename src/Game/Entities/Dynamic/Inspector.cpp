#include "Inspector.h"

Inspector::Inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger, int *money) 
    : Client(x, y, width, height, sprite, burger){
        this->money = money;
    }

void Inspector::tick(){
    Client::tick();
    if(isLeaving && patience <= 0){
        if (*money < 0){
            *money = *money;
        } else {
            *money = *money / 2;
        }
    }
}