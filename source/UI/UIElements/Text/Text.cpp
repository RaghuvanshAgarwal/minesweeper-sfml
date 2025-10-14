//
// Created by Raghuvansh Agarwal on 13/10/25.
//

#include "../../../../header/UI/UIElements/Text/Text.h"

#include <iostream>
#include <ostream>

#include "../../../../header/Assets/AssetManager.h"

namespace UIElements {
    void Text::initializeText(Asset::FontType p_font_type) {
        if (!font_.loadFromFile(Asset::AssetManager::getFont(p_font_type))) {
            std::cerr << "Failed to load font." << std::endl;
        }
        text_.setFont(font_);
        text_.setCharacterSize(font_size_);
        text_.setFillColor(color_);
        text_.setPosition(position_);
    }

    Text::Text(const std::string& p_initial_text, sf::Vector2f p_position, unsigned int p_font_size, sf::Color p_color, Asset::FontType p_font_type) {
        position_ = p_position;
        font_size_ = p_font_size;
        color_ = p_color;
        text_.setString(p_initial_text);
        initializeText(p_font_type);
    }

    void Text::setText(const std::string& p_text) {
        text_.setString(p_text);
    }

    void Text::render(sf::RenderWindow &window) const {
        window.draw(text_);
    }
} // UIElements