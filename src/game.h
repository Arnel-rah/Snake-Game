#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    Snake snake;
    Food food;
};

#endif