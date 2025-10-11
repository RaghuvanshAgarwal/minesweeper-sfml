//
// Created by Raghuvansh Agarwal on 10/10/25.
//

#ifndef MINESWEEPER_SFML_BUTTON_H
#define MINESWEEPER_SFML_BUTTON_H
#include "SFML/Graphics.hpp"

namespace Event {
    class EventPollingManager;
}

namespace UIElements {

    enum class MouseButtonType {
        LeftMouseButton,
        RightMouseButton,
    };

    class Button {
        sf::Sprite sprite_;
        sf::Texture texture_;
        std::function<void(MouseButtonType)> callback_ = nullptr;
        void initialize(const std::string& p_texture_path, const sf::Vector2f& p_position, const sf::Vector2f& p_size);
        bool isMouseOnSprite(const Event::EventPollingManager& p_polling_manager, const sf::RenderWindow& p_window);

    public:
        Button(const std::string& p_texture_path, const sf::Vector2f& p_position, const sf::Vector2f& p_size);
        void handleButtonInteractions(Event::EventPollingManager& event_manager, const sf::RenderWindow& window);
        void setTextureRect(const sf::IntRect& p_texture_rect);
        void registerCallback(std::function<void(MouseButtonType)> p_callback);
        void render(sf::RenderWindow& window) const;
    };
} // UIElements

#endif //MINESWEEPER_SFML_BUTTON_H