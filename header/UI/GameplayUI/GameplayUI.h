//
// Created by Raghuvansh Agarwal on 13/10/25.
//

#ifndef MINESWEEPER_SFML_GAMEPLAYUI_H
#define MINESWEEPER_SFML_GAMEPLAYUI_H
#include <functional>

#include "../../Assets/AssetManager.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"


namespace Event {
    class EventPollingManager;
}

namespace sf {
    class RenderWindow;
}

namespace UIElements {
    class Button;
    class Text;
    enum class MouseButtonType;
}

namespace Gameplay {
    class Board;
    class GameplayManager;
}

namespace UI {
    class GameplayUI {

        const Asset::FontType font_type_ = Asset::FontType::BubbleBobble;
        const sf::Color color_ = sf::Color::Red;
        const int font_size_ = 80;
        const sf::Vector2f text_background_sprite_size = sf::Vector2f(150, 150);

        const sf::Vector2f flag_count_position_ = sf::Vector2f(668, 85);
        const sf::Vector2f flag_sprite_position_ = sf::Vector2f(650, 65);

        const sf::Vector2f remaining_time_position_ = sf::Vector2f(1148, 85);
        const sf::Vector2f remaining_time_sprite_position_ = sf::Vector2f(1125, 65);

        const sf::Vector2f reset_button_position_ = sf::Vector2f(920, 100);
        const sf::Vector2f reset_button_size_ = sf::Vector2f(80, 80);


        UIElements::Text* flag_count_ = nullptr;
        UIElements::Text* remaining_timer_ = nullptr;
        UIElements::Button* reset_button_ = nullptr;
        Gameplay::Board* board_ = nullptr;
        Gameplay::GameplayManager* manager_ = nullptr;
        sf::Texture text_background_texture_;
        sf::Sprite flag_count_sprite_;
        sf::Sprite remaining_timer_sprite_;

        std::function<void(UIElements::MouseButtonType)> on_reset_btn_clicked_ = nullptr;
        void updateFlagCounter() const;
        void updateRemainingTimer();

        void createFlagCountBackground();
        void createRemainingTimeBackground();

    public:
        GameplayUI(Gameplay::Board* p_board, Gameplay::GameplayManager* p_manager);
        ~GameplayUI();
        void registerResetButtonClicked(std::function<void(UIElements::MouseButtonType)> p_callback);
        void update(Event::EventPollingManager &event_manager, const sf::RenderWindow &window);
        void render(sf::RenderWindow& window) const;
    };
} // UI

#endif //MINESWEEPER_SFML_GAMEPLAYUI_H