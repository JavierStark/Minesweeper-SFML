//
// Created by Javier on 13/05/2023.
//

#ifndef MINESWEEPER_UI_H
#define MINESWEEPER_UI_H


#include <SFML/Graphics.hpp>
#include "Counter.h"
#include "Timer.h"

class UI{
    sf::Font font;
    Counter counter;
    Timer timer;
public:
    UI(const sf::Font& font, int nMines, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    Counter* getCounter();
    Timer* getTimer();
};


#endif //MINESWEEPER_UI_H
