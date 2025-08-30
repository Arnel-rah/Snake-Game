#include <SFML/Graphics.hpp>
#include "snake.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 400), "Snake Game - SFML 2.6.2");

    Snake snake;

    sf::RectangleShape food(sf::Vector2f(20, 20));
    food.setFillColor(sf::Color::Red);
    food.setPosition(300, 200);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        snake.handleInput();
        snake.update();
        if (snake.getHeadPosition() == food.getPosition()) {
            snake.grow();
            food.setPosition(
                (rand() % 30) * 20,
                (rand() % 20) * 20
            );
        }

        // Collision avec soi-même
        if (snake.checkSelfCollision()) {
            window.close(); // tu peux mettre un écran "Game Over"
        }

        window.clear();
        snake.render(window);
        window.draw(food);
        window.display();
    }

    return 0;
}
