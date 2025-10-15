//
// Created by Raghuvansh Agarwal on 15/10/25.
//

#ifndef MINESWEEPER_SFML_MAINMENUMANAGER_H
#define MINESWEEPER_SFML_MAINMENUMANAGER_H
#include "SFML/Graphics.hpp"

namespace Event {
    class EventPollingManager;
}

namespace UIElements {
    class Button;
}

namespace UI {
    class MainMenuManager {
        const sf::Vector2f button_size_ = sf::Vector2f(192.f, 92.3f);
        sf::Texture logo_texture_;
        sf::Texture background_texture_;
        sf::Sprite background_;
        sf::Sprite logo_;
        UIElements::Button* play_button_ = nullptr;
        UIElements::Button* quit_button_ = nullptr;

        void createButtons(const sf::RenderWindow& window);
        void createBackground(const sf::RenderWindow& window);
        void createLogo(const sf::RenderWindow& window);

    public:
        explicit MainMenuManager(const sf::RenderWindow& window);
        ~MainMenuManager();
        void update(Event::EventPollingManager& p_event_manager, const sf::RenderWindow& p_window);
        void render(sf::RenderWindow& p_window) const;
    };
} // UI

#endif //MINESWEEPER_SFML_MAINMENUMANAGER_H