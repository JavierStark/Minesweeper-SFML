//
// Created by Javier on 18/05/2023.
//

#ifndef MINESWEEPER_TIMER_H
#define MINESWEEPER_TIMER_H


#include "Counter.h"

class Timer : Counter{
    sf::Clock clock;
    bool isStop;
public:
    Timer();
    Timer(sf::Vector2f position, sf::Vector2f size, const sf::Font& font);
    void stop();
    void reset();
    void render(sf::RenderWindow &window);
};


#endif //MINESWEEPER_TIMER_H
