#include "snake.h"
#include <iostream>

Snake::Snake() {
    blockSize = 20.f;
    moveDelay = 0.15f;
    direction = {blockSize, 0.f};

    sf::RectangleShape head(sf::Vector2f(blockSize, blockSize));
    head.setFillColor(sf::Color::Green);
    head.setPosition(200, 200);
    body.push_back(head);
}

void Snake::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && direction.y == 0)
        direction = {0.f, -blockSize};
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && direction.y == 0)
        direction = {0.f, blockSize};
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && direction.x == 0)
        direction = {-blockSize, 0.f};
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && direction.x == 0)
        direction = {blockSize, 0.f};
}

void Snake::update() {
    if (clock.getElapsedTime().asSeconds() < moveDelay) return;
    clock.restart();

    // Bouge le corps (du dernier morceau vers la tête)
    for (int i = body.size() - 1; i > 0; --i) {
        body[i].setPosition(body[i-1].getPosition());
    }

    // Bouge la tête
    body[0].move(direction);
}

void Snake::render(sf::RenderWindow& window) {
    for (auto& segment : body)
        window.draw(segment);
}

void Snake::grow() {
    sf::RectangleShape newPart(sf::Vector2f(blockSize, blockSize));
    newPart.setFillColor(sf::Color::Yellow);
    newPart.setPosition(body.back().getPosition());
    body.push_back(newPart);
}

bool Snake::checkCollision(const sf::Vector2f& position) const {
    for (auto& segment : body) {
        if (segment.getPosition() == position)
            return true;
    }
    return false;
}

bool Snake::checkSelfCollision() const {
    for (size_t i = 1; i < body.size(); i++) {
        if (body[0].getPosition() == body[i].getPosition())
            return true;
    }
    return false;
}

sf::Vector2f Snake::getHeadPosition() const {
    return body[0].getPosition();
}
