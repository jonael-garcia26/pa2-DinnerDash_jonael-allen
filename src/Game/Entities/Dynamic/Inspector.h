#pragma once

#include "Client.h"

class Inspector : public Client{
    public:
        Inspector(int, int, int, int, ofImage, Burger*, int*);
        void tick();
        bool isInsp(){return true;}
        int *money;
};