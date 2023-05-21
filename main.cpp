#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "Field.h"
#include "UI.h"

using namespace sf;
using namespace std;

#define FIELDX 16
#define FIELDY 16
#define NMINES 40
#define CELL 20

int main() {
    auto desktop = VideoMode::getDesktopMode();

    RenderWindow window(VideoMode(CELL*FIELDX, CELL*FIELDY), "Mine Sweeper", Style::None|Style::Close);
    window.setFramerateLimit(20);

    RenderWindow uiWindow(VideoMode(300, 100), "Mine Sweeper Score", Style::None|Style::Close);
    uiWindow.setFramerateLimit(20);
    uiWindow.setPosition(Vector2i(desktop.width / 2 - uiWindow.getSize().x / 2,
                                desktop.height/2 + uiWindow.getSize().y + CELL * FIELDY / 2));



    sf::Texture texture;
    if(!texture.loadFromFile("spritesheet.png")){
        cout << "Can't load texture" << endl;
    }
    sf::Font font;
    if (!font.loadFromFile("pixelFont.tff")) {
        cout << "Can't load font" << endl;
    }

    auto *ui = new UI(font, NMINES, uiWindow);
    auto *field = new Field(FIELDX, FIELDY, NMINES, CELL, texture, *ui);

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if(event.type == Event::MouseButtonPressed){
                sf::Vector2i localPosition = sf::Mouse::getPosition(window)/CELL;

                if(field->gameOver()) {
                    break;
                }

                if(event.mouseButton.button == Mouse::Button::Left){
                    field->click(floor(localPosition.x), floor(localPosition.y), false);
                }
                else if(event.mouseButton.button == Mouse::Button::Right){
                    field->click(floor(localPosition.x), floor(localPosition.y), true);
                }
            }
            if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Key::BackSpace){
                    field = new Field(FIELDX, FIELDY, NMINES, CELL, texture, *ui);
                    ui->getTimer()->reset();
                }
            }
        }

        if(field->gameOver()) {
            ui->getTimer()->stop();
        }

        window.clear(Color::Black);
        uiWindow.clear(Color::Black);

        // Rendering
        field->render(window);
        ui->render(uiWindow);

        window.display();
        uiWindow.display();
    }

    delete field;
    delete ui;
}

