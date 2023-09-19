#include "WinState.h"
#include "MenuState.h"

WinState::WinState(){

}

void WinState::tick() {
    
}

void WinState::render() {

    ofSetBackgroundColor(0,0,255);
    youWinImg.load("images/YouWin.png");
    youWinImg.draw(0,0, ofGetWidth(), ofGetHeight());        // You Win image

    ofSetColor(255);
    ofDrawBitmapString("Press ENTER to return to the main menu.", ofGetWidth() / 2 - 135, ofGetHeight() / 2 - 200);
}

void WinState::keyPressed(int key){
    
    if (key == OF_KEY_RETURN){      // preciona ENTER para volver al menu
        setNextState("Menu");
        setFinished(true);
    }
	
}

void WinState::mousePressed(int x, int y, int button){
}

void WinState::reset(){
    setFinished(false);
    setNextState("");
}