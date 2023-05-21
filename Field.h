//
// Created by Javier on 09/05/2023.
//


#ifndef MINESWEEPER_FIELD_H
#define MINESWEEPER_FIELD_H

#include <vector>
#include "Cell.h"
#include "UI.h"

class Field {
    int sizeX, sizeY, nMines, cellSize;
    bool isInitialized;
    bool isOver;
    std::vector<std::vector<Cell>> cells;
    UI* ui;



public:
    Field(int sizeX, int sizeY, int nMines, int cellSize, sf::Texture &texture, UI &ui);
    void render(sf::RenderWindow &window);
    void click(int x, int y, bool setFlag);
    bool gameOver();
};


#endif //MINESWEEPER_FIELD_H
