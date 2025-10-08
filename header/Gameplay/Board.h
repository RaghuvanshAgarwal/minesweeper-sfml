//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#ifndef MINESWEEPER_SFML_BOARD_H
#define MINESWEEPER_SFML_BOARD_H
#include "SFML/Graphics.hpp"

namespace Gameplay {
    class Board {
        sf::Texture texture_;
        sf::Sprite sprite_;

        void initializeBoardImage(const sf::RenderWindow* window);
        void initialize(sf::RenderWindow* window);

    public:
        Board(sf::RenderWindow* window);
        void render(sf::RenderWindow &window);
    };
} // Gameplay

#endif //MINESWEEPER_SFML_BOARD_H