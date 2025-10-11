//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#ifndef MINESWEEPER_SFML_GAMEPLAYMANAGER_H
#define MINESWEEPER_SFML_GAMEPLAYMANAGER_H
#include <SFML/Graphics.hpp>


namespace Event {
    class EventPollingManager;
}

namespace Gameplay {
    class Board;
    class GameplayManager {
        Board* board = nullptr;
        sf::RenderWindow* game_window = nullptr;
        sf::Texture backgroundTexture_;
        sf::Sprite backgroundSprite_;
        void initialize();
        void initializeVariables();
    public:
        GameplayManager(sf::RenderWindow* window);
        ~GameplayManager() = default;
        void update(Event::EventPollingManager &event_manager, const sf::RenderWindow& window);
        void render(sf::RenderWindow& window);
    };
} // Gameplay

#endif //MINESWEEPER_SFML_GAMEPLAYMANAGER_H