//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#include "../../header/Gameplay/GameplayManager.h"
#include "../../header/Assets/AssetManager.h"
#include "../../header/Gameplay/Board.h"
#include "../../header/Time/TimeManager.h"

namespace Gameplay {
    void GameplayManager::initialize() {
        initializeVariables();
    }

    void GameplayManager::initializeVariables() {
        board_ = new Board(game_window, this);
        remaining_time_ = max_level_duration;
        if (!backgroundTexture_.loadFromFile(Asset::AssetManager::getTexture(Asset::TextureType::MinesweeperBackground))) {
            throw std::runtime_error("Failed to load background texture");
        }
        backgroundSprite_.setTexture(backgroundTexture_);
        backgroundSprite_.setScale(
            static_cast<float>(game_window->getSize().x) / backgroundTexture_.getSize().x,
            static_cast<float>(game_window->getSize().y) / backgroundTexture_.getSize().y);
        backgroundSprite_.setColor({255, 255, 255, 150});
    }

    void GameplayManager::updateRemainingTime() {
        remaining_time_ -= Time::TimeManager::getDeltaTime();
        processTimeOver();
    }

    void GameplayManager::processTimeOver() {
        if (remaining_time_ <= 0) {
            setGameEnded(GameResult::LOST);
            remaining_time_ = 0;
            board_->revealAllCells();
        }
    }

    void GameplayManager::handleGameplay(Event::EventPollingManager &event_manager, const sf::RenderWindow &window) {
        updateRemainingTime();
        board_->update(event_manager, window);
    }

    bool GameplayManager::hasGameEnded() const {
        return game_result_ != GameResult::NONE;
    }

    GameplayManager::GameplayManager(sf::RenderWindow *window) {
        game_window = window;
        initialize();
    }

    void GameplayManager::setGameEnded(GameResult p_result) {
        game_result_ = p_result;
    }

    void GameplayManager::update(Event::EventPollingManager &event_manager, const sf::RenderWindow &window) {
        if (!hasGameEnded())
            handleGameplay(event_manager, window);
    }

    void GameplayManager::render(sf::RenderWindow &window) {
        window.draw(backgroundSprite_);
        board_->render(window);
    }
} // Gameplay
