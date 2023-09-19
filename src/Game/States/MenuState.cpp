#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");
	menuImg.load("images/MenuBurger.png");
	boxImg.load("images/TextBox.png");
	startImg.load("images/StartButton.png");

}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	ofSetBackgroundColor(102, 255, 102);
	ofSetColor(255);

	menuImg.draw(0, 0, ofGetWidth(), ofGetHeight());
	startButton->render();
	startImg.draw(ofGetWidth() / 2 - 110, ofGetHeight() / 2 - 100, startImg.getWidth() * 0.25, startImg.getHeight() * 0.25);
	boxImg.draw(5, ofGetHeight() - 240);

	ofSetColor(0);
	ofDrawBitmapString("Use E to pick up ingredients",45 ,ofGetHeight() - 150);
	ofDrawBitmapString("Use S to serve customers",45 ,ofGetHeight() - 130);
	ofDrawBitmapString("Use U to undo last ingredient",45 ,ofGetHeight() - 110);
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}