#include "BaseCounter.h"

class StoveCounter : public BaseCounter {
    private:
        Item *cookedItem;
        Item *rawItem;
        int cookingtimer = 0;
        int tickstocook = 2;
        bool isCooking = false;
        bool isCooked = false;
        int progress = 10;
        ofColor done = ofColor(21,136,235);
        ofColor notdone = ofColor(255);
        ofImage activeimage;
        ofImage image;

    public:
        StoveCounter(int x, int y, int width, int height, Item* raw, Item* cooked, ofImage image, ofImage activeimage);
        Item* getItem();
        void interact();
        void render();
        void reset();
        void tick();

};