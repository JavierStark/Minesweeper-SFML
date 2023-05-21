//
// Created by Javier on 13/05/2023.
//

#include "Counter.h"

using namespace std;
using namespace sf;

Counter::Counter(int value, Vector2f position, Vector2f size, const Font& font) {
    this->value = value;
    this->position = position;
    this->size = size;

    bg = RectangleShape(size);
    bg.setOrigin(Vector2f(0, size.y/2.f));
    bg.setPosition(position);

    text.setFont(font);
    text.setCharacterSize(size.y);
    text.setFillColor(Color::Red);
    text.setOrigin(Vector2f(0, size.y/2.f));
    text.setPosition(position + Vector2f(0, size.y/2 + 5/2.f));


    text.setString(to_string(value));
}

Counter::Counter() = default;

int Counter::getValue() {
    return value;
}

void Counter::incrementValue(int increment) {
    value += increment;

    text.setString(to_string(value));
}

void Counter::render(sf::RenderWindow &window) {
    window.draw(bg);
    window.draw(text);
}
