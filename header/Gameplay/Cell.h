//
// Created by Raghuvansh Agarwal on 10/10/25.
//

#ifndef MINESWEEPER_SFML_CELL_H
#define MINESWEEPER_SFML_CELL_H
#include "../UI/UIElements/Button/Button.h"
#include "SFML/Graphics.hpp"

namespace Gameplay {
    class Cell {
        sf::Vector2i position_;
        const int tile_size_ = 128;
        const int slice_count_ = 12;
        UIElements::Button* button_;

        void initialize(float p_width,float p_height, sf::Vector2i p_position);
        public:
        Cell(float p_width,float p_height, sf::Vector2i p_position);
        ~Cell();

        void render(sf::RenderWindow& window) const;
    };
} // Gameplay

#endif //MINESWEEPER_SFML_CELL_H