//
// Created by Raghuvansh Agarwal on 08/10/25.
//
#include "../../header/Gameplay/Board.h"

#include <iostream>

#include "../../header/Gameplay/Cell.h"
#include "../../header/Assets/AssetManager.h"
#include "../../header/Gameplay/GameplayManager.h"
#include "../../header/Sound/SoundManager.h"
#include "../../header/UI/UIElements/Button/Button.h"

namespace Gameplay {
    void Board::initializeBoardImage(const sf::RenderWindow *window) {
        if (!texture_.loadFromFile(Asset::AssetManager::getTexture(Asset::TextureType::Board))) {
            throw std::runtime_error("Failed to load board image!");
        }
        sprite_.setTexture(texture_);
        sprite_.setPosition(board_position_, 0);
        sprite_.setScale(board_width_ / texture_.getSize().x, board_height_ / texture_.getSize().y);
    }

    void Board::initialize(sf::RenderWindow *window, GameplayManager* gameplay_manager) {
        generator_.seed(random_device_());
        gameplay_manager_ = gameplay_manager;
        board_state_ = BoardState::FirstCell;
        flaggedCells = 0;
        createBoard();
    }

    float Board::getCellWidth() const {
        return (board_width_ - horizontal_cell_padding_) / number_of_columns;
    }

    float Board::getCellHeight() const {
        return (board_height_ - vertical_cell_padding_) / number_of_rows;
    }

    void Board::createBoard() {
        const float cell_width = getCellWidth();
        const float cell_height = getCellHeight();

        for (int i = 0; i < number_of_rows; i++) {
            for (int j = 0; j < number_of_columns; j++) {
                cellGrid_[i][j] = new Cell(cell_width, cell_height, sf::Vector2i(i, j), this);
            }
        }
    }

    void Board::populateBoard(sf::Vector2i p_first_cell_position) {
        populateMines(p_first_cell_position);
        populateCells();
    }

    void Board::populateMines(sf::Vector2i p_first_cell_position) {
        int mines = 0;
        std::uniform_int_distribution x_dis (0, number_of_rows - 1);
        std::uniform_int_distribution y_dis (0, number_of_columns - 1);
        while (mines < mines_count) {
            const int x = x_dis(generator_);
            const int y = y_dis(generator_);
            if (cellGrid_[x][y]->getType() == CellType::Mine || (p_first_cell_position.x == x && p_first_cell_position.y == y)) continue;
            cellGrid_[x][y]->setType(CellType::Mine);
            mines++;
        }
    }

    int Board::countMinesAround(sf::Vector2i p_cell_position) {
        int mines = 0;
        const int start_x = p_cell_position.x - 1;
        const int start_y = p_cell_position.y - 1;
        for (int i = start_x; i <= start_x + 2; i++) {
            for (int j = start_y; j <= start_y + 2; j++) {
                if (p_cell_position.x == j && p_cell_position.y == i) continue;
                if (isValidCellPosition({i,j})) {
                    if (cellGrid_[i][j]->getType() == CellType::Mine) {
                        mines++;
                    }
                }
            }
        }
        return mines;
    }

    void Board::populateCells() {
        for (int i = 0; i < number_of_rows; i++) {
            for (int j = 0; j < number_of_columns; j++) {
                if (cellGrid_[i][j]->getType() == CellType::Mine) continue;
                int mines = countMinesAround(sf::Vector2i(i, j));
                cellGrid_[i][j]->setType(static_cast<CellType>(mines));
            }
        }
    }

    bool Board::isValidCellPosition(sf::Vector2i p_cell_position) {
        return p_cell_position.x >= 0 && p_cell_position.x < number_of_columns && p_cell_position.y >= 0 && p_cell_position.y < number_of_rows;
    }


    BoardState Board::getBoardState() const {
        return board_state_;
    }

    bool Board::areAllCellsOpen() const {
        int total_valid_cells = (number_of_columns * number_of_rows) - mines_count;
        int open_cells = 0;
        for (const auto & i : cellGrid_) {
            for (const auto j : i) {
                if (j->getState() == CellState::Opened && j->getType() != CellType::Mine) {
                    open_cells++;
                }
            }
        }
        return open_cells == total_valid_cells;
    }

    int Board::getFlagCount() const {
        return flaggedCells;
    }

