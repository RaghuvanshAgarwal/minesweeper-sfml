#include "../../header/GameLoop/GameLoop.h"
#include "../../header/Time/TimeManager.h"
#include "../../header/Sound/SoundManager.h"
#include "../../header/Gameplay/GameplayManager.h"
#include "../../header/GameWindow/GameWindowManager.h"
#include "../../header/Event/EventPollingManager.h"
#include "../../header/UI/SplashScreen/SplashScreenManager.h"

GameState GameLoop::current_state = GameState::SPLASH_SCREEN;

GameLoop::GameLoop() { initialize(); }

void GameLoop::initialize() {
    // Create Managers:
    window_manager = new GameWindow::GameWindowManager();
    game_window = window_manager->getGameWindow();
    event_manager = new Event::EventPollingManager(game_window);
    game_play_manager = new Gameplay::GameplayManager(game_window);
    splash_screen_manager = new UI::SplashScreenManager(game_window);

    // Initialize Sounds:
    Sound::SoundManager::Initialize();
    Sound::SoundManager::PlayBackgroundMusic();

    // Initialize Time:
    Time::TimeManager::initialize();
}

GameLoop::~GameLoop() {
    delete window_manager;
    delete event_manager;
    delete splash_screen_manager;
    delete game_play_manager;
}

void GameLoop::update() {
    Time::TimeManager::update();
    event_manager->update();
    window_manager->update();

    switch (current_state) {
        case GameState::SPLASH_SCREEN:
            splash_screen_manager->update();
            break;
        case GameState::MAIN_MENU:
            break;
        case GameState::GAMEPLAY:
            game_play_manager->update(*event_manager, *game_window);
            break;
        case GameState::EXIT:
            game_window->close();
            break;
    }
}

void GameLoop::render() {
    game_window->clear();
    window_manager->render();

    switch (current_state) {
        case GameState::SPLASH_SCREEN:
            splash_screen_manager->render();
            break;
        case GameState::MAIN_MENU:
            break;
        case GameState::GAMEPLAY:
            game_play_manager->render(*game_window);
            break;
        default:
            throw std::runtime_error("Invalid state");
    }

    game_window->display();
}

void GameLoop::run() {
    while (window_manager->isGameWindowOpen()) {
        event_manager->processEvents();
        update();
        render();
    }
}

void GameLoop::setGameState(GameState state_to_set) { GameLoop::current_state = state_to_set; }
