#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
public:
    Snake();
    void update();
    void render(sf::RenderWindow& window);
    void grow();
    bool checkCollision(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;

private:
    std::vector<sf::RectangleShape> body;
    sf::Vector2f direction;
    float speed;
};

#endif