//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#include "../../header/Gameplay/Board.h"

#include <iostream>

#include "../../header/Assets/AssetManager.h"

namespace Gameplay {
    void Board::initializeBoardImage(const sf::RenderWindow *window) {
        if (!texture_.loadFromFile(Asset::AssetManager::getTexture(Asset::TextureType::Board))) {
            throw std::runtime_error("Failed to load board image!");
        }
        sprite_.setTexture(texture_);
        sprite_.setPosition(board_position_, 0);
        sprite_.setScale(board_width_ / texture_.getSize().x, board_height_ / texture_.getSize().y);
    }

    void Board::initialize(sf::RenderWindow *window) {
        generator_.seed(random_device_());
        initializeBoardImage(window);
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
                cellGrid_[i][j] = new Cell(cell_width, cell_height, sf::Vector2i(i, j));
                cellGrid_[i][j]->setState(CellState::Opened);
            }
        }
        populateBoard();
    }

    void Board::populateBoard() {
        populateMines();
    }

    void Board::populateMines() {
        int mines = 0;
        std::uniform_int_distribution x_dis (0, number_of_columns - 1);
        std::uniform_int_distribution y_dis (0, number_of_rows - 1);
        while (mines < mines_count) {
            const int x = x_dis(generator_);
            const int y = y_dis(generator_);
            if (cellGrid_[x][y]->getType() == CellType::Mine) continue;
            cellGrid_[x][y]->setType(CellType::Mine);
            mines++;
        }
    }

    Board::Board(sf::RenderWindow *window) {
        initialize(window);
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
