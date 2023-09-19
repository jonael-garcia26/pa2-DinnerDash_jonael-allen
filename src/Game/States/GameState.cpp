#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();
	if (Client::lostClients >= 10){		// Cuando 10 clientes se van activa el LoseState
		setNextState("Lose");
		setFinished(true);
	} else if (Restaurant::moneyCount >= 100){		// Cuando el dinero llega a 100 se activa el WinState
		setNextState("Win");
		setFinished(true);
	}
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
	Client::lostClients = 0; // reinicia el counter de los clientes cuando el juego acaba
	Restaurant::moneyCount = 0; // reinicia el dinero cuando acaba el juego
}