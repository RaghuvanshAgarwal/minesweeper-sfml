//
// Created by Raghuvansh Agarwal on 15/10/25.
//

#include "../../../header/UI/MainMenu/MainMenuManager.h"

#include <iostream>

#include "../../../header/Assets/AssetManager.h"
#include "../../../header/GameLoop/GameLoop.h"
#include "../../../header/UI/UIElements/Button/Button.h"

namespace UI {
    void MainMenuManager::createButtons(const sf::RenderWindow& window) {
        const float window_width = static_cast<float>(window.getSize().x);
        const float window_height = static_cast<float>(window.getSize().y);
        const float xPos = (window_width-button_size_.x)*0.5f;
        const auto play_button_pos = sf::Vector2f(xPos, (window_height)*0.6f);
        const auto quit_button_pos = sf::Vector2f(xPos, window_height*0.6f + button_size_.y + 25);

        play_button_ = new UIElements::Button(Asset::AssetManager::getTexture(Asset::TextureType::PlayButton),play_button_pos, button_size_);
        quit_button_ = new UIElements::Button(Asset::AssetManager::getTexture(Asset::TextureType::QuitButton),quit_button_pos, button_size_);

        play_button_->registerCallback([this](UIElements::MouseButtonType p_button) {
            GameLoop::setGameState(GameState::GAMEPLAY);
        });

        quit_button_->registerCallback([this](UIElements::MouseButtonType p_button) {
            GameLoop::setGameState(GameState::EXIT);
        });
    }

    void MainMenuManager::createBackground(const sf::RenderWindow& window) {
        if (!background_texture_.loadFromFile(Asset::AssetManager::getTexture(Asset::TextureType::MinesweeperBackground))) {
            std::cerr << "Error loading background texture" << std::endl;
        }
        const float window_width = static_cast<float>(window.getSize().x);
        const float window_height = static_cast<float>(window.getSize().y);
        background_.setTexture(background_texture_);
        background_.setScale(static_cast<float>(background_texture_.getSize().x)/ window_width, static_cast<float>(background_texture_.getSize().y)/ window_height);
        background_.setColor({255, 255, 255, 150});
    }

    void MainMenuManager::createLogo(const sf::RenderWindow& window) {
        if (!logo_texture_.loadFromFile(Asset::AssetManager::getTexture(Asset::TextureType::Logo))) {
            std::cerr << "Error loading logo texture" << std::endl;
        }
        logo_.setTexture(logo_texture_);
        const float window_width = static_cast<float>(window.getSize().x);
        const float window_height = static_cast<float>(window.getSize().y);
        const sf::Vector2f pos = {(window_width-logo_texture_.getSize().x) * 0.5f,window_height * 0.3f};
        logo_.setPosition(pos);
    }

    MainMenuManager::MainMenuManager(const sf::RenderWindow& window) {
        createBackground(window);
        createLogo(window);
        createButtons(window);
    }

    MainMenuManager::~MainMenuManager() {
        delete play_button_;
        delete quit_button_;
    }

    void MainMenuManager::update(Event::EventPollingManager &p_event_manager, const sf::RenderWindow &p_window) {
        play_button_->handleButtonInteractions(p_event_manager, p_window);
        quit_button_->handleButtonInteractions(p_event_manager, p_window);
    }

    void MainMenuManager::render(sf::RenderWindow &p_window) const {
        p_window.draw(background_);
        p_window.draw(logo_);
        play_button_->render(p_window);
        quit_button_->render(p_window);
    }
} // UI