//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#ifndef MINESWEEPER_SFML_BOARD_H
#define MINESWEEPER_SFML_BOARD_H
#include <random>

#include "Cell.h"
#include "SFML/Graphics.hpp"

namespace Gameplay {
    class Board {


        const float board_width_ = 866.f;
        const float board_height_ = 1080.f;
        const float board_position_ = 530.f;
        static constexpr int number_of_rows = 9;
        static constexpr int number_of_columns = 9;
        const float horizontal_cell_padding_ = 115.f;
        const float vertical_cell_padding_ = 329.f;
        std::default_random_engine generator_;
        std::random_device random_device_;

        sf::Texture texture_;
        sf::Sprite sprite_;
        Cell* cellGrid_[number_of_rows][number_of_columns]{};
        static constexpr int mines_count = 9;





        void initializeBoardImage(const sf::RenderWindow* window);
        void initialize(sf::RenderWindow* window);
        float getCellWidth() const;
        float getCellHeight() const;
        void createBoard();
        void populateBoard();
        void populateMines();

    public:
        explicit Board(sf::RenderWindow* window);
        void render(sf::RenderWindow &window) const;
    };
} // Gameplay

#endif //MINESWEEPER_SFML_BOARD_H