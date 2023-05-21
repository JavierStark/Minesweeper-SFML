//
// Created by Javier on 13/05/2023.
//

#ifndef MINESWEEPER_COUNTER_H
#define MINESWEEPER_COUNTER_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <string>


class Counter {
    int value;
    sf::Vector2f position;
    sf::Vector2f size;
protected:
    sf::RectangleShape bg;
    sf::Text text;
public:
    Counter();
    Counter(int value, sf::Vector2f position, sf::Vector2f size, const sf::Font& font);

    int getValue();
    void incrementValue(int increment);
    void render(sf::RenderWindow &window);
};


#endif //MINESWEEPER_COUNTER_H
