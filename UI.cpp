//
// Created by Javier on 13/05/2023.
//

#include "UI.h"

using namespace sf;

UI::UI(const Font& font, int nMines, RenderWindow& window) {
    this->font = font;

    auto wSize = window.getSize();

    counter = Counter(nMines,
                      Vector2f(wSize.x/2.f - wSize.x/3.f,wSize.y/2.f),
                      Vector2f(25*3+5*2,40), font);

    timer = Timer(Vector2f(wSize.x/2.f ,wSize.y/2.f),
                  Vector2f(25*4+5*3,40), font);
}

void UI::render(RenderWindow& window) {
    counter.render(window);
    timer.render(window);
}

Counter *UI::getCounter() {
    return &counter;
}

Timer *UI::getTimer(){
    return &timer;
}
