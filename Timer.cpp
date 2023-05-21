//
// Created by Javier on 18/05/2023.
//

#include "Timer.h"

using namespace sf;

Timer::Timer() = default;
Timer::Timer(Vector2f position, Vector2f size, const Font& font) : Counter(0, position, size, font){
    isStop = false;
}

void Timer::stop(){
    isStop = true;
}
void Timer::reset(){
    clock.restart();
    isStop = false;
}

void Timer::render(RenderWindow &window) {
    if(!isStop){
        text.setString(std::to_string((int) clock.getElapsedTime().asSeconds()));
    }
    window.draw(bg);
    window.draw(text);
}

