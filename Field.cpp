//
// Created by Javier on 09/05/2023.
//

#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

#include "Field.h"

using namespace std;

Field::Field(int sizeX, int sizeY, int nMines, int cellSize, sf::Texture &texture,  UI &ui) {
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->nMines = nMines;
    this->cellSize = cellSize;
    this->isInitialized = false;
    this->isOver = false;
    this->ui = & ui;


    cells = vector<vector<Cell>>(sizeX, vector<Cell>(sizeY));

    for(int x = 0; x < sizeX; x++){
        for(int y = 0; y < sizeY; y++){
            cells[x][y] = Cell(cellSize, x, y, texture, *ui.getCounter());
        }
    }


    int max = sizeX * sizeY;

    //random
    mt19937 gen(time(NULL));
    uniform_int_distribution<> distrib(0, max);

    cout << max << endl;
    vector<int> minesPos(nMines);
    for (auto &pos: minesPos) {
        int randomPos = -1;
        while (randomPos == -1 || count(minesPos.begin(), minesPos.end(), randomPos) > 0) {
            randomPos = distrib(gen);
        }
        pos = randomPos;

        int yPos = ceil(pos/sizeX);
        int xPos = pos%sizeX;

        cells[xPos][yPos].setMine();
    }

    for(int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
             cells[x][y].countMinesAround(cells);
        }
    }

}

void Field::render(sf::RenderWindow &window) {
    for(auto &column : cells){
        for(auto &cell: column){
            cell.render(window);
        }
    }
}

void Field::click(int x, int y, bool setFlag) {
    if(setFlag)
        cells[x][y].switchFlag();
    else
        if(cells[x][y].discover()){
            isOver = true;
        }
}

bool Field::gameOver(){
    return isOver;
}
