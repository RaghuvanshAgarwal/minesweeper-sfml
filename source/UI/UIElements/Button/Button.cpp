//
// Created by Raghuvansh Agarwal on 10/10/25.
//

#include "../../../../header/UI/UIElements/Button/Button.h"
#include "../../../../header/Event/EventPollingManager.h"

#include <iostream>
#include <utility>

namespace UIElements {
    void Button::initialize(const std::string &p_texture_path, const sf::Vector2f &p_position, const sf::Vector2f &p_size) {
        if (!texture_.loadFromFile(p_texture_path)) {
            throw std::runtime_error("Failed to load texture: " + p_texture_path);
        }
        sprite_.setTexture(texture_);
        sprite_.setPosition(p_position);
        sprite_.setScale(p_size.x / texture_.getSize().x, p_size.y / texture_.getSize().y);
    }

    bool Button::isMouseOnSprite(const Event::EventPollingManager &p_polling_manager, const sf::RenderWindow &p_window) {
        sf::Vector2i mousePos = p_polling_manager.getMousePosition();
        return sprite_.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }

    void Button::handleButtonInteractions(Event::EventPollingManager &event_manager, const sf::RenderWindow &window) {
        if (event_manager.pressedLeftMouseButton() && isMouseOnSprite(event_manager,window)) {
            if (callback_) callback_(MouseButtonType::LeftMouseButton);
        }
        else if (event_manager.pressedRightMouseButton() && isMouseOnSprite(event_manager,window)) {
            if (callback_) callback_(MouseButtonType::RightMouseButton);
        }
    }

    Button::Button(const std::string &p_texture_path, const sf::Vector2f &p_position, const sf::Vector2f &p_size) {
        initialize(p_texture_path, p_position, p_size);
    }

    void Button::setTextureRect(const sf::IntRect &p_texture_rect) {
        sprite_.setTextureRect(p_texture_rect);
    }

    void Button::registerCallback(std::function<void(MouseButtonType)> p_callback) {
        callback_ = std::move(p_callback);
    }

    void Button::render(sf::RenderWindow &window) const {
        window.draw(sprite_);
    }
} // UIElements