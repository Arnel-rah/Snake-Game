#include "snake.h"

Snake::Snake() {
    speed = 100.0f;
    direction = sf::Vector2f(1, 0);
    sf::RectangleShape segment(sf::Vector2f(20, 20));
    segment.setFillColor(sf::Color::Green);
    segment.setPosition(400, 300);
    body.push_back(segment);
}

void Snake::update() {
    for (size_t i = body.size() - 1; i > 0; --i) {
        body[i].setPosition(body[i - 1].getPosition());
    }
    body[0].move(direction * speed * 0.016f);
}

void Snake::render(sf::RenderWindow& window) {
    for (const auto& segment : body) {
        window.draw(segment);
    }
}

void Snake::grow() {
    sf::RectangleShape newSegment(sf::Vector2f(20, 20));
    newSegment.setFillColor(sf::Color::Green);
    newSegment.setPosition(body.back().getPosition());
    body.push_back(newSegment);
}

bool Snake::checkCollision(const sf::Vector2f& position) {
    return body[0].getGlobalBounds().contains(position);
}

sf::Vector2f Snake::getPosition() const {
    return body[0].getPosition();
}