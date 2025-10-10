//
// Created by Raghuvansh Agarwal on 10/10/25.
//

#include "../../../../header/UI/UIElements/Button/Button.h"

namespace UIElements {
    void Button::initialize(const std::string &p_texture_path, const sf::Vector2f &p_position, const sf::Vector2f &p_size) {
        if (!texture_.loadFromFile(p_texture_path)) {
            throw std::runtime_error("Failed to load texture: " + p_texture_path);
        }
        sprite_.setTexture(texture_);
        sprite_.setPosition(p_position);
        sprite_.setScale(p_size.x / texture_.getSize().x, p_size.y / texture_.getSize().y);
    }

    Button::Button(const std::string &p_texture_path, const sf::Vector2f &p_position, const sf::Vector2f &p_size) {
        initialize(p_texture_path, p_position, p_size);
    }

    void Button::render(sf::RenderWindow &window) const {
        window.draw(sprite_);
    }
} // UIElements