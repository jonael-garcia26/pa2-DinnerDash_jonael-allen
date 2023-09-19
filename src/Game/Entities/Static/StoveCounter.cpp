#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item* raw, Item* cooked, ofImage image, ofImage activeimage) : BaseCounter(x,y,width,height,raw,image),

cookedItem(cookedItem), rawItem(rawItem), image(image), activeimage(activeimage) {}

Item* StoveCounter::getItem(){

if(!isCooked){
    return nullptr;
}

reset();
return cookedItem;

}

void StoveCounter::interact(){
    if(isCooking) return;
    isCooking = true;
    setSprite(activeimage);
}

void StoveCounter::tick(){
    ticks++;
    if(isCooking && ticks % tickstocook){
        cookingtimer++;
    }

    if(isCooking && progress == 100){
        setItem(cookedItem);
        setSprite(image);
        isCooking = false;
        isCooked = true;
    }
}

void StoveCounter::render(){
    Entity::render();

    ofSetColor(100);
    ofDrawRectRounded(x,y+height-progress*2, width, progress,1);

    ofSetColor(isCooked? done : notdone);
    ofDrawRectRounded(x,y+height-progress*2, width/100 * cookingtimer, progress, 1);
}

void StoveCounter::reset(){
    cookingtimer = 0;
    setItem(rawItem);
    setSprite(sprite);
    isCooking = false;
    isCooked = false;
}