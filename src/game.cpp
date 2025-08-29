#include "game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Snake Game"), snake(), food() {
    window.setFramerateLimit(60);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update() {
    snake.update();
    if (snake.checkCollision(food.getPosition())) {
        snake.grow();
        food.respawn();
    }
}

void Game::render() {
    window.clear();
    snake.render(window);
    food.render(window);
    window.display();
}