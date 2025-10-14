//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#include "../../header/Gameplay/GameplayManager.h"

#include <iostream>

#include "../../header/Assets/AssetManager.h"
#include "../../header/Gameplay/Board.h"
#include "../../header/Sound/SoundManager.h"
#include "../../header/Time/TimeManager.h"
#include "../../header/UI/GameplayUI/GameplayUI.h"

namespace Gameplay {
    void GameplayManager::initialize() {
        initializeVariables();
    }

    void GameplayManager::initializeVariables() {
        board_ = new Board(game_window, this);
        remaining_time_ = max_level_duration;
        gui_ = new UI::GameplayUI(board_, this);
        gui_->registerResetButtonClicked([this]() {
            Sound::SoundManager::PlaySound(Sound::SoundType::BUTTON_CLICK);
            board_->initialize(game_window, this);
            game_result_ = GameResult::NONE;
            remaining_time_ = max_level_duration;
        });
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
            board_->setBoardState(BoardState::Completed);
        }
    }

    void GameplayManager::handleGameplay(Event::EventPollingManager &event_manager, const sf::RenderWindow &window) {
        updateRemainingTime();
        board_->update(event_manager, window);
        checkGameWin();

    }

    void GameplayManager::gameWon() {
        Sound::SoundManager::PlaySound(Sound::SoundType::GAME_WON);
        board_->flagAllMines();
        board_->setBoardState(BoardState::Completed);
    }

    void GameplayManager::gameLost() {
        Sound::SoundManager::PlaySound(Sound::SoundType::EXPLOSION);
        board_->setBoardState(BoardState::Completed);
        board_->revealAllCells();
    }

    void GameplayManager::checkGameWin() {
        if (board_->areAllCellsOpen()) {
            game_result_ = GameResult::WON;
        }
    }

    void GameplayManager::processGameResult() {
        switch (game_result_) {
            case GameResult::LOST:
                gameLost();
                break;
            case GameResult::WON:
                gameWon();
                break;
            default:
                break;
        }

    }

    bool GameplayManager::hasGameEnded() const {
        return game_result_ != GameResult::NONE;
    }

    GameplayManager::GameplayManager(sf::RenderWindow *window) {
        game_window = window;
        initialize();
    }

    float GameplayManager::getRemainingTime() const {
        return remaining_time_;
    }

    void GameplayManager::setGameEnded(GameResult p_result) {
        game_result_ = p_result;
    }

    void GameplayManager::update(Event::EventPollingManager &event_manager, const sf::RenderWindow &window) {
        if (!hasGameEnded())
            handleGameplay(event_manager, window);
        else if (board_->getBoardState() != BoardState::Completed)
            processGameResult();

        gui_->update(event_manager, window);
    }

    void GameplayManager::render(sf::RenderWindow &window) {
        window.draw(backgroundSprite_);
        board_->render(window);
        gui_->render(window);
    }
} // Gameplay
