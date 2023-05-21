//
// Created by Javier on 09/05/2023.
//
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

#include "Cell.h"

using namespace sf;
using namespace std;

Cell::Cell() = default;

Cell::Cell(int size, int x, int y, Texture &texture, Counter &counter) {
    this->size = size;
    this->x = x;
    this->y = y;
    this->minesAround = 0;
    this->isMineVar = false;
    this->isFlaggedVar = false;
    this->isDiscovered = false;
    this->counter = &counter;

    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0,0,16,16));
    sprite.setPosition(x*size,y*size);
    float scaleFactor = (1/(float)16)*(float)size;
    sprite.setScale(Vector2f(scaleFactor,scaleFactor));
    setSprite();


}

void Cell::setMine() {
    this->isMineVar = true;
}

bool Cell::isMine() const {
    return isMineVar;
}
bool Cell::isFlagged() const{
    return isFlaggedVar;
}

void Cell::switchFlag(){
    if(isDiscovered) return;
    isFlaggedVar = !isFlaggedVar;
    setSprite();
    counter->incrementValue(isFlaggedVar? -1:1);
}

void Cell::countMinesAround(vector<vector<Cell>> &cells) {
    unsigned int sizeX = cells.size();
    unsigned int sizeY = cells[0].size();

    for(int xN = x-1; xN <= x+1; xN++){
        for(int yN = y-1; yN <= y+1; yN++) {
            if(xN < 0 || yN < 0 || xN >= sizeX || yN >= sizeY || (xN == x && yN == y)){
                continue;
            }


            neighbours.push_back(&cells[xN][yN]);

            if(cells[xN][yN].isMine())
                minesAround++;
        }
    }
}

void Cell::setSprite() {
    if(isFlagged()){
        sprite.setTextureRect(IntRect(12*16, 0, 16, 16));
        return;
    }

    if(!isDiscovered){
        sprite.setTextureRect(IntRect(0,0,16,16));
        return;
    }

    if(isMine()){
        sprite.setTextureRect(IntRect(11*16,0,16,16));
        return;
    }

    if(minesAround == 0){
        sprite.setTextureRect(IntRect(9*16, 0, 16, 16));
        return;
    }
    sprite.setTextureRect(IntRect(minesAround*16, 0, 16, 16));
}

bool Cell::discover() {
    if(isDiscovered || isFlagged()) return false;
    isDiscovered = true;
    setSprite();
    if(isMine()) {
        return true;
    }
    if(minesAround > 0) {
        return false;
    }

    for(auto &neighbour : neighbours){
        neighbour->discover();
    }

    return false;
}

void Cell::render(RenderWindow &window) {
    window.draw(sprite);
}



