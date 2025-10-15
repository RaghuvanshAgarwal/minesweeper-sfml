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
    class GameplayManager;

    enum class BoardState {
        FirstCell,
        Playing,
        Completed,
    };

    class Board {
        static constexpr int number_of_rows = 9;
        static constexpr int number_of_columns = 9;
        static constexpr int mines_count = 9;


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
        GameplayManager* gameplay_manager_ = nullptr;

        BoardState board_state_ = BoardState::FirstCell;
        int flaggedCells{};

        float getCellWidth() const;
        float getCellHeight() const;
        int countMinesAround(sf::Vector2i p_cell_position);
        bool isValidCellPosition(sf::Vector2i p_cell_position);


        void initializeBoardImage(const sf::RenderWindow* window);
        void createBoard();
        void populateBoard(sf::Vector2i p_first_cell_position);
        void populateMines(sf::Vector2i p_first_cell_position);
        void populateCells();

        void openCell(sf::Vector2i p_cell_position);
        void toggleFlag(sf::Vector2i p_cell_position);
        void processEmtpyCell(sf::Vector2i p_cell_position);
        void processMineCell(sf::Vector2i p_cell_position) const;
        void processCellType(sf::Vector2i p_cell_position);

    public:
        explicit Board(sf::RenderWindow* window, GameplayManager* gameplay_manager);


        BoardState getBoardState() const;
        bool areAllCellsOpen() const;
        int getFlagCount() const;

        void initialize(sf::RenderWindow* window, GameplayManager* gameplay_manager);
        void setBoardState(BoardState p_boardState);
        void onCellButtonClick(sf::Vector2i p_cell_position, UIElements::MouseButtonType p_type);
        void revealAllCells();
        void flagAllMines();
        void reset();
        void update(Event::EventPollingManager &event_manager, const sf::RenderWindow& window);
        void render(sf::RenderWindow &window) const;
    };
} // Gameplay

#endif //MINESWEEPER_SFML_BOARD_H