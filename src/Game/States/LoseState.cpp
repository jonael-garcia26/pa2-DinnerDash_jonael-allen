#include "LoseState.h"
#include "MenuState.h"

LoseState::LoseState(){

}

void LoseState::tick() {
    
}

void LoseState::render() {

    ofSetBackgroundColor(255,0,0);
    gameOverImg.load("images/GameOver.png");
    gameOverImg.draw(0,0, ofGetWidth(), ofGetHeight());        // Game Over image

    ofSetColor(255);
    ofDrawBitmapString("Press ENTER to return to the main menu.", ofGetWidth() / 2 - 130, ofGetHeight() / 2);
}

void LoseState::keyPressed(int key){
    
    if (key == OF_KEY_RETURN){      // preciona ENTER para volver al menu
        setNextState("Menu");
        setFinished(true);
    }
	
}

void LoseState::mousePressed(int x, int y, int button){
}

void LoseState::reset(){
    setFinished(false);
    setNextState("");
}