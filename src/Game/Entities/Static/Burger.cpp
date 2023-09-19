//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}

void Burger::clear(){
    ingredients.clear();
}

//burger equals method

bool Burger::equals(const Burger& otherBurger) const {

    bool isEqual = false;

    if (ingredients.size() != otherBurger.ingredients.size()) {
        return isEqual;
    }

    for(unsigned int i = 0; i < ingredients.size(); i++){
        if(ingredients[i]->name == otherBurger.ingredients[i]->name){
            isEqual = true;
        }else{
            return false;
        }
    }
    return isEqual;
}

void Burger::undo(Item *item) {
    if (!ingredients.empty()) {
        ingredients.pop_back();
    }
}

int Burger::getBurgerPrice(vector<Item *> ingredients) const {

    int cheeseCount = 0;
    int lettuceCount = 0;
    int tomatoCount = 0;
    int pattyCount = 0;

    for(auto* ingredient : ingredients){
        if (ingredient->name == "cheese"){
            ++cheeseCount;
        } else if(ingredient->name == "lettuce"){
            ++lettuceCount;
        } else if(ingredient->name == "tomato"){
            ++tomatoCount;
        } else if(ingredient->name == "patty"){
            ++pattyCount;
        }
    }
    int burgerPrice = 3 * cheeseCount + 2 * lettuceCount + 2 * tomatoCount + 4 * pattyCount + 2;
    return burgerPrice;
}
