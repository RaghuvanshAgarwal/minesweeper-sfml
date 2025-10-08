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
        const float scale = static_cast<float>(window->getSize().y) / static_cast<float>(texture_.getSize().y);
        sprite_.setScale(scale, scale);
        const float posX = (static_cast<float>(window->getSize().x) - sprite_.getGlobalBounds().width) / 2.0f;
        sprite_.setPosition(posX,0);
    }

    void Board::initialize(sf::RenderWindow* window) {
        initializeBoardImage(window);
    }

    Board::Board(sf::RenderWindow* window) {
        initialize(window);
    }


    void Board::render(sf::RenderWindow &window) {
        window.draw(sprite_);
    }
} // Gameplay