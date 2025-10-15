//
// Created by Raghuvansh Agarwal on 08/10/25.
//

#ifndef MINESWEEPER_SFML_GAMEPLAYMANAGER_H
#define MINESWEEPER_SFML_GAMEPLAYMANAGER_H
#include <SFML/Graphics.hpp>


namespace UI {
    class GameplayUI;
}

namespace Event {
    class EventPollingManager;
}

namespace Gameplay {

    enum class GameResult {
        NONE,
        WON,
        LOST,
    };

    class Board;
    class GameplayManager {

        const float max_level_duration = 150.f;
        const float game_over_time = 11.f;

        Board* board_ = nullptr;
        UI::GameplayUI* gui_ = nullptr;
        sf::RenderWindow* game_window = nullptr;
        sf::Texture backgroundTexture_;
        sf::Sprite backgroundSprite_;


        float remaining_time_{};
        GameResult game_result_ = GameResult::NONE;

        bool hasGameEnded() const;
        void initialize();
        void initializeVariables();
        void updateRemainingTime();
        void processTimeOver();
        void handleGameplay(Event::EventPollingManager &event_manager, const sf::RenderWindow &window);
        void gameWon();
        void gameLost();
    public:
        explicit GameplayManager(sf::RenderWindow* window);
        ~GameplayManager() = default;
        float getRemainingTime() const;
        void setGameEnded(GameResult p_result);
        void checkGameWin();
        void processGameResult();
        void restartGame();
        void update(Event::EventPollingManager &event_manager, const sf::RenderWindow& window);
        void render(sf::RenderWindow& window);
    };
} // Gameplay

#endif //MINESWEEPER_SFML_GAMEPLAYMANAGER_H