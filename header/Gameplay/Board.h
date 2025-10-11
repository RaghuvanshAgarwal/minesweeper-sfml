//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#ifndef MINESWEEPER_SFML_BOARD_H
#define MINESWEEPER_SFML_BOARD_H
#include <random>
#include "SFML/Graphics.hpp"

namespace Event {
    class EventPollingManager;
}

namespace UIElements {
    enum class MouseButtonType;
}

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
        class Cell* cellGrid_[number_of_rows][number_of_columns]{};
        static constexpr int mines_count = 9;
        int flaggedCells;





        void initializeBoardImage(const sf::RenderWindow* window);
        void initialize(sf::RenderWindow* window);
        float getCellWidth() const;
        float getCellHeight() const;
        void createBoard();
        void populateBoard();
        void populateMines();
        int countMinesAround(sf::Vector2i p_cell_position);
        void populateCells();
        bool isValidCellPosition(sf::Vector2i p_cell_position);

    public:
        Board(sf::RenderWindow* window);

        void openCell(sf::Vector2i p_cell_position);

        void toggleFlag(sf::Vector2i p_cell_position);

        void onCellButtonClick(sf::Vector2i p_cell_position, UIElements::MouseButtonType p_type);
        void update(Event::EventPollingManager &event_manager, const sf::RenderWindow& window);
        void render(sf::RenderWindow &window) const;
    };
} // Gameplay

#endif //MINESWEEPER_SFML_BOARD_H