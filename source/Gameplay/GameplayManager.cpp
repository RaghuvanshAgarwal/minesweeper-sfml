//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#include "../../header/Gameplay/GameplayManager.h"
#include "../../header/Assets/AssetManager.h"
#include "../../header/Gameplay/Board.h"

namespace Gameplay {
    void GameplayManager::initialize() {
        initializeVariables();
    }

    void GameplayManager::initializeVariables() {
        board = new Board(game_window);
        if (!backgroundTexture_.loadFromFile(Asset::AssetManager::getTexture(Asset::TextureType::MinesweeperBackground))) {
            throw std::runtime_error("Failed to load background texture");
        }
        backgroundSprite_.setTexture(backgroundTexture_);
        backgroundSprite_.setScale(
            static_cast<float>(game_window->getSize().x)/backgroundTexture_.getSize().x,
            static_cast<float>(game_window->getSize().y)/backgroundTexture_.getSize().y);
        backgroundSprite_.setColor({255,255,255,150});
    }

    GameplayManager::GameplayManager(sf::RenderWindow* window) {
        game_window = window;
        initialize();
    }

    void GameplayManager::update(Event::EventPollingManager &event_manager, const sf::RenderWindow &window) {
        board->update(event_manager, window);
    }

    void GameplayManager::render(sf::RenderWindow &window) {
        window.draw(backgroundSprite_);
        board->render(window);
    }
} // Gameplay