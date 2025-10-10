//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#include "../../header/Gameplay/Board.h"

#include <iostream>

#include "../../header/Assets/AssetManager.h"

namespace Gameplay {
    void Board::initializeBoardImage(const sf::RenderWindow* window) {
        if (!texture_.loadFromFile(Asset::AssetManager::getTexture(Asset::TextureType::Board))) {
            throw std::runtime_error("Failed to load board image!");
        }
        sprite_.setTexture(texture_);
        sprite_.setPosition(boardPosition, 0);
        sprite_.setScale(boardWidth / texture_.getSize().x,boardHeight / texture_.getSize().y);
    }

    void Board::initialize(sf::RenderWindow* window) {
        initializeBoardImage(window);
        createBoard();
    }

    void Board::createBoard() {
        cell_ = new Cell(83,83,sf::Vector2i(0,0));
    }

    Board::Board(sf::RenderWindow* window) {
        initialize(window);
    }


    void Board::render(sf::RenderWindow &window) const {
        window.draw(sprite_);
        cell_->render(window);
    }
} // Gameplay