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
        static constexpr int number_of_rows = 5;
        static constexpr int number_of_columns = 5;
        static constexpr int mines_count = 5;


        const float board_width_ = 866.f;
        const float board_height_ = 1080.f;
        const float board_position_ = 530.f;
        const float horizontal_cell_padding_ = 115.f;
        const float vertical_cell_padding_ = 329.f;


        std::default_random_engine generator_;
        std::random_device random_device_;
        sf::Texture texture_;
        sf::Sprite sprite_;
        class Cell* cellGrid_[number_of_rows][number_of_columns]{};
        class GameplayManager* gameplay_manager_ = nullptr;

        int flaggedCells;

        float getCellWidth() const;
        float getCellHeight() const;
        int countMinesAround(sf::Vector2i p_cell_position);
        bool isValidCellPosition(sf::Vector2i p_cell_position);

        void initialize(sf::RenderWindow* window, GameplayManager* gameplay_manager);
        void initializeBoardImage(const sf::RenderWindow* window);
        void createBoard();
        void populateBoard();
        void populateMines();
        void populateCells();

        void openCell(sf::Vector2i p_cell_position);
        void toggleFlag(sf::Vector2i p_cell_position);
        void processEmtpyCell(sf::Vector2i p_cell_position);
        void processMineCell(sf::Vector2i p_cell_position);
        void processCellType(sf::Vector2i p_cell_position);
    public:
        explicit Board(sf::RenderWindow* window, GameplayManager* gameplay_manager);
        void onCellButtonClick(sf::Vector2i p_cell_position, UIElements::MouseButtonType p_type);
        void revealAllCells();
        void update(Event::EventPollingManager &event_manager, const sf::RenderWindow& window);
        void render(sf::RenderWindow &window) const;
    };
} // Gameplay

#endif //MINESWEEPER_SFML_BOARD_H