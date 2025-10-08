//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#ifndef MINESWEEPER_SFML_GAMEPLAYMANAGER_H
#define MINESWEEPER_SFML_GAMEPLAYMANAGER_H
#include <SFML/Graphics.hpp>


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
        void render(sf::RenderWindow& window);
    };
} // Gameplay

#endif //MINESWEEPER_SFML_GAMEPLAYMANAGER_H