    void Board::flagAllMines() {
        for (const auto & i : cellGrid_) {
            for (auto j : i) {
                if (j->getType() == CellType::Mine && j->getState() != CellState::Flagged) {
                    j->setState(CellState::Flagged);
                }
            }
        }
    }

    void Board::reset() {
        flaggedCells = 0;
        setBoardState(BoardState::FirstCell);
        for (const auto & cellRow : cellGrid_) {
            for (auto cell : cellRow) {
                cell->reset();
            }
        }
    }

    void Board::setBoardState(BoardState p_boardState) {
        board_state_ = p_boardState;
    }

    Board::Board(sf::RenderWindow *window, GameplayManager* gameplay_manager) {
        initializeBoardImage(window);
        initialize(window, gameplay_manager);
    }

    void Board::openCell(sf::Vector2i p_cell_position) {
        if (Cell* cell = cellGrid_[p_cell_position.x][p_cell_position.y]; !cell->canOpen()) {
            return;
        }
        if (board_state_ == BoardState::FirstCell) {
            populateBoard(p_cell_position);
            board_state_ = BoardState::Playing;
        }
        processCellType(p_cell_position);
    }

    void Board::toggleFlag(sf::Vector2i p_cell_position) {
        if (isValidCellPosition(p_cell_position)) {
            if (Cell* cell = cellGrid_[p_cell_position.x][p_cell_position.y]; cell->canFlag()) {
                cell->toggleFlag();
                flaggedCells += (cell->getState() == CellState::Flagged ? 1 : -1);
            }
        }
    }

    void Board::processEmtpyCell(sf::Vector2i p_cell_position) {
        // Handle the clicked cell
        switch (CellState cell_state = cellGrid_[p_cell_position.x][p_cell_position.y]->getState()) {
            case CellState::Opened:
                return;  // Already open, stop here
            default:
                cellGrid_[p_cell_position.x][p_cell_position.y]->open();
        }
        for (int a = -1; a <= 1; ++a) {
            for (int b = -1; b <= 1; ++b) {
                //Store neighbor cells position
                sf::Vector2i next_cell_position = sf::Vector2i(a + p_cell_position.x, b + p_cell_position.y);
                if ((a== 0 && b == 0) || !isValidCellPosition(next_cell_position)) continue;
                if (cellGrid_[next_cell_position.x][next_cell_position.y]->getState() == CellState::Flagged) {
                    toggleFlag(next_cell_position);
                }
                //Open neighbor cell
                openCell(next_cell_position);  // Open neighbor
            }
        }
    }

    void Board::processMineCell(sf::Vector2i p_cell_position) const {
        gameplay_manager_->setGameEnded(GameResult::LOST);
    }

    void Board::processCellType(sf::Vector2i p_cell_position) {
        switch (cellGrid_[p_cell_position.x][p_cell_position.y]->getType()) {
            case CellType::Empty:
                processEmtpyCell(p_cell_position);
                break;
            case CellType::Mine:
                break;
            default:
                cellGrid_[p_cell_position.x][p_cell_position.y]->open();
                break;
        }
    }

    void Board::onCellButtonClick(sf::Vector2i p_cell_position, UIElements::MouseButtonType p_type) {
        if (p_type == UIElements::MouseButtonType::LeftMouseButton) {
            Sound::SoundManager::PlaySound(Sound::SoundType::BUTTON_CLICK);
            if (cellGrid_[p_cell_position.x][p_cell_position.y]->getType() == CellType::Mine) {
                processMineCell(p_cell_position);
            }else {
                openCell(p_cell_position);
            }
        }
        else if (p_type == UIElements::MouseButtonType::RightMouseButton) {
            Sound::SoundManager::PlaySound(Sound::SoundType::FLAG);
            toggleFlag(p_cell_position);
        }
    }

    void Board::revealAllCells() {
        for (int i = 0; i < number_of_rows; i++) {
            for (int j = 0; j < number_of_columns; j++) {
                cellGrid_[i][j]->setState(CellState::Opened);
            }
        }
    }

    void Board::update(Event::EventPollingManager &event_manager, const sf::RenderWindow& window) {
        for (const auto & i : cellGrid_) {
            for (const auto j : i) {
                j->update(event_manager, window);
            }
        }
    }


    void Board::render(sf::RenderWindow &window) const {
        window.draw(sprite_);
        for (const auto & i : cellGrid_) {
            for (const auto j : i) {
                j->render(window);
            }
        }
    }
} // Gameplay
