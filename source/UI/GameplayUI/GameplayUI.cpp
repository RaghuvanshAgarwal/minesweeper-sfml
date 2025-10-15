//
// Created by Raghuvansh Agarwal on 13/10/25.
//

#include <utility>

#include "../../../header/UI/GameplayUI/GameplayUI.h"

#include <iostream>

#include "../../../header/Gameplay/Board.h"
#include "../../../header/Gameplay/GameplayManager.h"
#include "../../../header/UI/UIElements/Button/Button.h"
#include "../../../header/UI/UIElements/Text/Text.h"

namespace UI {
    void GameplayUI::updateFlagCounter() const {
        int counter = board_->getFlagCount();
        std::string counterString = "";
        if (counter < 10) {
            counterString = "00"+ std::to_string(counter);
        }
        else if (counter < 100) {
            counterString = "0"+std::to_string(counter);
        }
        else {
            counterString = std::to_string(counter);
        }
        flag_count_->setText(counterString);
    }

    void GameplayUI::updateRemainingTimer() {
        const int remaining_time = static_cast<int>(std::floor(manager_->getRemainingTime()));
        if (remaining_time < 10) {
            remaining_timer_->setText("00"+std::to_string(remaining_time));
        }
        else if (remaining_time < 100) {
            remaining_timer_->setText("0"+std::to_string(remaining_time));
        }else {
            remaining_timer_->setText(std::to_string(remaining_time));
        }
    }

    void GameplayUI::createFlagCountBackground() {
        flag_count_sprite_.setTexture(text_background_texture_);
        flag_count_sprite_.setPosition(flag_sprite_position_);
        flag_count_sprite_.setScale(
            text_background_sprite_size.x/static_cast<float>(text_background_texture_.getSize().x) * 12,
            text_background_sprite_size.y/static_cast<float>(text_background_texture_.getSize().y)
        );
        flag_count_sprite_.setTextureRect({1280,0,128,128});
    }

    void GameplayUI::createRemainingTimeBackground() {
        remaining_timer_sprite_.setTexture(text_background_texture_);
        remaining_timer_sprite_.setPosition(remaining_time_sprite_position_);
        remaining_timer_sprite_.setScale(
            text_background_sprite_size.x/static_cast<float>(text_background_texture_.getSize().x) * 12,
            text_background_sprite_size.y/static_cast<float>(text_background_texture_.getSize().y)
        );
        remaining_timer_sprite_.setTextureRect({1280,0,128,128});
    }

    GameplayUI::GameplayUI(Gameplay::Board *p_board, Gameplay::GameplayManager *p_manager) {
        manager_ = p_manager;
        board_ = p_board;
        flag_count_ = new UIElements::Text("000", flag_count_position_,font_size_,color_, font_type_);
        remaining_timer_ = new UIElements::Text("000", remaining_time_position_,font_size_,color_, font_type_);
        reset_button_ = new UIElements::Button(Asset::AssetManager::getTexture(Asset::TextureType::RestartButton),reset_button_position_,reset_button_size_);
        reset_button_->registerCallback([this](UIElements::MouseButtonType p_button) {
            if (on_reset_btn_clicked_) on_reset_btn_clicked_(p_button);
        });
        if (!text_background_texture_.loadFromFile(Asset::AssetManager::getTexture(Asset::TextureType::Cell))) {
            std::cerr << "Failed to load background texture" << std::endl;
            return;
        }
        createFlagCountBackground();
        createRemainingTimeBackground();
    }

    GameplayUI::~GameplayUI() {
        delete flag_count_;
        delete remaining_timer_;
        delete reset_button_;
    }

    void GameplayUI::registerResetButtonClicked(std::function<void(UIElements::MouseButtonType)> p_callback) {
        on_reset_btn_clicked_ = p_callback;
    }

    void GameplayUI::update(Event::EventPollingManager &event_manager, const sf::RenderWindow &window) {
        reset_button_->handleButtonInteractions(event_manager, window);
        updateFlagCounter();
        updateRemainingTimer();
    }

    void GameplayUI::render(sf::RenderWindow &window) const {
        window.draw(flag_count_sprite_);
        window.draw(remaining_timer_sprite_);
        flag_count_->render(window);
        remaining_timer_->render(window);
        reset_button_->render(window);
    }
} // UI