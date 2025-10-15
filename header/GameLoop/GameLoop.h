#pragma once
#include "../GameWindow/GameWindowManager.h"



namespace UI {
    class SplashScreenManager;
    class MainMenuManager;
}

namespace Event {
    class EventPollingManager;
}

namespace Gameplay {
    class GameplayManager;

}

enum class GameState
{
    SPLASH_SCREEN,
    MAIN_MENU,
    GAMEPLAY,
    EXIT
};

class GameLoop {
private:
    GameWindow::GameWindowManager* window_manager;
    Event::EventPollingManager* event_manager;
    UI::SplashScreenManager* splash_screen_manager;
    UI::MainMenuManager* main_menu_manager;
    Gameplay::GameplayManager* game_play_manager;

    sf::RenderWindow* game_window;

    static GameState current_state;

    void initialize();
    void update();
    void render();

public:
    GameLoop();
    ~GameLoop();

    void run();
    static void setGameState(GameState state_to_set);
};