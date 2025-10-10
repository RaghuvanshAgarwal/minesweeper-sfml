//
// Created by Raghuvansh Agarwal on 10/10/25.
//

#ifndef MINESWEEPER_SFML_BUTTON_H
#define MINESWEEPER_SFML_BUTTON_H
#include "SFML/Graphics.hpp"

namespace UIElements {

    enum class MouseButtonType {
        LeftMouseButton,
        RightMouseButton,
    };

    class Button {
        sf::Sprite sprite_;
        sf::Texture texture_;
        void initialize(const std::string& p_texture_path, const sf::Vector2f& p_position, const sf::Vector2f& p_size);

    public:
        Button(const std::string& p_texture_path, const sf::Vector2f& p_position, const sf::Vector2f& p_size);
        void setTextureRect(const sf::IntRect& p_texture_rect);
        void render(sf::RenderWindow& window) const;
    };
} // UIElements

#endif //MINESWEEPER_SFML_BUTTON_H