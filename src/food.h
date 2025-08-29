#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>

class Food {
public:
    Food();
    void respawn();
    void render(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;

private:
    sf::CircleShape shape;
};

#endif