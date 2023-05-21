//
// Created by Javier on 09/05/2023.
//

#ifndef MINESWEEPER_CELL_H
#define MINESWEEPER_CELL_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Counter.h"


class Cell {
    int size, x, y, minesAround;
    bool isMineVar;
    bool isFlaggedVar;
    bool isDiscovered;
    std::vector<Cell*> neighbours;
    sf::Sprite sprite;
    Counter* counter;

public:
    Cell();
    Cell(int size, int x, int y, sf::Texture &texture, Counter &counter);
    void setMine();
    bool isMine() const;
    bool isFlagged() const;
    void switchFlag();
    void countMinesAround(std::vector<std::vector<Cell>> &cells);
    bool discover();
    void setSprite();
    void render(sf::RenderWindow & window);
};


#endif //MINESWEEPER_CELL_H
