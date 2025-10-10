//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#ifndef MINESWEEPER_SFML_BOARD_H
#define MINESWEEPER_SFML_BOARD_H
#include "Cell.h"
#include "SFML/Graphics.hpp"

namespace Gameplay {
    class Board {
        sf::Texture texture_;
        sf::Sprite sprite_;

        Cell* cell_;

        const float boardWidth = 866.f;
        const float boardHeight = 1080.f;
        const float boardPosition = 530.f;

        void initializeBoardImage(const sf::RenderWindow* window);
        void initialize(sf::RenderWindow* window);
        void createBoard();

    public:
        Board(sf::RenderWindow* window);
        void render(sf::RenderWindow &window) const;
    };
} // Gameplay

#endif //MINESWEEPER_SFML_BOARD_H