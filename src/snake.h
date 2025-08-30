#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
public:
    Snake();
    void handleInput();                 // Gérer le clavier
    void update();                      // Mettre à jour la position
    void render(sf::RenderWindow& window);
    void grow();                        // Ajouter un morceau au corps
    bool checkCollision(const sf::Vector2f& position) const;
    bool checkSelfCollision() const;    // Vérifie si le serpent se mord
    sf::Vector2f getHeadPosition() const;

private:
    std::vector<sf::RectangleShape> body;
    sf::Vector2f direction;
    float blockSize;
    sf::Clock clock;
    float moveDelay;
};

#endif
