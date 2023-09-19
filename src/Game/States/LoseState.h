#pragma once

#include "State.h"

class LoseState : public State {
private:
    ofImage gameOverImg;

public:
    LoseState();
    void tick();
    void render();
    void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();

};