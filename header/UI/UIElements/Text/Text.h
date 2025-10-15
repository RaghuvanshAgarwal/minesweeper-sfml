//
// Created by Raghuvansh Agarwal on 13/10/25.
//

#ifndef MINESWEEPER_SFML_TEXT_H
#define MINESWEEPER_SFML_TEXT_H
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"

namespace Asset {
    enum class FontType;
}

namespace UIElements {
    class Text {
        sf::Font font_;
        sf::Text text_;
        sf::Vector2f position_;
        unsigned int font_size_;
        sf::Color color_;

        void initializeText(Asset::FontType p_font_type);

    public:
        Text(const std::string& p_initial_text, sf::Vector2f p_position, unsigned int p_font_size, sf::Color p_color, Asset::FontType p_font_type);
        void setText(const std::string& p_text);

        void render(sf::RenderWindow& window) const;
    };
} // UIElements

#endif //MINESWEEPER_SFML_TEXT_H