#include "food.h"
#include <cstdlib>
#include <ctime>

Food::Food() {
    shape.setRadius(10);
    shape.setFillColor(sf::Color::Red);
    respawn();
}

void Food::respawn() {
    float x = static_cast<float>(rand() % 800);
    float y = static_cast<float>(rand() % 600);
    shape.setPosition(x, y);
}

void Food::render(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::Vector2f Food::getPosition() const {
    return shape.getPosition();
}